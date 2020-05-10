select
  Customer.*,
  Purchase.*
from Customer,
  Purchase
where
  Customer.CustomerNumber = Purchase.CustomerNumber;