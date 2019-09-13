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
typedef std::set<int>::iterator RoadIter;
typedef int Road;
class crossRoad
{
public:
	crossRoad();
	~crossRoad();
	void ini(void);
	void read(void);
	void DFS(void);
	int isArrived(void);
private:
	void DFS(int);
	int switchNeededToArrive;
	Road DefaultRoad;
	std::set<Road> Roadto;
};
const int MAX_N = 107;
const int INF = 0xFFFF;
int n, m, a, b, j, k, start, end;
crossRoad Town[MAX_N];
int main(void)
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // DEBUG
	
	while (scanf("%d%d%d",&n,&start,&end)!=EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			Town[i].read();
		}
		Town[start].DFS();
		printf("%d", Town[end].isArrived());
	}
#ifdef DEBUG
	system("pause");
	system("pause");
#endif // DEBUG

	return 0;
}
crossRoad::crossRoad() { this->ini(); }
crossRoad::~crossRoad() { this->ini(); }
void crossRoad::ini(void)
{
	switchNeededToArrive = INF;
	DefaultRoad = this - Town;
	Roadto.clear();
}
void crossRoad::read(void)
{
	Road RoadCount;
	Road RoadBuffer;
	this->ini();
	scanf("%d", &RoadCount);
	for (int i = 0; i < RoadCount; i++)
	{
		scanf("%d", &RoadBuffer);
		if (i == 0)
		{
			DefaultRoad = RoadBuffer;
		}
		else
		{
			Roadto.insert(RoadBuffer);
		}
	}
}
void crossRoad::DFS(void) { this->DFS(0); }
int crossRoad::isArrived(void) { return switchNeededToArrive == INF ? -1 : switchNeededToArrive; }
void crossRoad::DFS(int deepth)
{
	this->switchNeededToArrive = deepth;
	if (Town[this->DefaultRoad].switchNeededToArrive>deepth)
	{
		Town[this->DefaultRoad].DFS(deepth);
	}
	for (RoadIter iter = this->Roadto.begin(); iter != this->Roadto.end(); iter++)
	{
		if (Town[*iter].switchNeededToArrive>deepth+1)
		{
			Town[*iter].DFS(deepth + 1);
		}
	}
}
