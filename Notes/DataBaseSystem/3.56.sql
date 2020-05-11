select
  distinct CustomerNumber
from Purchase a
where
  not exists (
    select
      *
    from Purchase b
    where
      b.CustomerNumber = '100006'
      and not exists(
        select
          *
        from Purchase c
        where
          c.CustomerNumber = a.CustomerNumber
          and c.ItemNumber = b.ItemNumber
      )
  );