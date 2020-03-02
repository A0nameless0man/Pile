# ContestURL

[VOJ](https://vjudge.net/contest/359115)

## A

$$
ans = \begin{cases}
k &a = b = c \\
2^k\times k/2 & a \neq b\land(a = c\lor b=c)\\
0&a\neq c \land b\neq c\\
\end{cases}
$$

## G

>找最长的，最多有一个字母出现了奇数次的子串

```puml
start
:枚举每一个字母;
:寻找除了这个字母外的字母出现了偶数次的子串;
end
```

## J

|x|y|
|---|---|
|0|0|
|1|1|
|2|2|
|2|0|
|3|1|

|dx|dy|cnt|
|---|---|---|
|1|1|3|
|2|2|1|
|2|0|2|
|3|1|1|
|1|-1|2|
|0|-2|1|
