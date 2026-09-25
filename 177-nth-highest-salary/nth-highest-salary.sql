CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        with ranked_salary as
        (
            select salary,
            DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
            FROM Employee
        )
        select distinct salary 
        from ranked_salary 
        where rnk = N
  );
END