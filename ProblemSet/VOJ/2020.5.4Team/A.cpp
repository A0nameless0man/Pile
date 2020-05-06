#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main(void)
{
    int n, m;
    while(std::cin >> n >> m)
    {
        std::vector<int>             in, out;
        std::unordered_map<int, int> map;
        for(int i = 0; i < n; ++i)
        {
            int buf;
            std::cin >> buf;
            in.push_back(buf);
        }
        for(int i = 0; i < m; ++i)
        {
            int buf;
            std::cin >> buf;
            out.push_back(buf);
        }
        for(auto &i: in)
        {
            for(auto &j: out)
            {
                if(j >= i)
                {
                    ++map[j - i];
                }
            }
        }
        {
            int best_dt  = 0x7fffffff;
            int best_cnt = 0;
            for(auto &it: map)
            {
                if(it.second > best_cnt || (it.second == best_cnt && it.first < best_dt))
                {
                    best_dt  = it.first;
                    best_cnt = it.second;
                }
            }
            std::cout << best_dt;
        }
    }
}