# Write your MySQL query statement below
DELETE from Person
where id NOT IN(
    select id from (select MIN(id) as id
    from Person
    group by email) as temp
);