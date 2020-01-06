#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
bool IsPrime(long long int input)
{
    for(size_t i = 2; i <= 0.5 + sqrt(input); i++)
    {
        if((input % i) == 0)
        {
            /*-利用求余和循环判断是否是素数-*/
            return false;
        }
    }
    return true;
}
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
        if(IsPrime(n) && IsPrime(_n))
        {
            puts("1");
        }
        else
        {
            puts("0");
        }
    }
    return 0;
}
