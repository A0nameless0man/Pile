select
  ItemName,
  case
    when Price < 20 then "Cheap"
    when Price < 50 then "Mormal"
    when Price < 100 then "Expensive"
    else "Luxury"
  end as `Level`
  from Item;