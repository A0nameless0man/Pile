alter view PurchaseOf10010001InJSNJ as
select
  *
from PurchaseInJiangSuNanJing
where
  ItemNumber = 30010001;