#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>

using LL = long long;

LL qur(const LL &a)
{
    return a * a;
}

LL dis(const std::tuple<LL, LL> &lop,
       const std::tuple<LL, LL> &rop)
{
    return qur(std::get<0>(lop) - std::get<0>(rop))
           + qur(std::get<1>(lop) - std::get<1>(rop));
}

int main(void)
{
    int T;
    std::cin.sync_with_stdio(false);
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            int n;
            std::cin >> n;
            std::vector<std::tuple<LL, LL>>       vec;
            std::vector<std::tuple<LL, int, int>> map;
            std::vector<LL>                       vis(n, 0);
            for(int i = 0; i < n; i++)
            {
                LL x, y;
                std::cin >> x >> y;
                vec.push_back(std::make_tuple(x, y));
            }
            {
                // std::map<LL,
                //          std::vector<std::tuple<int,
                //          int>>>
                //   map;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < i; j++)
                    {
                        // map[dis(vec[i],
                        // vec[j])].push_back(
                        //   std::make_tuple(i, j));
                        map.push_back(std::make_tuple(
                          dis(vec[i], vec[j]),
                          i,
                          j));
                    }
                }
                std::sort(map.rbegin(), map.rend());
#ifdef DEBUG
                {
                    std::cout << "map[] : \n";
                    for(auto tp: map)
                    {
                        std::cout << std::get<0>(tp) << " "
                                  << std::get<1>(tp) << " "
                                  << std::get<2>(tp)
                                  << "\n";
                    }
                }
#endif  // DEBUG
                std::vector<int> set;
                LL               curdis = 0;
                for(auto tp: map)
                {
                    if(curdis != std::get<0>(tp))
                    {
                        for(auto p: set)
                        {
                            vis[p] = curdis;
                        }
                        set.clear();
                        curdis = std::get<0>(tp);
                    }
                    if(!vis[std::get<1>(tp)]
                       && !vis[std::get<2>(tp)])
                    {
                        set.push_back(std::get<1>(tp));
                        set.push_back(std::get<2>(tp));
                    }
                }
                for(auto p: set)
                {
                    vis[p] = curdis;
                }
            }
#ifdef DEBUG
            {
                std::cout << "vis[] : ";
                for(auto i: vis)
                {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
            }
#endif  // DEBUG
            if(vis[0])
            {
                std::cout << "YES\n";
            }
            else
            {
                std::cout << "NO\n";
            }
        }
    }
}