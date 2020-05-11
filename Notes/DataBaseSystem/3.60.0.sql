create view JScustomer as
select
  *
from Customer
where
  City like "JiangSu%";
create view LeftInvetory(ItemNumber,LeftCount)  as
select
  a.ItemNumber,
  a.Inventory - x.OrderSum
from Item a,(
    select
      ItemNumber,
      SUM(Count) as OrderSum
      from Purchase
    group by
      ItemNumber
  ) x
where
  a.ItemNumber = x.ItemNumber;
create view Bill(CustomerNumber, Cost) as
select
  Customer.CustomerNumber ,SUM(Price * Count)
from (Customer
join Purchase on Customer.CustomerNumber = Purchase.CustomerNumber)
join Item on Purchase.ItemNumber = Item.ItemNumber
group by
  CustomerNumber;