select
  Customer.*,
  ItemNumber
from Purchase
right join Customer on Customer.CustomerNumber = Purchase.CustomerNumber;