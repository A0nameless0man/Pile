# 传送门

## 针对 **OIer**

1. 建立空图 $G$
1. `DFS` 找出连通块 作为 $G$ 的节点
2. 暴力搜索 , 图上建边
   - 注意有的连通块完全不靠墙, 尤其是出发的块
   - 这一部分可以做到 $O(n^2)$ 标程中未给出,请自行考虑具体实现
3. 图上找最短路
4. $\textrm{最短路径长}+1$ 即为所求答案

## 针对新手

### 连通块

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

在给一个格子赋予编号之后,检查其相邻的格子,如果也满足以上两个条件,则也赋予编号并进行这个检查

```cpp
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
```