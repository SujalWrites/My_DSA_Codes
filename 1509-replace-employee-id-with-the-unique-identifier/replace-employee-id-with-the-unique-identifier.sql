# Write your MySQL query statement below
select e1.unique_id as unique_id, e.name from employees e left join EmployeeUNI e1 on e.id=e1.id ;  