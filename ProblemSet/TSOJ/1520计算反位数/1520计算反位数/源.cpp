#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int n, _n;
    while(scanf("%d", &n) != EOF)
    {
        _n = 0;
        while(n != 0)
        {
            _n = n % 10 + _n * 10;
            n /= 10;
        }
        printf("%d\n", _n);
    }
    return 0;
}