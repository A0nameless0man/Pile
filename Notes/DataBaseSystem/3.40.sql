select
  a.*,
  b.ItemNumber,
  b.OrderTime,
  b.Count,
  b.DueDate,
  b.Payment,
  b.Delivery
from Customer a,
  Purchase b
where
  a.CustomerNumber = b.CustomerNumber;