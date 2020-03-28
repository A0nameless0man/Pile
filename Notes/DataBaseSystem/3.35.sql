select
  count(*) as `CustomerCount`,
  ItemNumber
from Purchase
where
  ItemNumber = '10010001';