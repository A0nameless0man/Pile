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

对于第二种操作，需要有序反向映射，即 `map<value, set<key> >`。

对于第三种操作，容易想到对顶堆，然而 `priority_queue` 不支持删除，可删堆又不支持查找，什么结构可用呢？

`set<key>`: 那当然是……

`map<key, value>`: 当然是我了

```cpp
map<int, set<int>, greater<int> > vk_map;
map<int, int> heap[2];
```

用两个 `map<key, value>` 模拟对顶堆，同步维护反向映射。

第一种操作：若没有该键，直接加入对顶堆，同步更新反向映射，若有，先删除原键值对，再加入新键值对。复杂度 $O(log(len))$，其中 $len$ 为数据库中键的个数。

第二种操作：取反向映射中的第一个，即最大值，输出集合中所有键，同步从对顶堆中删除键，然后从反向映射中删除最大值。最坏情况：一次删除所有键，复杂度 $O(len\cdot log(len))$，由于所有删除的键的数量不会超过 $n + q$，所以整体复杂度 $O((n+q)log(n+q))$。

第三种操作：从对顶堆中查找中位数键，输出对应值。复杂度 $O(log(len))$。

最终整体复杂度 $O((n+q)log(n+q))$。

## E - 后四位

如题目所示

$$
\Huge
3^{25}  =3^{1\cdot2^4}\cdot 3^{1\cdot2^3} \cdot 3^{0\cdot2^2} \cdot 3^{0\cdot2^1} \cdot 3^{1\cdot2^0}\\
\ \ \ \ \ =3^{1\cdot2^0}\cdot 3^{0\cdot2^1} \cdot 3^{0\cdot2^2} \cdot 3^{1\cdot2^3} \cdot 3^{1\cdot2^4}\\
3^{2^4} = 3^{2^3}\cdot 3^{2^3}\\
\cdots\\
3^{2^1} = 3^{2^0}\cdot 3^{2^0}\\
$$

用一个循环来依次得到$\huge 3^{2^0},3^{2^1},\cdots,3^{2^{\lfloor \log_{2}{(n)}+1\rfloor}}$

```cpp
int a = 3;
for(int i = 0;i < n;i++)
{
    a;//所求序列
    a *= a;
}
```

利用 `c` 的位运算,分解 $n$为其二进制的每一位

```cpp
void pow(unsigned int n)
{
    while(n)
    {
        n&1;//所求的二进制序列
        n>>=1;
    }
}
```

综合起来

```cpp
unsigned int pow(unsigned int base,unsigned int n)
{
    unsigned int ans = 1;
    while(n)
    {
        if(n&1)
        {
            ans*=base;
        }
        base*=base;
        n>>=1;
    }
    return ans;
}
```

这道题目要求保留后四位,那也就是对 $10^4$取模

因此


```cpp
unsigned int pow(unsigned int base,unsigned int n)
{
    const unsigned int MOD = 10000;
    unsigned int ans = 1;
    while(n)
    {
        if(n&1)
        {
            ans*=base;
            ans%=MOD;
        }
        base*=base;
        base%=MOD
        n>>=1;
    }
    return ans%MOD;
}
```

## F - 传送门

### 针对 **OIer**

1. 建立空图 $G$
1. `DFS` 找出连通块 作为 $G$ 的节点
2. 暴力搜索 , 图上建边
   - 注意有的连通块完全不靠墙, 尤其是出发的块
   - 这一部分可以做到 $O(n^2)$ 标程中未给出,请自行考虑具体实现
3. 图上找最短路
4. $\textrm{最短路径长}+1$ 即为所求答案
    - 最短路长为 $0$ 即 用户和出口在同一块地面时,输出 `0`

### 针对新手

#### 连通块

可以看出,这题的结果与每一块 '**可以自由走动的地面**' 的大小及形状没有关系

有影响的,是这些 '**可以自由走动的地面**' 之间的关系,即

- 从 某一片 '**可以自由走动的地面**' 可不可以传送到 另一片 '**可以自由走动的地面**' 上

为了方便描述, 定义 一片 '**可以自由走动的地面**' 为 一块 `连通块`

首先,为了了解 连通块 之间的关系, 我们希望计算出

1. 有多少连通块
2. 每片地面属于哪一块连通块

