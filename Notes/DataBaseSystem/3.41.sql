select
  a.CustomerNumber,
  CustomerName,
  City,
  Tel
from Customer a,
  Purchase b
where
  a.CustomerNumber = b.CustomerNumber
  and ItemNumber = '10010001';