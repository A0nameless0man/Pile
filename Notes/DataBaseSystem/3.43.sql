select
  a.*
from Customer a,
  Customer b
where
  a.CustomerName = b.CustomerName
  and a.CustomerNumber <> b.CustomerNumber;