为了存储这两个问题的答案,我们声明两个变量

```cpp
int connectedBlockCount = 0;
int theBlockGroundBelongsTo[n][m] = {-1};
```

约定, 
- `theBlockGroundBelongsTo[i][j]` 代表 $(i,j)$ 这片地面所对应的 连通块 的序号,为 $[0,connectedBlockCount)$ 中的正整数
- `connectedBlockCount` 代表所有已知的  连通块的数量

然后,我们对于所有的格子进行检查

- 是地面吗?

- 还没有编号吗?

如果满足这两个条件,就 `connectedBlockCount++;` , 并且为这块路面 赋予编号

在给一个格子赋予编号之后,检查其相邻的格子,如果也满足以上两个条件,则也赋予相同的编号并进行这个检查

> 这是递归哦,为了不无限递归,记得先赋予编号

#### 传送的可能性

直接对于每个坐标,暴力查找其各个方向所对的墙壁是否宜于传送.

但是有几个地方需要注意

- 某些连通块可能不靠墙,也就无法传送离开

- 真正有用的信息是 : 从 $x$ 号连通块可以传送到 $y$ 号连通块

#### 如何传送

这一部分其实就是在一张有向图上找最短路.

简单来说,对于任意的连通块,保存一个列表来记录从这个连通块可以直接到达的连通块的 **序号**

实现上来说,可以是二维数组,也可以是 `std::vector<std::vector<size_t> >`

然后顺这这个关系开展搜索,每个连通块记录其已知的最短距离并在搜索过程中更新.

- $\textrm{最短路径长}+1$ 即为所求答案
- 最短路长为 $0$ 即 用户和出口在同一块地面时,输出 `0`


