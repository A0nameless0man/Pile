select
  *
from Customer
where
  City in (
    select
      City
    from Customer
    where
      CustomerName = "ZXL"
  );