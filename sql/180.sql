select DISTINCT Num ConsecutiveNums FROM (select Num,LAG(Num,1) Over(Order by Id) as Numa,LAG(Num,2) Over(Order by Id) as Numb from Logs) as c where Num=Numa and Num=Numb