#include <algorithm>
#include <cstdio>
int main(void)
{
    int T = 0;
    while(scanf("%d", &T) != EOF)
    {
        for(int t = 0; t < T; ++t)
        {
            int n, m, k;
            scanf("%d%d%d", &n, &m, &k);
            long long sum = 0;
            int min = 1e9 + 7;
            for(int i = 0; i < m; ++i)
            {
                int a;
                scanf("%d", &a);
                sum += abs(a - k);
                if(min > a)
                {
                    min = a;
                }
            }
            long long ans = 0;
            ans += sum;
            ans += sum;
            ans += k;
            ans -= 2;
            ans += min - abs(k - min);
#ifdef DEBUG
            printf("ans = %lld\n", ans);
            printf("min = %d\n", min);
            printf("sum = %d\n", sum);
#endif
            printf("%lld\n", ans);
        }
    }
}