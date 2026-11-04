# Write your MySQL query statement below
with temp as (
    select min(id) as id
    from person
    group by email
)
delete from person
where id not in (
    select id from temp
)