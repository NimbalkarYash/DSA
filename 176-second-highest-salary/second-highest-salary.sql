# Write your MySQL query statement below
with rankedsalary as
(
    select salary,
    dense_rank() over (order by salary desc) as rnk
    from Employee
)

select max(salary) as SecondHighestSalary from rankedsalary where rnk = 2;