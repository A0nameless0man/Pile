create view JiangSuNanJingCustomer as
select
  *
from Customer
where
  City = "JiangSu NanJing";