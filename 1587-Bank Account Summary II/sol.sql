# Write your MySQL query statement below

Select u.name , SUM(amount) AS balance
FROM Transactions t
INNER JOIN Users u
ON t.account = u.account
GROUP BY u.name 
HAVING SUM(amount) > 10000;
