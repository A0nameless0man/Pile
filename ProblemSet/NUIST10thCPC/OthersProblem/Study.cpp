#include <array>
#include <iostream>
/*
Time: 2020-04-04 16:28:24
Describe: Solve of P1636 idyllic的书房
Statue: Accepted
*/
int main(void)
{
    int m, n;
    while(std::cin >> n >> m)
    {
        std::array<int, 1000> ary = { 0 };
        for(int i = 0; i < n; ++i)
        {
            int last = 1;
            for(int j = 0; j < m; ++j)
            {
                int buf;
                std::cin >> buf;
                if(buf != last)
                {
                    ary[j] = 1;
                    last   = buf;
                }
            }
        }
        ary[0] = 1;
        for(int i = 1; i < m; ++i)
        {
            ary[i] += ary[i - 1];
        }
        for(int i = 0; i < m; ++i)
        {
            std::cout << ary[i];
        }
        std::cout << std::endl;
    }
}