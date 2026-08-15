# Write your MySQL query statement below
select s.user_id, ROUND(COALESCE((SUM(action = 'confirmed')/Count(*)),0),2) as confirmation_rate
from Signups s
LEFT JOIN Confirmations c
on s.user_id = c.user_id
GROUP by s.user_id;