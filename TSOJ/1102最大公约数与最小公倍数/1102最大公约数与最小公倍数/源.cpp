#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int m, n = 0, a = 0, b = 0;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        a = m;
        b = n;
        while(a != 0 && b != 0)
        {
            a %= b;
            if(a == 0)
            {
                break;
            }
            b %= a;
        }

        printf("%d\n%d\n", a == 0 ? b : a, m * n / (a == 0 ? b : a));
    }
}