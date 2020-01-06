#include <algorithm>
#include <iostream>
typedef long long LL;
int               main(void)
{
    LL n, m;
    while(std::cin >> n >> m)
    {
        LL s = n;
        LL i = 0;
        while(s > 0)
        {
            i++;
            s = std::min(s + m, n);
            s -= i;
        }
        std::cout << i << std::endl;
    }
}
