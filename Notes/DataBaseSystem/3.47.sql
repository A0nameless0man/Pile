select
  Customer.*,
  ItemNumber
from Customer
left join Purchase on Customer.CustomerNumber = Purchase.CustomerNumber;