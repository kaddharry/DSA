# Write your MySQL query statement below
select v.customer_id, Count(*) as count_no_trans
from Visits v
Left Join Transactions t
ON v.visit_id = t.visit_id
where t.transaction_id IS NULL
group by v.customer_id;