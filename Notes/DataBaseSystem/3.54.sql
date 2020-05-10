select
  *
from Item
where
  Price < any(
    select
      Price
    from Item
    where
      ItemType = 'Food'
  );