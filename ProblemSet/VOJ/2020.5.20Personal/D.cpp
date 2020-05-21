#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        std::vector<std::tuple<int, int>> vec;
        std::vector<std::tuple<int, int>> edges;
        std::vector<int>                  mainChain;

        for(int i = 0; i < n; ++i)
        {
            int buf;
            scanf("%d", &buf);
            vec.push_back(std::make_tuple(buf, i));
        }
        std::sort(vec.begin(), vec.end(), std::greater<std::tuple<int, int>>());
        mainChain.push_back(std::get<1>(vec[0]) * 2 + 1);
        for(int i = 1; i < n; ++i)
        {
            mainChain.push_back(std::get<1>(vec[i]) * 2 + 1);
            edges.push_back(std::make_tuple(mainChain[i], mainChain[i - 1]));
        }
        for(int i = 0; i < n; ++i)
        {
            int bubble = std::get<1>(vec[i]) * 2 + 2;
            int dis    = std::get<0>(vec[i]);
            edges.push_back(std::make_tuple(mainChain[dis + i - 1], bubble));
            if(dis + i == mainChain.size())
            {
                mainChain.push_back(bubble);
            }
        }
        for(const auto &t: edges)
        {
            printf("%d %d\n", std::get<0>(t), std::get<1>(t));
        }
    }
}