```cpp
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>

//#define DEBUG

const int MAX_M = 100;
const int MAX_N = 100;
const int DIR[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
using BlockID = int;
const BlockID VOIDBLOCK = -1;

struct coordinate
{
	int x, y;
};

inline coordinate operator+(const coordinate pos,int dir)
{
	return {pos.x+DIR[dir][0],pos.y+DIR[dir][1]};
}

class Block
{
public:
	Block() : ableToLeaveViaPortal(false), vistied(false), portalCount(-1), portalFrom(VOIDBLOCK) {}
	std::vector<coordinate> member;
	std::set<BlockID> edge;
	bool ableToLeaveViaPortal;
	bool vistied;
	int portalCount;
	BlockID portalFrom;
};

std::vector<Block> blocks;
BlockID theBlockGroundBelongsTo[MAX_M][MAX_N];
bool passable[MAX_M][MAX_N];
bool visibility[MAX_M][MAX_N];
//+--------->y/n
//|
//|
//|
//|
//v
//x/m

inline bool isUnidedGround(int m, int n)
{
	return passable[m][n] && theBlockGroundBelongsTo[m][n] == VOIDBLOCK;
}

inline int setBlockID(coordinate pos,BlockID id)
{
	return theBlockGroundBelongsTo[pos.x][pos.y]=id;
}

int getBlockID(int m, int n)
{
	if (isUnidedGround(m, n))
	{
		int currentID = blocks.size();
		blocks.push_back(Block());
		std::queue<coordinate> que;//BFS based on queue;
		que.push({ m, n });
		while (!que.empty())
		{
			coordinate curPos = que.front();
			que.pop();
			setBlockID(curPos,currentID);
			blocks[currentID].member.push_back(curPos);
			for (size_t i = 0; i < 4; i++)
			{
				if (isUnidedGround(curPos.x + DIR[i][0], curPos.y + DIR[i][1]))
				{
					que.push(curPos+i);
					setBlockID(curPos+i,currentID);
				}
			}
		}
		return currentID;
	}
	else
	{
		return theBlockGroundBelongsTo[m][n];
	}
}

inline int getBlockID(coordinate pos)
{
	return getBlockID(pos.x, pos.y);
}

std::set<BlockID>& getPossiblePortal(coordinate pos, std::set<BlockID>& ans)
{
	if (visibility[pos.x][pos.y])
	{
		for (int i = 0; i < 4; i++)
		{
			int dis = 1;
			while (visibility[pos.x + dis * DIR[i][0]][pos.y + dis * DIR[i][1]])
			{
				++dis;
			}
			--dis;
			if (passable[pos.x + dis * DIR[i][0]][pos.y + dis * DIR[i][1]])
			{
				ans.insert(getBlockID(pos.x + dis * DIR[i][0], pos.y + dis * DIR[i][1]));
			}
		}
	}
	return ans;
}

inline bool nextToWall(coordinate pos)
{
	if (passable[pos.x][pos.y])
	{
		for (int i = 0; i < 4; i++)
		{
			if (!visibility[pos.x + DIR[i][0]][pos.y + DIR[i][1]])
			{
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
	long T = 0;
	int m, n, sx = 0, sy = 0, tx = 0, ty = 0, ans = -1;
	BlockID sBlock, tBlock;
	//std::ios::sync_with_stdio(false);
	std::cin >> T;
	// std::cout<<0<<std::endl;
	// std::cout<<T<<std::endl;
	while(T--)
	//while (std::cin >> m >> n)
	{
		//input
		{
			std::cin >> m >> n;
		}

		//ini
		{
			blocks.clear();
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					theBlockGroundBelongsTo[i][j] = VOIDBLOCK;
					passable[i][j] = false;
					visibility[i][j] = false;
				}
			}
		}

		//read map
		{
			for (int i = 0; i < m; i++)
			{
				std::string input;
				std::cin >> input;
				for (int j = 0; j < n; j++)
				{
					switch (input[j])
					{
					case '.':
						visibility[i][j] = true;
						passable[i][j] = false;
						break;
					case 'w':
						visibility[i][j] = false;
						passable[i][j] = false;
						break;
					case 'g':
						visibility[i][j] = true;
						passable[i][j] = true;
						break;
					case 'p':
						visibility[i][j] = true;
						passable[i][j] = true;
						sx = i;
						sy = j;
						break;
					case 'e':
						visibility[i][j] = true;
						passable[i][j] = true;
						tx = i;
						ty = j;
						break;
					default:
						break;
					}
				}
			}
		}

		//BFS for connected Block
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					getBlockID(i, j);
				}
			}
		}

		//search for edges
		{
			for (BlockID id = 0; id < (int)blocks.size(); id++)
			{
				Block& currentBlock = blocks[id];
				for (coordinate pos : currentBlock.member)
				{
					if (nextToWall(pos))
					{
						currentBlock.ableToLeaveViaPortal = true;
						break;
					}
				}
				if (blocks[id].ableToLeaveViaPortal)
				{
					for (coordinate pos : currentBlock.member)
					{
						getPossiblePortal(pos, currentBlock.edge);
					}
				}
			}
		}


		//BFS for route
		{
			sBlock = getBlockID(sx, sy);
			tBlock = getBlockID(tx, ty);
			if (sBlock != tBlock)
			{
				if (blocks[sBlock].ableToLeaveViaPortal)
				{
					std::queue<BlockID> que;
					que.push(sBlock);
					blocks[sBlock].portalCount = 1;
					blocks[sBlock].vistied = true;
					while (!que.empty())
					{
						BlockID curBlockID = que.front();
						Block& curBlock = blocks[curBlockID];
						for (BlockID id : curBlock.edge)
						{
							if (!blocks[id].vistied)
							{
								blocks[id].portalFrom = curBlockID;
								blocks[id].portalCount = curBlock.portalCount + 1;
								blocks[id].vistied = true;
								que.push(id);
							}
						}
						que.pop();
					}
					ans = blocks[tBlock].portalCount;
				}
				else
				{
					ans = -1;
				}
			}
			else
			{
				ans = 0;
			}
		}

		//output result
		{
			std::cout << ans;
			//if(T)
			{
				std::cout<<std::endl;
			}
		}
		//std::cout<<0<<std::endl;

// 		{
// 			std::clog << "Report:" << std::endl;
// 		}

// 		{
// 			std::clog << "BlockID:" << std::endl;
// 			for (int i = 0; i < m; i++)
// 			{
// 				for (int j = 0; j < n; j++)
// 				{
// 					std::clog << std::setw(3) << getBlockID(i, j) << ' ';
// 				}
// 				std::clog << std::endl;
// 			}
// 		}//check connectedBlock

// 		{
// 			std::clog << "Edges:" << std::endl;
// 			for (BlockID id = 0; id < (int)blocks.size(); id++)
// 			{
// 				std::clog << "BlockID:" << std::resetiosflags(std::ios::left | std::ios::right) << std::setiosflags(std::ios::left) << std::setw(3) << id << std::setiosflags(std::ios::right);
// 				std::clog << "PortalCount:" << std::setw(3) << blocks[id].portalCount;
// 				std::clog << "From:" << std::setw(3) << blocks[id].portalFrom;
// 				std::clog << "Portal to:";
// 				for (BlockID edge : blocks[id].edge)
// 				{
// 					std::clog << std::setw(3) << edge;
// 				}
// 				std::clog << std::endl;
// 			}
// 		}//check edge

	}
	return 0;
}

```

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

