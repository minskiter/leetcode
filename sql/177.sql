CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (select distinct Salary as getNthHighestSalary from [Employee] order by Salary desc offset (@N-1) rows fetch next 1 rows only)
END