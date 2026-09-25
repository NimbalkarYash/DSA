# Write your MySQL query statement below
select r.name as Employee
from Employee e
join Employee r
on e.id = r.managerId
where r.salary > e.salary 