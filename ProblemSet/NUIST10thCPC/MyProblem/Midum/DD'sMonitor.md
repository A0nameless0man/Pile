# DD 的显示器

## 题目描述

`DD` 的意思是 `誰も大好き`　指那些同时关注多个 `VTB` 的直播的人。

这天，有个 `DD` 准备看直播。但是他只准备了一台显示器，最多同时观看 $4$ 场直播。

但是最近好像特别热闹，有许多 `VTB` 在 `Twitter` 上发出了直播预告。

`DD` 希望能尽量观看所有的直播，因此，如果某一时刻同时开播的 `VTB` 数量大于 $4$ , `DD` 就会感到焦虑，他的焦虑值会每分钟上涨 $1$ 点。

如果某一时刻，没有`VTB`开播，`DD` 会感到失望，同时，如果时间在 6:00 到 18:00 之间( $t\mod 2400 \in [0600,1800)$ )，`DD` 会开始写作业，否则 `DD` 会睡觉。

现在给出一个月内，`DD` 关注的所有 `VTB` 的开播计划。请帮 `DD` 求出，他的焦虑值一共有几点，做了多长时间作业，睡了多长时间觉。

## 输入描述

第一行有一个整数 $T$ ,表示测试的组数，每一组代表一月（ $30$ 天）。

对于每一组样例，其第一行为一个整数 $n$ 代表 `DD` 关注的 `VTB` 人数。

下面 $n$ 行，每行代表一人。第 $i$ 行开头有一个数字 $a_i$ 代表此人本月开播次数。后面有 $a_i$ 组开播计划，每组计划有两个整数 $l$ $r$ ，分别表示开播的时间和下播的时间,即这个 `VTB` 在 $[l,r)$ 时间段在直播。

>本题中时间的表示是一个 $6$位整数，前 $2$位表示日期，然后 $2$ 位表示小时，后 $2$ 位表示分钟，一日从 `0000` 开始。即某月第一日的时间范围为 $[000000,002400)$ 共计 $1440$ 分钟。
>
>时间使用 **30小时制** 表示（因为有人喜欢通宵直播，但是计算时只计算 到本月 30 日 24 时。
>
>即次日凌晨6时 **可以** 表示为今日30时

直播开始时间大于等于 `010000` 小于 `302400` 。
直播结束时间大于对应的开始时间，小于等于 `303000` 。
同一个 `VTB` 不能同时开两场直播。
每个文件里总的直播数小于 $10^4$ 场、不超过 $1000$ 组测试。

每组测试是相互独立的

## 输出描述

对于每个月，一行输出三个整数，分别表示 `DD` 的焦虑值，写作业的分钟数和睡觉的分钟数。

## 样例输入

```txt
2
5
1 010000 302400
1 010000 303000
1 010000 302400
1 010000 302400
1 010000 302400
5
0
0
0
0
0
```

## 样例输出

```txt
43200 0 0
0 21600 21600
```