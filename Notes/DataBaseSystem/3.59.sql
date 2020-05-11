(
  select
    *
  from Item
  where
    Price < 50
)
except
  (
    select
      *
    from Item
    where
      Inventory > 20
  );