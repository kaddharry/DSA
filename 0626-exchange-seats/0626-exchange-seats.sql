# Write your MySQL query statement below
select s1.id, COALESCE(s2.student, s1.student) as student
from Seat s1
Left JOIN Seat s2
ON s2.id = Case when s1.id % 2 = 1 then s1.id + 1
                else s1.id - 1
            end
;