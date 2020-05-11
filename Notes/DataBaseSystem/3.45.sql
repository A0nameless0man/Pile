select
  distinct CustomerName,
  Tel
from
Customer inner join Purchase on Customer.CustomerNumber = Purchase.CustomerNumber
where ItemNumber = '10010001';