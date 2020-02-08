#include <iostream>
int main(void)
{
    long long n, q;
    while(std::cin >> n >> q)
    {
        for(long long i = 0; i < q; i++)
        {
            long long x;
            // std::cin >> x;
            scanf("%lld", &x);
            while(x % 2 == 0)
            {
                x = n + x / 2;
            }
            // std::cout << (x + 1) / 2 << std::endl;
            printf("%lld\n", (x + 1) / 2);
        }
    }
}
/*
1+2+3+4+5+6
1+2+3+4+56
1+2+3+465
1+2+3564
the ith move,move (2*n-i) to 2*(n-i)th pos
x = 2*(n-i)
n-i = x/2
i = n-x/2
(2*n-i)=n+x/2
*/
/*
1 2 3 4
1 2 34
1 243
1324
x = 2
(n-i)=1
i = 3
(2*n-i)=5
n+x/2 = 5
*/
