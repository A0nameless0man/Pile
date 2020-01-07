#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long int b, p, _p, k, mi[32] = { 0 }, r = 1;
int      t[32] = { 0 };
int      main(void)
{
    scanf("%ld%ld%ld", &b, &p, &k);
    _p = p;
    for(size_t i = 0; i < 32; i++)
    {
        t[i] = _p % 2;
        _p /= 2;
    }
    mi[0] = b;
    for(size_t i = 1; i < 32; i++)
    {
        mi[i] = (mi[i - 1] * mi[i - 1]) % k;
    }
    for(size_t i = 0; i < 32; i++)
    {
        if(t[i] == 1)
        {
            r *= mi[i];
            r %= k;
        }
    }
    printf("%ld^%ld mod %ld=%ld", b, p, k, r % k);
}