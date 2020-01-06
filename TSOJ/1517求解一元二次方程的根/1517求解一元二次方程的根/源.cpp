#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    double a, b, c, d;
    // printf("%5d\n%5d\n%5f\n%5f", -0,0, -0.0-0.0, 0.0-0.0);
    while(scanf("%lf%lf%lf", &a, &b, &c) != EOF)
    {
        if(a + 0.0 == 0.0)
        {
            printf("不是一元二次方程\n");
        }
        else
        {
            if((d = pow(b, 2) - 4 * a * c) >= 0)
            {
                d = sqrt(d);
                printf("%.2f %.2f\n", -(b - d) / 2 / a + 0.0, -(b + d) / 2 / a + 0.0);
            }
            else
            {
                d = sqrt(-d);
                printf("%.2f+%.2fi %.2f-%.2fi\n",
                       -b / 2 / a + 0.0,
                       d / 2 / a + 0.0,
                       -b / 2 / a + 0.0,
                       d / 2 / a + 0.0);
            }
        }
    }
    return 0;
}
