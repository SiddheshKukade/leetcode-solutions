# Write your MySQL query statement below


SELECt actor_id , director_id
from ActorDirector 
GROUP BY actor_id , director_id 
HAVING COUNT(timestamp) >=3
