select
  *
from Item
where
  Price < all(
    select
      Price
    from Item
    where
      ItemType = 'Food'
  );