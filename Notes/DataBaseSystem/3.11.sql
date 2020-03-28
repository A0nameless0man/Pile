create view PurchaseInJiangSuNanJing as
select
  Customer.*,
  ItemNumber
from Customer,
  Purchase
where
  Customer.City = 'JiangSu NanJing'
  and Customer.CustomerNumber = Purchase.CustomerNumber;