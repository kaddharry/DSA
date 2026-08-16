# Write your MySQL query statement below
select (select u.name
from Users u
JOIN MovieRating mr
ON u.user_id = mr.user_id
group by u.user_id, u.name
order by Count(*) DESC, u.name ASC
LIMIT 1) as results
UNION ALL
select (select m.title
        from Movies m
        JOIN MovieRating mr
        on m.movie_id = mr.movie_id
        where mr.created_at >= '2020-02-01'
        AND mr.created_at < '2020-03-01'
        group by m.movie_id, m.title
        order by AVG(rating) DESC, m.title ASC
        LIMIT 1
) as results