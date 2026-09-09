with RankedMoney as
(
    select 
        e.name as Employee, 
        e.salary as Salary, 
        d.name as Department,
    DENSE_RANK() over (partition by e.departmentId order by e.salary desc) as rnk   
    from Employee e
    join Department d
    on e.departmentId = d.id
    
)
select Department, Employee, Salary
from RankedMoney 
where rnk <= 3
