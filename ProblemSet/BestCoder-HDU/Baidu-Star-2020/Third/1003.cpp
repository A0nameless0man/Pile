#include <cstdio>
#include <iostream>
int main(void)
{
    int t;
    while(std::cin >> t)
    {
        for(int caseid = 0; caseid < t; ++caseid)
        {
            // double x;
            long long n, m;
            std::cin >> n >> m;
            if(m >= n / 2)
            {
                m = n / 2;
            }
            // if(m)
            //     std::cout << (2 * n - 2 - m) * (m + 1) /
            //     2
            //               << std::endl;
            // else
            //     std::cout << 0 << std::endl;
            printf("%lld\n",
                   m ? ((2 * n - 1 - 2 * m) * (2 * m) / 2)
                     : 0LL);
        }
    }
}