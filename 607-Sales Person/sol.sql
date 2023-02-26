# SELECT
#     s.name
# FROM
#     salesperson s
# WHERE
#     s.sales_id NOT IN (SELECT
#             o.sales_id
#         FROM
#             orders o
#                 LEFT JOIN
#             company c ON o.com_id = c.com_id
#         WHERE
#             c.name = 'RED')
# ;
WITH cte AS
(Select sales_id FROM Orders o
LEFT JOIN Company c
On  o.com_id = c.com_id
WHERE c.name LIKE 'RED')

SELECT name
FROM SalesPerson
WHERE sales_id  NOT IN( SELECT DISTINCT sales_id FROM cte)
