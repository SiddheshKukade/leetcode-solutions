# Write your MySQL query statement below
WITH cte AS
(SELECT *, DENSE_RANK() OVER(ORDER BY salary DESC)
AS r
 FROM Employee)

SELECT IFNULL((Select salary from cte where r=2 LIMit 1 ), null) as SecondHighestSalary
# IFNULL(expression ,value-returned-if-the-expression-is-null)
