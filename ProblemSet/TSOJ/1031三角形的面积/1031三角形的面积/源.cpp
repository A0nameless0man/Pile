#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
int main(void)
{
    double a, b, c, p;
    while(scanf("%lf%lf%lf", &a, &b, &c) != EOF)
    {
        p = (a + b + c) / 2.0;
        if(a + b > c && b + c > a && a + c > b && a > 0 && b > 0 && c > 0)
        {
            printf("%.2f\n", sqrt(p * (p - a) * (p - b) * (p - c)));
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}