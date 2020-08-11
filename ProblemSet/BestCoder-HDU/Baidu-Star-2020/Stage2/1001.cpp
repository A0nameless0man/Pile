#include <iostream>

const long long MOD      = 998244353;
int             rev[101] = { 0 };

int getRev(long long i)
{
    long long pow = 998244351;
    long long ans = 1;
    while(pow)
    {
        if(pow & 1)
        {
            ans = ans * i % MOD;
        }
        i = i * i % MOD;
        pow >>= 1;
    }
    return static_cast<int>(ans);
}

int main(void)
{
    for(long long i = 1; i <= 100; ++i)
    {
        rev[i] = getRev(i);
#ifdef DEBUG
        std::cout << i << " " << rev[i] << " "
                  << static_cast<long long>(i) * rev[i]
                       % MOD
                  << std::endl;
#endif  // DEBUG
    }
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            long long m, p, q;
            std::cin >> m >> p >> q;
            long long expround =
              m * rev[p] % MOD * 100 % MOD;
#ifdef DEBUG
            std::cout << expround << std::endl;
#endif  // DEBUG
            std::cout << (((expround - 1) * (MOD - q) % MOD
                             * rev[100] % MOD
                           + m)
                          % MOD)
                      << std::endl;
        }
    }
}