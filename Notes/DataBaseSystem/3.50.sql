select
  *
from Customer
where
  CustomerNumber not in (
    select
      CustomerNumber
    from Purchase
    where
      ItemNumber in (
        select
          ItemNumber
        from Item
        where
          ItemType = 'Food'
      )
  );