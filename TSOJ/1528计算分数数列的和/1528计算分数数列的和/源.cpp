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
    double sum;
    int    n, a = 1, b = 2, j;
    while(scanf("%d", &n) != EOF)
    {
        a   = 1;
        b   = 2;
        sum = 0;
        j   = 0;
        while(n-- != 0)
        {
            if(j++ % 2 == 0)
            {
                sum += (float) b / a;
            }
            else
            {
                sum -= (float) b / a;
            }
            a += b;
            swap(a, b);
        }
        printf("%.4f\n", sum);
    }
    return 0;
}