# Graph

```plantuml
@startuml


!unquoted function edge($u,$v,$w="")
!if $w
$u --> $v :$w
!else
$u --> $v
!endfunction

left to right direction

skinparam usecase {
  ArrowColor Black
}

skinparam interface{
  BackgroundColor<<Source>> Red
  BackgroundColor<<Target>> Yellow
  BorderColor Black
}

skinparam note{
  BorderColor Black
}

skinparam package{
  BackgroundColor<<KeyPoint>> Gray
}

() Source as s <<Source>>

frame Graph {
  frame A <<KeyPoint>> {
    () 1
  }
  () 2
  () 3
  cloud B <<KeyPoint>> {
    () 4
  }

}
() Target as t <<Target>>

note as NotKey
**Not** KeyPoint actually
endnote

NotKey .> A
NotKey .> B


edge(s,1,1)
edge(s,2,2)
edge(1,2,3)
edge(1,3,4)
edge(2,4,5)
edge(3,4,6)
edge(3,t,7)
edge(4,t,7)
edge(3,2,8)

@enduml
```
