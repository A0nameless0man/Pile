#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int a, b, m, n;
    while(scanf("%d%d", &m, &n) != EOF)
    {
        if(n % 2 == 0 && n / 2 >= m && n / 4 <= m && m > 0 && n > 0 && (n - 2 * m) % 2 == 0 &&
           (4 * m - n) % 2 == 0 && n >= 2 * m && 4 * m >= n)
        {
            n /= 2;
            b = n - m;
            a = m - b;
        }
        else
        {
            a = b = -1;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}