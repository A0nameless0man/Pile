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
    for(LL i = 0; i < MAX_N; ++i)
    {
        num[i] = qpow(i * i, mod - 2);
    }
    for(LL i = 2; i < MAX_N; ++i)
    {
        num[i] += num[i - 1];
        num[i] %= mod;
    }
    int T;
    while(scanf("%d", &T) != EOF)
    {
        for(int id = 0; id < T; ++id)
        {
            int n;
            scanf("%d", &n);
            printf("%lld\n",
                   (qpow(n, mod - 2) * num[n] * 3) % mod);
        }
    }
}