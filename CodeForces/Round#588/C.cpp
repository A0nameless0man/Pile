#include <iostream>
#include <map>
#include <vector>
std::vector<std::vector<size_t>>                    hate;
std::vector<bool>                                   vis;
std::vector<std::vector<std::pair<size_t, size_t>>> triples;
std::vector<size_t>                                 solve;
std::vector<size_t>                                 danger;
std::vector<size_t>                                 salary;
void                                                find(size_t v)
{
    vis[v] = true;
    for(auto u: hate[v])
    {
        if(!vis[u])
        {
            vis[u] = true;
            for(auto k: hate[u])
            {
                if(!vis[k])
                {
                    triples[v].push_back({ u, k });
                }
            }
            vis[u] = false;
        }
    }
    vis[v] = false;
}
void check(size_t v) {}
int  main(void)
{
    size_t n, m;
    std::cin >> n >> m;
    hate.clear();
    hate.resize(n + 1);
    vis.clear();
    vis.resize(n + 1);
    triples.clear();
    triples.resize(n + 1);
    solve.clear();
    solve.resize(n + 1);
    while(m--)
    {
        size_t a, b;
        hate[a].push_back(b);
        hate[b].push_back(a);
    }
}