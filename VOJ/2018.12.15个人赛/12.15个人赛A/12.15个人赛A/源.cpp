#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int n, k;
    int buffer;
    int pocketneeded;
    while(scanf("%d%d", &n, &k) != EOF)
    {
        pocketneeded = 0;
        for(size_t i = 0; i < n; i++)
        {
            scanf("%d", &buffer);
            pocketneeded += (buffer % k == 0) ? buffer / k : buffer / k + 1;
        }
        printf("%d\n", (pocketneeded) % 2 == 0 ? pocketneeded / 2 : pocketneeded / 2 + 1);
    }
    return 0;
}