select
  City
from Customer
where
  Birthday > '1975-1-1'
group by
  City
having
  count(*) >= 2;