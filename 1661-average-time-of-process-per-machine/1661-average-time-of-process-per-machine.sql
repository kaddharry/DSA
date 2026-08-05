# Write your MySQL query statement below
select m.machine_id, ROUND(AVG(p.timestamp - m.timestamp),3) as processing_time
from Activity m
join Activity p
ON
(m.machine_id = p.machine_id 
AND m.process_id = p.process_id 
AND m.activity_type = 'start' 
AND p.activity_type = 'end'
)
group by m.machine_id;