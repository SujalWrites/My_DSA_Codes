# Write your MySQL query statement below
select patient_id , patient_name ,conditions
from patients
group by patient_id
having  conditions like "DIAB1%" OR conditions like "% DIAB1%"