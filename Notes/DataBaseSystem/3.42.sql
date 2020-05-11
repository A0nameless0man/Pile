select
  distinct a.CustomerNumber,
  CustomerName,
  Tel,
  DueDate
from Customer a,
  Purchase b,
  Item c
where
  a.CustomerNumber = b.CustomerNumber
  and b.ItemNumber = c.ItemNumber
  and ItemType = "Sports"
order by
  DueDate;