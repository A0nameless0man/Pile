#include <algorithm>
#include <iostream>
#include <vector>
int main(void)
{
    int t;
    while(std::cin >> t)
    {
        for(int i = 0; i < t; ++i)
        {
            long long a, b, c, n;
            std::cin >> a >> b >> c >> n;
            long long ans = (a + b + c + n) / 3;
            long long sum = ans * 3;
            // std::cout << ans << " " << sum << std::endl;
            if(ans < a || ans < b || ans < c || sum != (a + b + c + n))
            {
                std::cout << "NO" << std::endl;
            }
            else
            {
                std::cout << "YES" << std::endl;
            }
        }
    }
    return 0;
}