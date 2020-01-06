#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N[120000] = { 0 }, n = 0, m = 0;
int main(void)
{
    scanf("%d%d", &n, &m);
    for(size_t i = 0; i < n; i++)
    {
        scanf("%d", N + i);
    }
    int a = 0, b = 0;
    int sum = 0;
    while(b < n)
    {
        while(sum + N[b] <= m && b < n)
        {
            sum += N[b];
            b++;
        }
        a++;
        sum = 0;
    }
    printf("%d", a);
}