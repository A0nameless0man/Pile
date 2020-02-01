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
            if(std::max(a, std::max(b, c)) * 2 - (a + b + c) > n || (a + b + c + n) % 3 != 0)
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