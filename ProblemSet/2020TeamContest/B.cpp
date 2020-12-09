#include <iostream>

int main()
{
    int        n, m;
    static int b[] = { 0, 6, 3, 0 };
    while(std::cin >> n >> m)
    {
        int ans = (n / 1000) * (1000 - 80 - 5 - 20 - 120) * 12
                  + n * b[m];
        if(ans < 100000)
        {
            std::cout << "GongWuYuan" << std::endl;
        }
        else
        {
            std::cout << ans << std::endl;
        }
    }
}