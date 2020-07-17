#include <iostream>
#include <stack>
#include <tuple>
#include <vector>

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        std::vector<std::vector<int>> E(n);
        std::vector<char>             vis(n, 0);
        std::vector<int>              S;
        int                           root = 0;
        {
            int edgecount = n - 1;
            for(int i = 0; i < edgecount; ++i)
            {
                int u, v;
                std::cin >> u >> v;
                --u;
                --v;
                E[u].push_back(v);
                E[v].push_back(u);
            }
        }
        {
            while(E.at(root).size() == 1)
            {
                root++;
            }
            {
                std::stack<std::tuple<int, int>> stc;
                stc.push(std::make_tuple(root, 0));
                vis[root] = true;
                while(!stc.empty())
                {
                    auto &cur = stc.top();
                    while(static_cast<size_t>(std::get<1>(cur)) < E[std::get<0>(cur)].size()
                          && vis[E[std::get<0>(cur)][std::get<1>(cur)]])
                    {
                        ++(std::get<1>(cur));
                    }
                    if(static_cast<size_t>(std::get<1>(cur)) < E[std::get<0>(cur)].size())
                    {
                        stc.push(std::make_tuple(E[std::get<0>(cur)][std::get<1>(cur)], 0));
                        vis[E[std::get<0>(cur)][std::get<1>(cur)]] = true;
                        if(E[E[std::get<0>(cur)][std::get<1>(cur)]].size() == 1)
                        {
                            S.push_back(E[std::get<0>(cur)][std::get<1>(cur)]);
                        }
                    }
                    else
                    {
                        stc.pop();
                    }
                }
            }
        }
#ifdef DEBUG
        {
            for(auto p: S)
            {
                std::cout << p + 1 << " ";
            }
            std::cout << std::endl;
        }
#endif
        if(S.size() & 1)
        {
            S.push_back(root);
        }
        std::cout << S.size() / 2 << "\n";
        for(size_t i = 0; i < S.size() / 2; ++i)
        {
            std::cout << S[i] + 1 << " " << S[i + S.size() / 2] + 1 << "\n";
        }
    }
}