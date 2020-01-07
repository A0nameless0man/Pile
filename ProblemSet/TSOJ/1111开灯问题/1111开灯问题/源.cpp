#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
const int MAX_N = 100007;
bool      lanmps[MAX_N];
int       n, k;
int       main(void)
{
    while(scanf("%d%d", &n, &k) != EOF)  // n’µµ∆£¨k∏ˆ»À
    {
        for(int i = 0; i <= n; i++)
        {
            lanmps[i] = true;
        }
        for(int i = 2; i <= k; i++)
        {
            int j = i;
            while(j <= n)
            {
                lanmps[j] = !lanmps[j];
                j += i;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(lanmps[i])
            {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
