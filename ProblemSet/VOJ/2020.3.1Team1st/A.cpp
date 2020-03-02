// #include <iostream>
#include <cstdio>

using LL = long long;

const LL MOD = 1000000007;

LL pow(LL n)
{
    LL base = 2;
    LL ans  = 1;
    while(n)
    {
        if(n & 1)
        {
            ans *= base;
            ans %= MOD;
        }
        n >>= 1;
        base *= base;
        base %= MOD;
    }
    return ans;
}

int main(void)
{
    LL a, b, k, c;
    // while(std::cin >> a >> b >> k >> c)
    while(scanf("%lld%lld%lld%lld", &a, &b, &k, &c) != EOF)
    {
        if(a == b && b == c)
        {
            // std::cout << (pow(k) * k) % MOD << std::endl;
            printf("%lld\n", (pow(k) * k) % MOD);
        }
        else if(a != b && (a == c || b == c))
        {
            // std::cout << (pow(k - 1) * k) % MOD << std::endl;
            printf("%lld\n", (pow(k-1) * k) % MOD);
        }
        else
        {
            // std::cout << 0 << std::endl;
            printf("0\n");
        }
    }
    return 0;
}