# Write your MySQL query statement below
select a.visited_on,
        SUM(b.amount) as amount,
        ROUND(SUM(b.amount)/7,2) as average_amount
from (select Distinct visited_on from Customer) a
JOIN Customer b
ON DATEDIFF(a.visited_on, b.visited_on) BETWEEN 0 AND 6
where a.visited_on >= (select MIN(visited_on) from Customer) + INTERVAL 6 DAY
group by a.visited_on
order by a.visited_on