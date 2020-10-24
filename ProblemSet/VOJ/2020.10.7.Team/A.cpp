#include <algorithm>
// #include <cstdio>
using LB = long double;

const int MAX_N = 101;

LB solve(int n, int m, int k)
{
    LB transfer[MAX_N][MAX_N];
    LB curstate[MAX_N];
    LB nextstate[MAX_N];
    LB C[MAX_N];
    LB fac[MAX_N];
    {
        LB p2 = 1;
        for(int i = 0; i < k; ++i)
        {
            p2 *= 0.5;
        }
        for(int i = 0; i <= k; ++i)
        {
            fac[i] = 1;
        }
        for(int i = 1; i <= k; ++i)
        {
            fac[i] = i * fac[i - 1];
        }
        for(int i = 0; i <= k; ++i)
        {
            C[i] = fac[k] / (fac[i] * fac[k - i]);
        }
        curstate[0] = 1.0;
        for(int i = 1; i <= n; ++i)
        {
            curstate[i] = 0.0;
        }
        for(int i = 0; i <= n; i++)
        {
            int low = std::min(i, n - k);
            for(int j = 0; j <= k; ++j)
            {
                int p          = j + low;
                transfer[i][p] = p2 * C[j];
            }
        }
    }
    for(int r = 0; r < m; ++r)
    {
        for(int i = 0; i <= n; i++)
        {
            nextstate[i] = 0.0;
        }
        for(int i = 0; i <= n; i++)
        {
            int low = std::min(i, n - k);
            for(int j = 0; j <= k; ++j)
            {
                int p = j + low;
                nextstate[p] +=
                  transfer[i][p] * curstate[i];
            }
        }
        for(int i = 0; i <= n; i++)
        {
            curstate[i] = nextstate[i];
        }
    }
    {
        LB ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            ans += i * curstate[i];
        }
        return ans;
    }
}

int main(void)
{
    int T;
    while(scanf("%d", &T) != EOF)
    {
        for(int t = 0; t < T; ++t)
        {
            int n, m, k;
            scanf("%d%d%d", &n, &m, &k);
            printf("%.3Lf\n", solve(n, m, k));
        }
    }
}