## A - 搭梯子

可知任意一根木条均可作为梯子的阶，所以为了搭出最多的阶数，我们可将最长的两根木条 $(a_{max_1},a_{max_2})$ 作为梯子两侧的边。由此，我们可知 $min(a_{max_2}-1 , n-2)$ 为此题的解。
求解第二长木条有多种方法：
1.整体扫描记录第一长与第二长，$O(n)$ 时间。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int inp[100010];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, max1 = 0, max2 = 0;
        cin >> n;
        for(int i = 0; i < n; i ++){
            cin >> inp[i];
            if(inp[i] >= max1){
                max2 = max1;
                max1 = inp[i];
            }
            else if(inp[i] > max2){
                max2 = inp[i];
            }
        }
        cout << min(max2-1, n-2) << endl;
    }
    return 0;
}
```

2.排序后取第二长。快排$O(n\cdot \log (n))$可过，冒泡、选择排序与劣质手写快排不可过。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int inp[100010];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++){
            cin >> inp[i];
        }
        sort(inp, inp+n);
        cout << min(inp[n-2]-1, n-2) << endl;
    }
    return 0;
}
```


## B - Tree on Graph

建反边:

$ed$ 能连接到 $k$ 个点, 则总共有 $k-1$ 条边；

在最短路径确定的情况下，共享的路径长度越长越好，等价于每个点的前驱边越短越好；

综上，对于每个点，每次更新 $ed$ 到它的最短距离时，顺便更新前驱边。

## C - 欢迎来到算法至上主义的比赛

>1. `ctrl`+`c`
>
>2. `ctrl`+`v`

## D - 键值数据库

### 暴力做法

用一个 $500000$ 的数组作为表，查找、添加、删除键值对都是 $O(1)$.

弹出具有最大价值的所有键，遍历一次数据表，找出最大值，再升序遍历一次，删除对应键，将对应键存储到另一个数组中，最后输出。时间复杂度 $O(M)$，其中 $M = 500000$.

查询中位数键对应的值，同样遍历一次数据表，存储所有有效键，直接找到中位数键，并输出对应值，时间复杂度 $O(M)$.

总体时间复杂度 $O(qM)$

优化1：用 `vector<int>`　存储所有有效键，查询中位数键前先排序一遍，时间复杂度降为 $O(q(n+q)log(n+q))$。

优化2：用 `vector<int>`　存储所有有效键，插入时用二分查找保证有序性，时间复杂度降为 $O(q(n+q))$.

### 正解

对于第一种操作，至少需要一个 `map<key, value>` 来存储。

对于第二种操作，需要有序反向映射，即 `map<value, set<key>>`。

对于第三种操作，容易想到队顶堆，然而 `priority_queue` 不支持删除，可删堆又不支持查找，什么结构可用呢？

`set<key>`: 那当然是……

`map<key, value>`: 当然是我了

```cpp
map<int, set<int>, greater<int> > vk_map;
map<int, int> heap[2];
```

用两个 `map<key, value>` 模拟队顶堆，同步维护反向映射。

第一种操作：若没有该键，直接加入队顶堆，同步更新反向映射，若有，先删除原键值对，再加入新键值对。复杂度 $O(log(len))$，其中 $len$ 为数据库中键的个数。

第二种操作：取反向映射中的第一个，即最大值，输出集合中所有键，同步从队顶堆中删除键，然后从反向映射中删除最大值。最坏情况：一次删除所有键，复杂度 $O(len\cdot log(len))$，由于所有删除的键的数量不会超过 $n + q$，所以整体复杂度 $O((n+q)log(n+q))$。

第三种操作：从队顶堆中查找中位数键，输出对应值。复杂度 $O(log(len))$。

最终整体复杂度 $O((n+q)log(n+q))$。

## H - 假·签到题
判断一个数字有几个因子可以在 $O(n)$ 时间内处理，即穷举 $i\in [1,n]$ ,判断 $i$ 是否为 $n$ 的因子。这样可以用两重循环把结果统计出来。最终复杂度 $O(n^2)$ 。

```cpp
#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=1;j<=i;j++){
                if(i%j==0){
                    cnt++;
                }
            }
            if(cnt==4){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
```

## G - 真·签到题
这个题目和上一个题目唯一的区别是数据范围扩充到了 $10^9$ , 如果还是用 $O(n^2)$ 的算法大概要算 $10^{10}$ 秒，也就是$317$年左右......

所有我们要想办法降低时间复杂度。考虑任何一个 $4$ 因子数，只有两种情况，一种是立方数，一种是有且仅有两个素因子。立方数很好处理，数量就是 $^{3}\sqrt{n}$ 。 接下来我们要找出 $[1,n]$ 内所有有且仅有两个素因子的数的个数。 对于任意一个满足条件的数字，我们不妨记为 $a$ ，满足：

$$a = p\times\ q$$

其中 $p,q$ 均为素数。由 $p\ \neq \ q$ ，不妨设 $p<q$ ，对于任意确定的 $p$ , 我们要统计所有的 $a$ 满足 $a\leq n$。即 $q \leq floor(\frac{n}{p})$ , 则 $q$ 满足:

$$p < q\leq  floor(\frac{n}{p})$$

$q$的个数即为区间内素数的个数。我们考虑所有的素数 $p$ 满足 $p\in [2,sqrt(n)]$ , 求解对应 $q$ 的个数即可。我们预处理 $f(n)$ 表示小于等于 $n$ 的素数的个数，从而可以在 $O(sqrt(n))$ 的时间复杂度里解决问题。

