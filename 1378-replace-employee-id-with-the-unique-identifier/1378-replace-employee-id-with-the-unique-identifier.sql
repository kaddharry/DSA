# Write your MySQL query statement below
select e.name, u.unique_id
from Employees e
Left Join EmployeeUNI u
ON e.id = u.id;