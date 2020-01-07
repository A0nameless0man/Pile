#include <cmath>
#include <iomanip>
#include <iostream>
int main(void)
{
    std::cout.precision(15);
    int t;
    std::cin >> t;
    while(t--)
    {
        long double a, b, r, d;
        std::cin >> a >> b >> r >> d;
        d = d / 360.0 * acosl(-1.0) * 2.0;
        if(d > atanl((b) / (a + r)))
        {
            // std::cout<<atanl((b)/(a+r))/(acosl(-1.0)*2.0)*360.0<<std::endl;
            std::cout << (sqrtl(powl(a + r, 2.0) + powl(b, 2.0)) - r) << std::endl;
        }
        else
        {
            long double x = atanl((b) / (a + r)) - d;
            std::cout << (sqrtl(powl(a + r, 2.0) + powl(b, 2.0)) - (r / cosl(x))) * cosl(x)
                      << std::endl;
        }
    }
    return 0;
}
/*
4
1 2 2 120
1 2 2 60
1 2 2 30
1 2 2 15
*/