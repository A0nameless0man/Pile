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
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            int n;
            std::cin >> n;
            std::vector<std::tuple<LL, LL>> vec;
            std::vector<LL>                 vis(n, 0);
            for(int i = 0; i < n; i++)
            {
                LL x, y;
                std::cin >> x >> y;
                vec.push_back(std::make_tuple(x, y));
            }
            {
                std::map<LL,
                         std::vector<std::tuple<int, int>>>
                  map;
                std::map<LL,
                         std::vector<std::tuple<int, int>>>
                  map2;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < i; j++)
                    {
                        map[dis(vec[i], vec[j])].push_back(
                          std::make_tuple(i, j));
                    }
                }
                for(auto it = map.rbegin();
                    it != map.rend();
                    ++it)
                {
                    auto &        curvec = it->second;
                    std::set<int> set;
                    for(auto tp: curvec)
                    {
                        if(!vis[std::get<0>(tp)]
                           && !vis[std::get<1>(tp)])
                        {
                            map2[it->first].push_back(tp);
                            set.insert(std::get<0>(tp));
                            set.insert(std::get<1>(tp));
                        }
                    }
                    for(auto p: set)
                    {
                        vis[p] = it->first;
                    }
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