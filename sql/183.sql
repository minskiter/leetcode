SELECT Name Customers FROM Customers where Id not in (select CustomerId FROM Orders)
