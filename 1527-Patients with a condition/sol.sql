# Write your MySQL query statement below


select patient_id , patient_name , conditions
FROM Patients
Where conditions LIKE 'DIAB1%' or   conditions LIKE '% DIAB1%'
