select
  CustomerNumber,
  ItemNumber
from Purchase
where
  ItemNumber = '10010001'
  and Count >(
    select
      AVG(Count)
    from Purchase
    where
      ItemNumber = '10010001'
  );