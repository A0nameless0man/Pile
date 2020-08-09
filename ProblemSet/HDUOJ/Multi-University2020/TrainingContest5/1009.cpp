#include <cstdio>

using LL       = long long;
const LL mod   = 998244353;
const LL MAX_N = 6e6 + 7;

LL num[MAX_N];
LL qpow(LL a, LL b)
{
    a %= mod;
    LL ans = 1;
    while(b)
    {
        if(b & 1)
        {
            ans *= a;
            ans %= mod;
        }
        b >>= 1;
        a *= a;
        a %= mod;
    }
    return ans;
}

int main(void)
{

    int T;
    while(scanf("%d", &T) != EOF)
    {
        for(int id = 0; id < T; ++id)
        {
            LL n;
            scanf("%lld", &n);
            LL pow2 = qpow(2, n);
            LL pow3 = qpow(3, n);
#ifdef DEBUG
            printf("2^n %lld\n", pow2);
            printf("3^n %lld\n", pow3);
#endif  // DEBUG
            printf(
              "%lld\n",
              (1 + pow2 + 2 * pow3 * qpow(pow2, mod - 2))
                % mod);
        }
    }
}
