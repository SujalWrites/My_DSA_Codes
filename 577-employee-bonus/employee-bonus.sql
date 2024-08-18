# Write your MySQL query statement below
select  e.name,b.bonus from employee e left join bonus b on e.empId=b.empId  group by e.empId having b.bonus<1000 or b.bonus is null