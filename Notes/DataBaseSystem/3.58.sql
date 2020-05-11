(
  select
    *
  from Item
  where
    Price < 50
)
INTERSECT
  (
    select
      *
    from Item
    where
      Inventory > 20
  );