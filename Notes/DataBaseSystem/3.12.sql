create view PurchaseOf10010001InJSNJ as
select
  *
from PurchaseInJiangSuNanJing
where
  ItemNumber = 10010001;