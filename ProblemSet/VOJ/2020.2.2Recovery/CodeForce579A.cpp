#include<iostream>
int main(void)
{
    long long x;
    while(std::cin>>x)
    {
        int sum = 0;
        while(x)
        {
            sum += x & 1;
            x >>= 1;
        }
        std::cout << sum << std::endl;
    }
}