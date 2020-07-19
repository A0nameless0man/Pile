#include <iostream>
#include <tuple>
#include <vector>

const int X = 0;
const int Y = 1;

int main(void)
{
    int t;
    while(std::cin >> t)
    {
        for(int i = 0; i < t; ++i)
        {
            int n, m, ans;
            ans = 0x7fffffff;
            std::cin >> n >> m;
            // std::vector<std::tuple<int, int> > drinks;
            for(int i = 0; i < n; ++i)
            {
                int x, y;
                std::cin >> x >> y;
                int cnt = (m - 1) / x + 1;
                int cal = cnt * y;
                if(cal < ans)
                {
                    ans = cal;
                }
            }
            std::cout << ans << std::endl;
        }
    }
}