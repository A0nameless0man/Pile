select
  *
from Customer
inner join Purchase on Customer.CustomerNumber = Purchase.CustomerNumber;