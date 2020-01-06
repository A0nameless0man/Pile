#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 100005;
const int M = 500005;
int       n, m;
struct edge
{
    int next, to, weight;
    edge() {}
    edge(int next, int to, int weight): next(next), to(to), weight(weight) {}
} edges[M];
int  tail[N], cnt = 0;  // tail是每个点的最后一个边在edges里的索引
void add_edge(int from, int to, int weight)
{
    edges[++cnt] = edge(tail[from], to, weight);
    tail[from]   = cnt;
}  //前向星 //去你妈的前向星，不是链表吗？

bool vis[N];
int  distenceToSource[N];
struct node
{
    int ind, distenceToSource;
    node() {}
    node(int ind, int distenceToSource): ind(ind), distenceToSource(distenceToSource) {}
};
bool operator<(node x, node y)
{
    return x.distenceToSource > y.distenceToSource;
}
priority_queue<node> q;
void                 dijkstra(int source)
{
    for(int i = 1; i <= n; ++i)
        distenceToSource[i] = inf;
    distenceToSource[source] = 0;
    q.push(node(source, 0));
    int setCount = N;  //防负环
    while(setCount != 0 && !q.empty())
    {
        node currentNode = q.top();
        q.pop();
        if(vis[currentNode.ind] != 0)
            continue;
        vis[currentNode.ind] = 1;
        for(int j = tail[currentNode.ind]; j != 0; j = edges[j].next)
        {
            if(distenceToSource[edges[j].to] > currentNode.distenceToSource + edges[j].weight)
            {
                distenceToSource[edges[j].to] = currentNode.distenceToSource + edges[j].weight;
                q.push(node(edges[j].to, distenceToSource[edges[j].to]));
            }
        }
        --setCount;
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int f, t, w;
        cin >> f >> t >> w;
        add_edge(f, t, w);
    }
    dijkstra(1);
    cout << distenceToSource[n] << endl;

    return 0;
}
