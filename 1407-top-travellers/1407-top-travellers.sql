# Write your MySQL query statement below
Select u.name,
COALESCE(sum(d.distance),0) as travelled_distance
from users u left join Rides d
on u.id = d.user_id
group by d.user_id
order by travelled_distance desc ,u.name asc;