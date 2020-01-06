#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    int a, b, n, sum;
    while(scanf("%d%d", &a, &n) != EOF)
    {
        sum = 0;
        b   = 0;
        for(size_t i = 0; i < n; i++)
        {
            b = 10 * b + a;
            sum += b;
        }
        printf("%d\n", sum);
    }
    return 0;
}