接下来我们要处理的问题，就是低于线性时间的将 $f(n)$ 求出来。线性时间的话线性筛一下就做出来了。但是线性时间还不够快，要低于线性时间，我们引入一个算法洲阁筛，可以在 $O(\frac{n^\frac{3}{4}}{\ln n})$ 时间里预处理出来。考虑到大部分同学没有数论方面的基础，可以查看如下[链接]( https://blog.csdn.net/semiwaker/article/details/73822107)

一般来说该算法处理问题的上限在 $10^{11}$ 左右，但是为了防止被看出是模板题并且简化题目，所有题目里用了 $10^9$。

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const ll maxm = 1e11;
const ll maxp = sqrt(maxm) + 10;
ll f[maxp],g[maxp];
bool isprime[maxn];
int prime[maxn];
int tot = 0;
void init()
{
    for(int i = 2; i < maxn; i ++) isprime[i] = true;
    for(int i = 2; i < maxn; i++){
        if(isprime[i]) prime[tot++] = i;
        for(int j = 0; j < tot && i * prime[j] < maxn; j++){
            isprime[i * prime[j]] = false;
            if(i % prime[j] == 0) break;
        }
    }
}
ll solve(ll n)
{
    ll i,j,m;
    for(m = 1; m * m <= n; m++) f[m] = n/m - 1;
    for(i = 1;i <= m; i++) g[i] = i-1;
    for(i = 2; i <= m; i++){
        if(g[i] == g[i-1]) continue;
        for(j = 1; j <= min(m - 1, n/i/i); j++){
            if(i * j < m) f[j] -= f[i * j] - g[i - 1];
            else f[j] -= g[n/i/j] - g[i-1];
        }
        for(j = m;j >= i * i; j--) g[j] -= g[j / i] - g[i - 1];
    }
    ll ans = 0;
    for(int i = 2; i < m; i++){
        if(g[i] == g[i - 1]) continue;
        ans += f[i] - g[i];
    }
    return ans;
}
int main (void)
{
    int t;
    cin>>t;
    init();
    while(t--){
        ll n;scanf("%lld", &n);
        ll ans = 0;
        for(int i = 0; i < tot; i++){
            if(prime[i] * 1LL * prime[i] * prime[i] > n) break;
            ans++;
        }
        printf("%lld\n", ans + solve(n));
    }
    return 0;
}
```

## I-格雷亲真可爱

首先，标题很正确，很给力，但是和题目内容没关系。 
这道题是一个披着外衣的 `01` 背包问题（动态规划）。（ACM中会有很多题目穿着各种奇怪的外衣，比如晕头的蚂蚁。）这道题目的难点显然在于，选的顺序不同，那么产生的影响也会不同（比如样例），因此对暴力算法造成了难度，思考起来也颇为复杂。但是，不管顺序怎么变，选定的宝石固定了，有一点是不变的，那就是会消耗多少宝石。
下面进入正文，拨开这个动态规划题的外衣。
先说结论：只要我们选取的 $k$ 个宝石所消耗的$k+\sum B_i$颗宝石（本身和后面的宝石），不超过总数 $n$ ，那么一定可以找到一种方法来进行魔术。
利用这个结论，我们令$W_i=B_i+1$（物品重量），$V_i=A_i$（物品价值），就变成了一个 $n$ 个物品 $n$ 承重的 `01` 背包问题。（没学过动态规划和 `01` 背包的需要先进行学习）有了结论，学过 `01` 背包的谁都会做，那么怎么得到这个结论呢？

证明如下：
利用反证法：
首先我们假设不能找到一个宝石，使得利用它发动魔术的时候不会让其他被选中的宝石消失。
那么对任意一个被选中的宝石 $x$，找它后面的离它最近的另一个被选中的宝石y（可以为 $x$ 本身，当只选一个宝石的时候），
$\textrm{if}（y>x) \lbrace D=y-x\rbrace;\textrm{else}\lbrace D=n+x-y;\rbrace$ ( $D$ 表示 $x$ 到 $y$ 相距多少个宝石）
有式一:$D_x < B_x+1$;
对选中的 $k$ 个宝石，共有 $k$ 对这样的相邻的被选中的宝石（若 $k$ 为 $1$，则有其本身构成的一对宝石），能写出 $k$ 个式一，对写出的 $k$ 个式一，小于号左右两边分别累加，
$\sum D_x < \sum (b_x+1)$,化简得，$n < k+\sum b_i$,与条件矛盾。
所以，一定可以找到一个被选中的宝石，使得利用它发动魔术的时候不会让其他被选中的宝石消失。
之后，也一定可以找到第二个被选中的宝石，以此类推，最终可以实现。
笔者出题的本心是希望大家看到题目能多多思考，考察研究模型。不要直接考虑xxx能不能用。
以上。
最后，格蕾亲真可爱，格蕾亲真可爱，格蕾亲真可爱。嘿嘿嘿。

```cpp
#include<iostream>
#include<stdio.h>
using namespace std;
long long  w[1005],v[1005];
long long dp[1005][1005];
int main(){
    long long i,j,n;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld%lld",&v[i],&w[i]);
        w[i]++;
    }
    for(i=1;i<=n;i++)
    {
        for(j=n;j>=0;j--)
        {
            if(j>=w[i])
            {
                dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    printf("%lld\n",dp[n][n]);
    return 0;
}
```
