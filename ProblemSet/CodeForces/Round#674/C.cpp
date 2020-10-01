#include <algorithm>
#include <iostream>
int main()
{
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            int n;
            if(std::cin >> n)
            {
                int ans = 0x7fffffff;
                for(int i = 0; i * i < n; ++i)
                {
                    int j = (n - 1) / (i + 1);
                    ans   = std::min(ans, i + j);
                }
                std::cout << ans << "\n";
            }
        }
    }
}