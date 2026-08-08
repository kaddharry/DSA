# Write your MySQL query statement below
select ROUND(count(*)/(select count(distinct player_id) from Activity),2) as fraction
from Activity
where (player_id,event_date) IN (select player_id, MIN(event_date) + INTERVAL 1 DAY
                                from Activity
                                group by player_id);