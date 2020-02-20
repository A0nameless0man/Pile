# Gantt

```puml
@startgantt

project starts the 2020/02/1

!function round($time)
[$time Round] as [$time] lasts 3 days and is colored in gray/black
!if %not($time == 1)
!$step = 1
!$last = $time - $step
[$time Round] starts at [$last Round]'s end
!endif
[A $time] lasts 1 days and starts at [$time]'s start
then [B $time] lasts 1 days
[UpSolving $time] lasts 1 day
[UpSolving $time] starts at [A $time]'s end
[UpSolving $time] starts at [B $time]'s end
!endfunction

!function loop($time)
!if %not($time == 1)
!$step = 1
!$last = $time - $step
loop2($last)
!endif
round($time)
!endfunction

!function loop2($time)
loop($time)
!endfunction

!function wh($time)
!while %not($time == 0)
round($time)
!$time = $time - 1
!endwhile
!endfunction

--Conststs--

loop(10)

'wh(5)

@endgantt
```
