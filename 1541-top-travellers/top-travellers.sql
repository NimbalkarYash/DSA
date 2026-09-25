# Write your MySQL query statement below
with travel as
(
    select u.name as name, u.id, IF(SUM(r.distance) IS NULL, 0, SUM(r.distance)) as travelled_distance
    from Users u
    left join Rides r
    on r.user_id = u.id
    group by u.id, u.name
    order by travelled_distance DESC, u.name ASC
)

select name, travelled_distance
from travel
order by travelled_distance DESC, name ASC