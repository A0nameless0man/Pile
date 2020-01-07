#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int d = 0, a = 0, b = 0, x = 0, y = 0;
    scanf("%d", &d);
    for(size_t i = 0; i < d; i++)
    {
        scanf("%d%d", &a, &b);
        x = a;
        y = b;
        while(a != 0 && b != 0)
        {
            a %= b;
            if(a == 0)
            {
                break;
            }
            b %= a;
        }

        printf("%d\n", x * y / (a == 0 ? b : a));
    }
}