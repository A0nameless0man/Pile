select
  CustomerNumber,
  CustomerName
from Customer
where
  City like "JiangSu%"
  and Gender = 'Male';