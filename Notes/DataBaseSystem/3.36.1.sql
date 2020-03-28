select
  concat(count(*), " Item sold ", Pcnt, " SKU.")as `Sali report`
from (
    select
      count(*) as `Pcnt`
    from Purchase
    group by
      ItemNumber
  ) as PurchaseCount
group by
  Pcnt;