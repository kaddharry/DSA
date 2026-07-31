# Write your MySQL query statement below
select w.id
from Weather w
Join Weather t
ON w.recordDate = DATE_ADD(t.recordDate, Interval 1 day)
where w.temperature > t.temperature;