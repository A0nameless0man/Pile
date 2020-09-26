#include <cmath>
// #include <iostream>
#include <cstdio>
using lf = long double;

const lf PI  = acos(-1.0);
const lf EPS = 1e-10;

lf V(lf a1)
{
    lf sina1 = sin(a1);
    lf cosa1 = cos(a1);

    return 2
           * ((PI - a1) * cosa1 + sina1
              - sina1 * sina1 * sina1 / 3)
           / (cosa1 + 1);
}

lf S(lf a1)
{
    lf sina1 = sin(a1);
    lf cosa1 = cos(a1);
    return ((PI - a1 + cosa1 * sina1))
           * hypot(2, (cosa1 + 1)) / (cosa1 + 1);
}

lf solve(lf d)
{
    if(d < EPS)
    {
        return 0;
    }
    else if(d > 1.0)
    {
        return hypot(2 - d, 1) * PI;
    }
    else
    {
        lf v = d * PI;
        lf l = 0, r = PI;
        // while(r - l > EPS)
        for(int i = 0; i < 100; ++i)
        {
            lf mid  = (l + r) / 2;
            lf midv = V(mid);
            if(midv > v)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
#ifdef DEBUG
        printf("binary search get l = %Lf\n", l);
        printf("binary search get r = %Lf\n", r);
        printf("binary search get V(l) = %Lf\n", V(l));
        printf("binary search get V(r) = %Lf\n", V(r));
        printf(
          "binary search get hypot(1, (cos(a1) + 1) / 2) = "
          "%lf\n",
          hypot(1, (cos(l) + 1) / 2));
#endif  // DEBUG
        return S(l);
    }
}

int main(void)
{
    int T;
    while(scanf("%d", &T) != EOF)
    {
        for(int t = 0; t < T; ++t)
        {
            lf d;
            scanf("%Lf", &d);
#ifdef DEBUG
            printf("Read %Lf\n", d);
            // printf("%.15Lf\n", solve(d));
#endif  // DEBUG
            printf("%.5Lf\n", solve(d));
        }
    }
}