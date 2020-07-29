#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            int n, p;
            int sum = 0;
            int ans = 0;
            std::cin >> n >> p;
            std::vector<int> prefix;
            std::vector<int> lastpos(p, -1);
            std::vector<std::tuple<int, int>> pairs;
            lastpos[0] = 0;
            for(int i = 0; i < n; ++i)
            {
                int a;
                std::cin >> a;
                sum += a;
                sum %= p;
                if(lastpos[sum] != -1)
                {
#ifdef DEBUG
                    std::cout << "got: { " << lastpos[sum]
                              << " , " << i + 1
                              << " } val: " << sum
                              << std::endl;
#endif  // DEBUG
                    pairs.push_back(
                      std::make_tuple(lastpos[sum], i + 1));
                }
                lastpos[sum] = i + 1;
            }
            std::priority_queue<
              std::tuple<int, int>,
              std::vector<std::tuple<int, int>>,
              std::greater<std::tuple<int, int>>>
              que;
            for(size_t i = 0; i < pairs.size(); ++i)
            {
                que.push(
                  std::make_tuple(std::get<1>(pairs[i]),
                                  std::get<0>(pairs[i])));
            }
            {
                int curpos = 0;
                while(!que.empty())
                {
                    while(!que.empty()
                          && std::get<1>(que.top())
                               < curpos)
                    {
                        que.pop();
                    }
                    // if(std::get<0>(pairs[i]) >= curpos)
                    if(!que.empty())
                    {
                        ++ans;
                        curpos = std::get<0>(que.top());
#ifdef DEBUG
                        std::cout << "match: { "
                                  << std::get<1>(que.top())
                                  << " , "
                                  << std::get<0>(que.top())
                                  << std::endl;
#endif  // DEBUG
                        que.pop();
                    }
                }
            }
            std::cout << ans << std::endl;
        }
    }
}
/*
3
5 3
2 1 3 2 1
3 1
123 456 789
6 3
1 2 1 3 2 1
*/