#include <iostream>
#include <queue>
#include <vector>
/*
Time: 2020-01-23 11:20:58
Describe: binary search plus k-coloring
Statue: TODO
*/
std::vector<std::vector<int>> G;
std::vector<int>              color, vis;

bool isBin(int n)
{
    std::queue<int> que;
    que.push(1);
    color[1] = 1;
    while(!que.empty())
    {
        int cur = que.front();
        qur.pop();
        color[0] = color[cur];
        if(vis[cur] != 2)
        {
            for(auto next: G[cur])
            {
                if(vis[next] == 0)
                {
                    que.push_back(next);
                    vis[next] = 1;
                }
                if(color[next] == 0)
                {
                    color[next] = 3 - color[0];
                }
                else
                {
                    if(color[next + color[0] != 3])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(void)
{
    int n, m;
    while(std::cin >> n >> m)
    {
        G.clear();
        G.resize(n + 1);
        color.clear();
        color.resize(n + 1);
        vis.clear();
        vis.resize(n + 1);

        for(int i = 0; i < m; ++i)
        {
            int u, v;
            std::cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(isBin(n))
        {
            std::cout << "1\n";
        }
        else
        {
            std::cout << "2\n";
        }
    }
}

/*
最小染色数-1
*/