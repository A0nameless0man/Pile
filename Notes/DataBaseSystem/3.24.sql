select
  *
from Customer
where
  Birthday not between '1980-1-1'
  and '1980-12-31';