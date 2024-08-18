# Write your MySQL query statement below
-- select product_id,new_price from products where change_date<='2019-08-16' group by product_id, change_date
-- order by change_date desc

-- SELECT product_id,price 
-- FROM
-- (SELECT product_id,MAX(new_price) AS price, change_date, 
-- CASE WHEN change_date<'2019-08-16' THEN MAX(new_price) ELSE 10 END AS X
-- FROM Products GROUP BY product_id ) AS DERIVED_TABLE;

SELECT p1.product_id,
       COALESCE(p2.new_price, 10) AS price
FROM (
    SELECT DISTINCT product_id
    FROM Products
) p1
LEFT JOIN Products p2
ON p1.product_id = p2.product_id
   AND p2.change_date = (
       SELECT MAX(change_date)
       FROM Products
       WHERE product_id = p1.product_id
         AND change_date <= '2019-08-16'
   )
GROUP BY p1.product_id;
