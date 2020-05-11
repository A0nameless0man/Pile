create table TempPurch (
  CustomerNumber char(6) not null,
  Count int
);
insert into TempPurch
select
  CustomerNumber,
  COUNT(*)
from Purchase
group by
  CustomerNumber;