其中 $p,q$ 均为素数。由 $p\ \neq \ q$ ，不妨设 $p < q$ ，对于任意确定的 $p$ , 我们要统计所有的 $a$ 满足 $a\leq n$。即 $q \leq floor(\frac{n}{p})$ , 则 $q$ 满足:

$$p < q\leq  floor(\frac{n}{p})$$

$q$的个数即为区间内素数的个数。我们考虑所有的素数 $p$ 满足 $p\in [2,sqrt(n)]$ , 求解对应 $q$ 的个数即可。我们预处理 $f(n)$ 表示小于等于 $n$ 的素数的个数，从而可以在 $O(sqrt(n))$ 的时间复杂度里解决问题。

接下来我们要处理的问题，就是低于线性时间的将 $f(n)$ 求出来。线性时间的话线性筛一下就做出来了。但是线性时间还不够快，要低于线性时间，我们引入一个算法洲阁筛，可以在 $O(\frac{n^\frac{3}{4}}{\ln n})$ 时间里预处理出来。考虑到大部分同学没有数论方面的基础，可以查看如下[链接]( https://blog.csdn.net/semiwaker/article/details/73822107)

一般来说该算法处理问题的上限在 $10^{11}$ 左右，但是为了防止被看出是模板题并且简化题目，所以题目里用了 $10^9$。

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

## I - 格蕾亲真可爱

首先，标题很正确，很给力，但是和题目内容没关系。 
这道题是一个披着外衣的 `01` 背包问题（动态规划）。（ACM中会有很多题目穿着各种奇怪的外衣，比如晕头的蚂蚁。）这道题目的难点显然在于，选的顺序不同，那么产生的影响也会不同（比如样例），因此对暴力算法造成了难度，思考起来也颇为复杂。但是，不管顺序怎么变，选定的宝石固定了，有一点是不变的，那就是会消耗多少宝石。
下面进入正文，拨开这个动态规划题的外衣。
先说结论：只要我们选取的 $k$ 个宝石所消耗的$k+\sum B_i$颗宝石（本身和后面的宝石），不超过总数 $n$ ，那么一定可以找到一种方法来进行魔术。
利用这个结论，我们令$W_i=B_i+1$（物品重量），$V_i=A_i$（物品价值），就变成了一个 $n$ 个物品 $n$ 承重的 `01` 背包问题。（没学过动态规划和 `01` 背包的需要先进行学习）有了结论，学过 `01` 背包的谁都会做，那么怎么得到这个结论呢？

证明如下：
利用反证法：
首先我们假设不能找到一个宝石，使得利用它发动魔术的时候不会让其他被选中的宝石消失。
那么对任意一个被选中的宝石 $x$，找它后面的离它最近的另一个被选中的宝石y（可以为 $x$ 本身，当只选一个宝石的时候），

$$\textrm{if}（y > x) \lbrace D=y-x\rbrace;\textrm{else}\lbrace D=n+x-y;\rbrace$$

( $D$ 表示 $x$ 到 $y$ 相距多少个宝石）
有式一:$D_x < B_x+1$;
对选中的 $k$ 个宝石，共有 $k$ 对这样的相邻的被选中的宝石（若 $k$ 为 $1$，则有其本身构成的一对宝石），能写出 $k$ 个式一，对写出的 $k$ 个式一，小于号左右两边分别累加得，

$\sum D_x < \sum (b_x+1)$,
化简得，$n < k + \sum b_i$,与条件矛盾。
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
