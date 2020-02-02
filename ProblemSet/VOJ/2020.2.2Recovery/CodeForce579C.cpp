#include <cmath>
#include <iomanip>
#include <iostream>

const long double pcs = 1e-18;

int main(void)
{
    int x, y;
    while(std::cin >> x >> y)
    {
        if(y > x)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            long long sum = x + y;
            long long k   = sum / (2 * y);
            // std::cout << sum << "v" << k << std::endl;
            std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
                      << static_cast<long double>(sum) / (2 * k) << std::endl;
        }
    }
}