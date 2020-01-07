#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void swap(int &a, int &b)
{
    int t = a;
    a     = b;
    b     = t;
}
int main(void)
{
    int a, b, n, j;
    while(scanf("%d", &n) != EOF)
    {
        a = 1;
        b = 1;
        j = 0;
        printf("%12d", a);
        j++;
        for(size_t i = 1; i < n; i++)
        {
            printf("%12d", b);
            j++;
            a += b;
            swap(a, b);
            if(j % 4 == 0)
            {
                putchar('\n');
            }
        }
        if(j % 4 != 0)
        {
            putchar('\n');
        }
    }
    return 0;
}