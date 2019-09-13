#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
template <typename T> void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}
class node;
class node
{
public:
	std::set<int> in, out;
	bool ConnectedToEnd;
	bool Useable;
	bool Passed;
	int bfs_deepth;
	void ini(void)
	{
		in.clear();
		out.clear();
		ConnectedToEnd = false;
		Useable = false;
		Passed = false;
		bfs_deepth = 0;
	}
	bool CheckUseablity(void);
	node(void)
	{
		this->ini();
	}
};
const int MAX_N = 10007;
int n, m, a, b, j, k, s, t;
node nodes[MAX_N];
bool node::CheckUseablity(void)
{
	if (ConnectedToEnd)
	{
		std::set<int>::iterator iter;
		for (iter = out.begin(); iter != out.end(); iter++)
		{
			if (!nodes[*iter].ConnectedToEnd)
			{
				return Useable = false;
			}
		}
		return Useable = true;
	}
	else
	{
		return Useable = false;
	}
}
std::queue<int> bfs_queue;
void bfs(void)
{
	int i;
	int deepth;
	while (!bfs_queue.empty())
	{
		i = bfs_queue.front();
		bfs_queue.pop();
		if (i==t)
		{
			return;
		}
		deepth = nodes[i].bfs_deepth+1;
		std::set<int>::iterator iter;
		for (iter = nodes[i].out.begin(); iter != nodes[i].out.end(); iter++)
		{
			if (nodes[*iter].Useable&&!nodes[*iter].Passed)
			{
				nodes[*iter].bfs_deepth = deepth;
				bfs_queue.push(*iter);
				nodes[*iter].Passed = true;
			}
		}
	}
}
void dfs(int rootis)//用dfs筛选可以成为路径点的点
{
	if (nodes[rootis].ConnectedToEnd)
	{
		return;
	}
	else
	{
		nodes[rootis].ConnectedToEnd = true;
		std::set<int>::iterator iter;
		for (iter = nodes[rootis].in.begin(); iter != nodes[rootis].in.end(); iter++)
		{
			dfs(*iter);
		}
	}
}
int main(void)
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // DEBUG

	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			nodes[i].ini();
		}//读取点数并初始化
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);
			if (a != b)
			{
				nodes[a].out.insert(b);
				nodes[b].in.insert(a);
			}
		}//读取边
		scanf("%d%d", &s, &t);//读取起点与终点
		dfs(t);//标定与终点有连接的点
		for (int i = 1; i <= n; i++)
		{
			nodes[i].CheckUseablity();
		}
		bfs_queue.push(s);
		nodes[s].Passed = true;
		bfs();
		if (nodes[t].bfs_deepth==0)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n", nodes[t].bfs_deepth);
		}
	}
#ifdef DEBUG
	system("pause");
	system("pause");
#endif // DEBUG

	return 0;
	}
