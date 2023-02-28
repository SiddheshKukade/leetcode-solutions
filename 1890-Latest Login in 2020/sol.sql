# Write your MySQL query statement below

SELECT DISTINCT user_id, FIRST_VALUE(time_stamp) 
OVER (PARTITION BY user_id ORDER BY time_stamp DESC) AS 
 last_stamp 
FROM Logins
WHERE Year(time_stamp) = '2020' 
# Remove those rows which are not from 2020.
# Now getting latest login
