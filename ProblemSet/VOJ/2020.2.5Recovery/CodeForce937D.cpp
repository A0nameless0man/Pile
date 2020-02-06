#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
int n, m, s;

bool circle(std::vector<std::vector<int>> &G, int s)
{
    std::stack<std::pair<int, int>> stc;
    std::vector<int>               instc(n, false);
    std::vector<int>               vis(n, false);
    stc.push(std::make_pair(s, 0));
    instc[s] = true;
    vis[s]   = true;
    while(!stc.empty())
    {
        auto &p = stc.top();
        if(p.second < G[p.first].size())
        {
            auto nxt = G[p.first][p.second];
            nxt -= n;
            if(!vis[nxt])
            {
                instc[nxt] = true;
                vis[nxt]   = true;
                stc.push(std::make_pair(nxt, 0));
            }
            else if(instc[nxt])
            {
                return true;
            }
            ++(p.second);
        }
        else
        {
            instc[p.first] = false;
            stc.pop();
        }
    }
    return false;
}

int main(void)
{
    while(std::cin >> n >> m)
    {
        std::vector<std::vector<int>> doubleG(n * 2);
        std::vector<int>             vis(n * 2, false);
        std::vector<int>              last(2 * n, -1);
        std::queue<int>               que;
        for(int i = 0; i < n; ++i)
        {
            int c;
            scanf("%d", &c);
            for(int j = 0; j < c; ++j)
            {
                int buf;
                scanf("%d", &buf);
                doubleG[i].push_back(buf - 1 + n);
                doubleG[i + n].push_back(buf - 1);
            }
        }
        std::cin >> s;
        --s;
        que.push(s);
        vis[s] = true;
        while(!que.empty())
        {
            auto cur = que.front();
            que.pop();
            for(const auto &c: doubleG[cur])
            {
                if(!vis[c])
                {
                    que.push(c);
                    last[c] = cur;
                    vis[c]  = true;
                }
            }
        }
        if([&]() -> bool {
               for(int i = n; i < 2 * n; ++i)
               {
                   if(vis[i] && doubleG[i].size() == 0)
                   {
                       int             cur = i;
                       std::stack<int> stc;
                       while(cur != s)
                       {
                           stc.push(cur % n + 1);
                           cur = last[cur];
                       }
                       stc.push(s + 1);
                       //    std::cout << "Win" << std::endl;
                       printf("Win\n");
                       while(!stc.empty())
                       {
                           printf("%d", stc.top());
                           stc.pop();
                           if(!stc.empty())
                           {
                               printf(" ");
                           }
                           else
                           {
                               printf("\n");
                           }
                       }
                       return true;
                   }
               }
               return false;
           }())
        {}
        else if(circle(doubleG, s))
        {
            std::cout << "Draw" << std::endl;
        }
        else
        {
            std::cout << "Lose" << std::endl;
        }
    }
}