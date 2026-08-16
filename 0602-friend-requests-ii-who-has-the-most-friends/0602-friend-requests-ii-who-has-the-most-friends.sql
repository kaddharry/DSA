# Write your MySQL query statement below
select id, COUNT(*) as num
from (
    select requester_id as id
    from RequestAccepted

    UNION ALL

    select accepter_id as id
    from RequestAccepted
) t
group by id
order by num DESC
LIMIT 1;