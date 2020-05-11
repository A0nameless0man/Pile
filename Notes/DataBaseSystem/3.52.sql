select
  CustomerNumber,
  ItemNumber
from Purchase a
where
  Count > (
    select
      AVG(Count)
    from Purchase b
    where
      a.CustomerNumber = b.CustomerNumber
  );