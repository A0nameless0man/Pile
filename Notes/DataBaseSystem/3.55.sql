select
  CustomerName
from Customer a
where
  exists (
    select
      *
    from Purchase b
    where
      b.CustomerNumber = a.CustomerNumber
      and b.ItemNumber = '10010001'
  );