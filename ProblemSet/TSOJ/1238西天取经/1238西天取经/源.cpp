#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
long n, k, max, bufer, sum;
long MAX(long a, long b)
{
    return a > b ? a : b;
}
int main(void)
{
    while(scanf("%ld", &n) != EOF)
    {
        sum = 0;
        for(size_t i = 0; i < n; i++)
        {
            scanf("%ld", &k);
            max = 0;
            for(size_t i = 0; i < k; i++)
            {
                scanf("%ld", &bufer);
                max = MAX(max, bufer);
            }
            sum += max;
        }
        printf("%ld\n", sum);
    }
    return 0;
}
