SELECT DISTINCT num AS ConsecutiveNums
FROM Logs l1
WHERE 
    (SELECT num FROM Logs WHERE id = l1.id - 1) = l1.num AND
    (SELECT num FROM Logs WHERE id = l1.id + 1) = l1.num;
