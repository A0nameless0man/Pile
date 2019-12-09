#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <array>
#include <map>
#include <string>
class Graph
{
private:
    std::vector<std::vector<unsigned long long>> edges;
    std::vector<bool> vis;

public:
    Graph(unsigned long long n) : edges(n), vis(n, false)
    {
    }
    Graph &unTagAll(void)
    {
        for (auto t : vis)
        {
            t = false;
        }
        return *this;
    }
    Graph &tag(unsigned long long v)
    {
        vis[v] = true;
        return *this;
    }
    bool taged(unsigned long long v)
    {
        return vis[v];
    }
    Graph &addEdge(unsigned long long u, unsigned long long v)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
        return *this;
    }
    const std::vector<unsigned long long> &getEdges(unsigned long long v) const
    {
        return edges[v];
    }
};
int main(void)
{
    unsigned long long n, m;
    while (std::cin >> n >> m)
    {
        Graph g(n);
        for (unsigned long long i = 0; i < m; ++i)
        {
            unsigned long long u, v;
            std::cin >> u >> v;
            g.addEdge(u, v);
        }
        {
            unsigned long long d;
            std::cin >> d;
            std::stack<std::pair<unsigned long long, unsigned long long>> stk;
            g.tag(d);
            stk.push({d, 0});
            std::cout << d << std::endl;
            while (!stk.empty())
            {
                unsigned long long cur = stk.top().first;
                unsigned long long pos = stk.top().second;
                unsigned long long depth = stk.size();
                stk.pop();
                std::string prefix = std::string(2*depth-2, ' ') + "|-";
                for (unsigned long long i = pos;i<g.getEdges(cur).size();++i)
                {
                    auto u = g.getEdges(cur)[i];
                    if (!g.taged(u))
                    {
                        std::cout << prefix << u << std::endl;
                        stk.push({cur,i+1});
                        stk.push({u,0});
                        g.tag(u);
                        break;
                    }
                }
            }
        }
        g.unTagAll();
        {
            unsigned long long d;
            std::cin >> d;
            std::queue<std::pair<unsigned long long, unsigned long long>> stk;
            g.tag(d);
            stk.push({d, 1});
            std::cout << d << std::endl;
            while (!stk.empty())
            {
                unsigned long long cur = stk.front().first;
                unsigned long long depth = stk.front().second;
                stk.pop();
                std::string prefix = std::string(2*depth-2, ' ') + "|-";
                for (auto u : g.getEdges(cur))
                {
                    if (!g.taged(u))
                    {
                        std::cout << prefix << u << std::endl;
                        stk.push({u, depth + 1});
                        g.tag(u);
                    }
                }
            }
        }
    }
    return 0;
}
/*
8 7
0 1
0 2
1 3
1 4
2 6
2 5
3 7
0
0


*/