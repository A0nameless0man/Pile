#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
const int MAX_N = 107;
struct Ball
{
    int head;
    int tail;
    int next;
};
int           n;
Ball          Chain[MAX_N];
long long int mem_DP[MAX_N][MAX_N];
void          ResetMEM(void)
{
    for(size_t i = 0; i < MAX_N; i++)
    {
        for(size_t j = 0; j < MAX_N; j++)
        {
            mem_DP[i][j] = -1;
        }
    }
}
inline long long int max(long long int a, long long int b)
{
    return a > b ? a : b;
}
long long int DP(int i, int j)
{
    if(i == j)
    {
        return 0;
    }
    else
    {
        if(mem_DP[i][j] != -1)
        {
            return mem_DP[i][j];
        }
        else
        {
            long long int r = 0;
            for(size_t k = i; k != j; k = Chain[k].next)
            {
                r = max(DP(i, k) + DP(Chain[k].next, j) +
                          Chain[i].head * Chain[k].tail * Chain[j].tail,
                        r);
            }
            return mem_DP[i][j] = r;
        }
    }
}
int main(void)
{
    freopen("testdata.in", "r", stdin);
    while(scanf("%d", &n) != EOF)
    {
        ResetMEM();
        for(size_t i = 0; i < n; i++)
        {
            scanf("%d", &Chain[i].head);
            Chain[i].next = i + 1;
            if(i != 0)
            {
                Chain[i - 1].tail = Chain[i].head;
            }
        }
        Chain[n - 1].tail    = Chain[0].head;
        Chain[n - 1].next    = 0;
        long long int Result = 0;
        for(size_t i = 0; i < n; i++)
        {
            Result = max(Result, DP(Chain[i].next, i));
        }
        printf("%lld\n", Result);
        return 0;
    }

    return 0;
}
