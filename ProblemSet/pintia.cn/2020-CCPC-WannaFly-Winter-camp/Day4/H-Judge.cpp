#include <cmath>
#include <iostream>
long long square(long long i)
{
    return i * i;
}

long double dis(long double i[3])
{
    return sqrt(square(i[0]) + square(i[1]) + square(i[2]));
}

int main(void)
{
    long long   i[3][3];
    long double k[3][3];
    long double dif[3][3];
    long double d[3];
    while(true)
    {
        for(int m = 0; m < 3; m++)
        {
            for(int n = 0; n < 3; ++n)
            {
                std::cin >> i[m][n];
            }
            for(int n = 0; n < 3; ++n)
            {
                k[m][n] = i[m][n] / sqrt(square(i[m][0]) + square(i[m][1]) + square(i[m][2]));
                std::cout << k[m][n] << " ";
            }
            std::cout << std::endl;
        }
        for(int m = 0; m < 3; m++)
        {
            for(int n = 0; n < 3; ++n)
            {
                dif[m][n] = k[m][n] - k[(m + 1) % 3][n];
            }
            d[m] = dis(dif[m]);
            std::cout << d[m] << " ";
        }
        std::cout << std::endl;
    }
}
/*
0 1 -1
100 -58 0
1000000 -577350 1
0 577350 -1
100 -58 0
1000000 -577350 1
0 1 0
1000000 577351 -1
1000000 -577350 1
0 1 0
1000000 -816496 1000000
-1000000 -816497 -1000000

*/