# 包图

```puml
scale 0.5
namespace "销售合同" as Sail {
  class "销售合同容器" as  CC
  class "销售合同" as C
  interface "建立销售合同" as makeC
  interface "销售合同查询" as queryC
  interface "发货通知单" as DeliverT
  interface "到款通知单" as PayT
  interface "催款单" as DueT
  makeC -- CC
  queryC -- CC
  DeliverT -- CC
  PayT -- CC
  DueT -- CC
  CC o- C : 存储 >
}
namespace "采购合同" as Buy {
  class "采购合同容器" as  CC
  class "采购合同" as C
  interface "建立采购合同" as makeC
  interface "采购合同查询" as queryC
  interface "到款通知单" as PayT
  interface "到货通知单" as DeliverT
  interface "催货单" as DueT
  makeC -- CC
  queryC -- CC
  DeliverT -- CC
  PayT -- CC
  DueT -- CC
  CC o- C : 存储 >
}
class "合同管理器" as CM
CM *-d- Buy.CC : 管理 >
CM *-d- Sail.CC : 管理 >
class "合同统计表" as CCT
Buy.CC <.-u- CCT :统计 <
Sail.CC <.-u- CCT :统计 <
interface "统计表" as CT
CCT <|- CT
```
