#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    unsigned int a = 0, b = 0, n = 0;
    int          out = 0;
    char         c   = '\0';
    while(scanf("%d", &n) != EOF)
    {
        for(; n > 0; n--)
        {
            scanf("%u%c%u", &a, &c, &b);
            switch(c)
            {
                case '+':
                    out = a + b;
                    break;
                case '-':
                    out = (int) a - (int) b;
                    break;
                case '*':
                    out = a * b;
                    break;
                case '/':
                    out = a / b;
                    break;
                default:
                    break;
            }
            printf("%d\n", out);
        }
    }
}