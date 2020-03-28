select
  ItemNumber,
  count(*) as `OrderCount`
from Purchase
group by
  ItemNumber
having
  OrderCount > 1;