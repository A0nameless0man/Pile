#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int n, _n, sum;
    while(scanf("%d", &n) != EOF)
    {
        sum = 0;
        _n  = 1;
        for(size_t i = 1; i <= n; i++)
        {
            _n *= i;
            sum += _n;
        }
        printf("%d\n", sum);
    }
    return 0;
}