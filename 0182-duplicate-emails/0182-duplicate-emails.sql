# Write your MySQL query statement below
select email as Email
from Person
group by email
having count(*) > 1; 
#count(*) works as it's given email hasnt null 