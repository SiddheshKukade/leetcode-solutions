# Write your MySQL query statement below

SELECT user_id ,(count(DISTINCT follower_id)) AS followers_count
# SELECT user_id, (count(distinct follower_id)) as followers_count 
FROM Followers
GROUP BY user_id
