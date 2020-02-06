#include <iostream>

int main(void)
{
    long long t, s, x;
    while(std::cin >> t >> s >> x)
    {
        if(x == t ||( x >= t+s && (((x - t) % s == 0) || ((x - 1 - t) % s == 0))))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }
}