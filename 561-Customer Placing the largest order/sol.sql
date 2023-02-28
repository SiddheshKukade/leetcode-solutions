# # Write your MySQL query statement below

# SELECT DISTINCT COUNT(customer_number) as customer_number from Orders;
# # Write your MySQL query statement below
# with tb as (select customer_number, count(order_number) as maxi from Orders group by customer_number)
# select customer_numbear from tb where maxi=(select max(maxi) from tb)

SELECT customer_number 
From Orders
Group BY customer_number
ORDER BY COUNT(DISTINCT order_number) DESC
LIMIT 1
