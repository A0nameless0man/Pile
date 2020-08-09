#include <cstdio>
#include <iostream>
#include <tuple>
#include <vector>

int main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            int n;
            int sum = 0;
            int ans = 0;
            std::cin >> n;
            std::vector<std::tuple<int, int>> vec;
            for(int i = 0; i < n; ++i)
            {
                int a, d;
                std::cin >> a >> d;
                vec.push_back(std::make_tuple(a, d));
            }
            for(int i = 0; i < n; ++i)
            {
                sum = 0;
                for(int j = 0; j < n; ++j)
                {
                    int mea = std::get<0>(vec[i]);
                    int med = std::get<1>(vec[i]);
                    int fa  = std::get<0>(vec[j]);
                    int fd  = std::get<1>(vec[j]);
                    int mer = (99) / mea;
                    int fr  = (99) / fa;
                    int met = med * mer;
                    int ft  = fd * fr;
#ifdef DEBUG
                    printf(
                      "mea %5d med %5d mt %5d fa %5d fd "
                      "%5d ft %5d\n",
                      mea,
                      med,
                      met,
                      fr,
                      fd,
                      ft);
#endif  // DEBUG
                    if(met < ft)
                    {
                        sum += 2;
                    }
                    else if(met == ft)
                    {
                        sum += 1;
                    }
                }
                if(sum > ans)
                {
                    ans = sum;
                }
            }
            std::cout
              << static_cast<long double>(ans) / (2 * n)
              << std::endl;
        }
    }
}