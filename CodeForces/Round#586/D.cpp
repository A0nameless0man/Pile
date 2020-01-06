#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
const int MAX_N = 200007;
long long input[MAX_N];
int       type[MAX_N];
int       typeCount[64];
long long lowbit(long long x)
{
    return x & (-x);
}
long long log2(long long n)
{
    long long l = 0, r = 64;
    while(l < r)
    {
        long long mid = (l + r) / 2;
        if((1ll << mid) < n)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}
int main(void)
{
    long long n;
    std::cin >> n;
    {
        for(int i = 0; i < 64; i++)
            typeCount[i] = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &input[i]);
            type[i] = log2(lowbit(input[i]));
            ++typeCount[type[i]];
        }
        int ans = 0, pos = 0;
        for(int i = 0; i < 64; i++)
        {
            if(ans < typeCount[i])
            {
                ans = typeCount[i];
                pos = i;
            }
        }
        std::cout << n - ans << std::endl;
        for(int i = 0; i < n; i++)
        {
            if(type[i] != pos)
                printf("%lld\n", input[i]);
        }
    }
    return 0;
}