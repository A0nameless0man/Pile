#include <iostream>
int jos(int n, int k)
{
    if(n)
    {
        return (jos(n - 1, k) + k - 1) % n + 1;
    }
    else
    {
        return 1;
    }
}
int main(void)
{
    int n, k;
    while(std::cin >> n >> k)
    {
        std::cout << jos(n, k) << std::endl;
    }
    return 0;
}