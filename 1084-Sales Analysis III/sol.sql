# Write your MySQL query statement below

Select p.product_id ,p.product_name
From  Product p JOIN Sales s 

ON s.product_id = p.product_id 

GROUP BY product_id Having min(sale_date) >= '2019-01-01'
AND  max(sale_date) <= '2019-03-31'
