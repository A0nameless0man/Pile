select
  distinct Customer.CustomerNumber,
  CustomerName,
  Tel,
  DueDate
from Customer
join (
    Item
    join Purchase on Item.ItemNumber = Purchase.ItemNumber
  ) on Customer.CustomerNumber = Purchase.CustomerNumber
where
  ItemType = 'Sports';