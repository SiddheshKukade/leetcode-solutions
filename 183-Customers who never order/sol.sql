# Write your MySQL query statement below
# Customers who don't order
SELECT name as Customers from Customers c
LEFT JOIN Orders o
ON c.id = o.customerId
where o.customerId is  null
