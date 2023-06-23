# Write your MySQL query statement below

SELECT e1.name as Employee 
from Employee e1 inner join Employee e2 
ON e1.id = e2.managerID
where e1.salary < e2.salary
