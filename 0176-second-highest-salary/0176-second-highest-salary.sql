# Write your MySQL query statement below
select MAX(salary) as SecondHighestSalary
from Employee
Where salary < (select max(salary) from Employee);