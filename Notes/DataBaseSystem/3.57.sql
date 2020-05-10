select
  CustomerNumber
from Purchase
where
  ItemNumber = '10010001'
union
select
  CustomerNumber
from Purchase
where
  ItemNumber = '10020001';