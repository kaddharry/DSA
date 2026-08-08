# Write your MySQL query statement below
select ROUND(100*AVG(order_date = customer_pref_delivery_date),2) as immediate_percentage
from Delivery
where (customer_id, order_date) IN 
                                (Select customer_id, MIN(order_date)
                                from Delivery
                                group by customer_id)
;