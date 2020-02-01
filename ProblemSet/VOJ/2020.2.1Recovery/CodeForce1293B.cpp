#include<iomanip>
#include<iostream>

int main(void)
{
    int n;
    while(std::cin>>n)
    {
        long double sum = 0;
        for(int i = 1; i <= n;++i)
        {
            sum += 1.0 / i;
        }
        std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << sum << std::endl;
    }
}