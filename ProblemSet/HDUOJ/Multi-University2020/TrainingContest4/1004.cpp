#include <cstdio>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
const int MAX_N = 100007;
using LL        = long long;
char str[MAX_N];
int  main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int cc = 0; cc < T; ++cc)
        {
            LL n, m, s, t, x;
            std::cin >> n >> m >> s >> t >> x;
            --s;
            --t;
            std::vector<std::vector<std::tuple<LL, LL>>>
                            edges(n * 2);
            std::vector<LL> dis(n * 2, 0x3f3f3f3f3f3f);
            scanf("%s", str);
            for(LL i = 0; i < n; ++i)
            {
                if(str[i] == 'M')
                {
                    str[i] = 3;
                }
                else if(str[i] == 'L')
                {
                    str[i] = 1;
                }
                else
                {
                    str[i] = 2;
                }
            }
            for(LL i = 0; i < m; ++i)
            {
                LL a, b, d;
                scanf("%lld%lld%lld", &a, &b, &d);
                // std::cin >> a >> b >> d;
                --a;
                --b;
                for(int j = 0; j < 2; ++j)
                {
                    if(str[a] & (1 << j))
                    {
                        for(int k = 0; k < 2; ++k)
                        {
                            if(str[b] & (1 << k))
                            {
                                edges[a + n * j].push_back(
                                  std::make_tuple(
                                    b + n * k,
                                    d
                                      + ((j == k) ? 0
                                                  : x)));
                                edges[b + n * k].push_back(
                                  std::make_tuple(
                                    a + n * j,
                                    d
                                      + ((j == k) ? 0
                                                  : x)));
                            }
                        }
                    }
                }
            }
            {
                std::priority_queue<
                  std::tuple<LL, LL>,
                  std::vector<std::tuple<LL, LL>>,
                  std::greater<std::tuple<int, int>>>
                  que;
                for(int i = 0; i < 2; ++i)
                {
                    if(str[s] & (1 << i))
                    {
                        que.push(
                          std::make_tuple(0, s + n * i));
                    }
                }
                while(!que.empty())
                {
                    auto cur = que.top();
#ifdef DEBUG
                    std::cout << "#--------cur at "
                              << std::get<1>(cur)
                              << " ---------- val "
                              << std::get<0>(cur)
                              << std::endl;
#endif  // DEBUG
                    que.pop();
                    for(size_t i = 0;
                        i < edges[std::get<1>(cur)].size();
                        ++i)
                    {
                        auto  curp     = std::get<1>(cur);
                        auto  curd     = std::get<0>(cur);
                        auto &edge     = edges[curp][i];
                        auto  dist     = std::get<0>(edge);
                        auto  distance = std::get<1>(edge);
                        if(curd + distance < dis[dist])
                        {
                            dis[dist] = curd + distance;
                            que.push(std::make_tuple(
                              curd + distance,
                              dist));
#ifdef DEBUG
                            std::cout << "push" << dist
                                      << " val "
                                      << curd + distance
                                      << std::endl;
#endif  // DEBUG
                        }
                    }
                }
            }

            {
                LL ans = 0x3f3f3f3f3f3f;
                for(int i = 0; i < 2; ++i)
                {
                    if(str[t] & (1 << i))
                    {
                        ans = std::min(ans, dis[t + n * i]);
                    }
                }
                std::cout << ans << "\n";
            }
        }
    }
}