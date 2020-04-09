#include <cmath>
#include <cstdio>
#include <iostream>

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        double r, h, ans;
        for(int i = 0; i < n; ++i)
        {
            scanf("%lF%lF", &r, &h);
            h = std::max(h, -r);
            h = std::min(h, r);
            h = -h;

            // ans = (3 * r * r * h - h * h * h + 2 * r * r * r) / (4 * r * r * r);
            // ans *= 100;

            // ans = 25 * (3 * r * r * h - h * h * h + 2 * r * r * r) / (r * r * r);
            
            ans = 25 * ((3*h+2*r)*(r*r)-h*(h*h)) / (r * r * r);

            if(std::abs(ans) < 0.0001)
            {
                ans = 0;
            }
            printf("%.2lF%%\n", ans);
        }
    }
}
/*
V(h) = inf S dh
  = inf (r^2-h^2)*PI dh
  = PI r^2*h - 1/3 h^3 + 2/3 r^3

ans = V(h)/V(r)
    = (r^2*h - 1/3 h^3 + 2/3 r^3)/(4/3 r^3)
    = (3 r^2*h - h^3 + 2 r^3)/(4 r^3)


*/