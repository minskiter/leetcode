declare @maxinum int
set @maxinum=(select max(Salary) from Employee)
select max(Salary) SecondHighestSalary from Employee where Salary!=@maxinum