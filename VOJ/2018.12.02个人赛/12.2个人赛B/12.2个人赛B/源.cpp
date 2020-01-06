#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
struct dot
{
    int x;
    int y;
};
double min(double a, double b)
{
    return a < b ? a : b;
}
const int MAX_N = 1007;
dot       p[MAX_N];
int       main(void)
{
    int    n;
    double r = 10e30;
    scanf("%d", &n);
    for(size_t i = 0; i < n; i++)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    for(size_t i = 1; i <= n; i++)
    {
        r = min(r,
                (((p[i - 1].x - p[(i + 1) % n].x) * (p[i].y - p[(i + 1) % n].y)) -
                 ((p[i - 1].y - p[(i + 1) % n].y) * (p[i].x - p[(i + 1) % n].x))) /
                  sqrt(((p[i - 1].x - p[(i + 1) % n].x)) * ((p[i - 1].x - p[(i + 1) % n].x)) +
                       ((p[i - 1].y - p[(i + 1) % n].y)) * ((p[i - 1].y - p[(i + 1) % n].y))));
    }
    printf("%f", r / 2.0);
}