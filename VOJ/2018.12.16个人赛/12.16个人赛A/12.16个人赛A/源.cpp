#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
inline int max(register int a, register int b)
{
    return a > b ? a : b;
}
inline int max_root(register int a, register int b)
{
    register int t;
    while(b != 0)
    {
        a = a % b;
        t = b;
        b = a;
        a = t;
    }
    return a;
}
int main(void)
{
    int a, b, c, d;

    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF)
    {
        if(a == c)
        {
            printf("%d\n", a);
        }
        else
        {
            int root = max_root(b, d);
            int mul  = b * d / root;
            for(size_t i = max(a, c); i < a + c + mul; i++)
            {
                if((i - a) % b == 0 && (i - c) % d == 0)
                {
                    printf("%d\n", i);
                    break;
                }
                if(i == a + c + mul - 1)
                {
                    printf("-1\n");
                }
            }
        }
    }
    return 0;
}
