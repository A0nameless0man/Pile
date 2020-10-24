# Float Chart

>Algorithm Homework too

```plantuml
@startuml
start
partition init {
  :Accept Set **s**<
  note:size of **s** is ""s.size()""
  :Generate BinArray **bin** whit the same size of s<
  :Fill **bin** With 0;
  :create an empty Set of BinArray **ans**<
}
partition "enum sub set of s"{
  while(**bin** is not full of 1)
    :Int sum = 0<
    :sum = Dot Product of **bin** and **s**;
    if (sum == m)then(Yes)
      :add curent **bin** into **ans**;
      :alert : leagal ans found;
      :print **s** using **bin** as mask;
    else(No)
    endif
    :++**bin**;
  end while
}
:return ans;
stop

@enduml
```

```plantuml
@startuml
partition dedece {
  partition reverse {
    :static const BASE = 10;
    detach
    start
    :Accept **S**<
    if(**s**!=0)then(Yes)
      :print **s**%**BASE**;
      :call reverse with **s**/**BASE**;
      detach
    else(No)
    end
    endif
  }
}
partition cycle {
  :static const BASE = 10;
  detach
  start
  :Accept **S**<
  while(**s!=0**)
    :print **s**%**BASE**;
    :**s**/=**BASE**;
  endwhile
  stop
}
@enduml
```

```puml
|出库单|
|合同管理|
|付款单|
|合同管理|

start
:签订销售合同;
:核对合同;
fork
|出库单|
:核对货物清单;
if (检查货物数量) then (有货)
:签发发货单]
else (无货)
end
endif
forkagain
|付款单|
:核对付款单;
if (付款情况) then (已付讫)
:签发付款单;
else
end
endif
|合同管理|
endfork

:发货;
:合同履约;
split
end
split again
-[#555,dotted]->
:合同存档]
detach
endsplit
```

```puml
|tech forks|
|salesperson|
|consultant|
start
|salesperson|
:call client;
:set up appointment;
if (location) then (on site)
|tech forks|
:prepare conference room;
else (offsite)
|consultant|
:prepaer on laptop;
endif
|salesperson|
fork
|tech forks|
:meet customer;
forkagain
|salesperson|
:meet customer;
forkagain
|consultant|
:meet customer;
|salesperson|
endfork
:follow up;
if (problem) then
-[]->
else(has one)
|consultant|
:proposal;
endif
end
```
