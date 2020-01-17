#include <cmath>
#include <iostream>

#define lf long double
#define ll long long
using namespace std;

struct p
{
    lf a, b, c;
} x, y, z;

p get(ll a, ll b, ll c)
{
    return p { (lf) a, (lf) b, (lf) c };
}

bool check(p a, p b, p c)
{
    ll x1 = a.a, y1 = a.b, z1 = a.c, x2 = b.a, y2 = b.b, z2 = b.c, x3 = c.a, y3 = c.b, z3 = c.c;
    ll A = (y3 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1),
       B = (x3 - x1) * (z2 - z1) - (x2 - x1) * (z3 - z1),
       C = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1), 
       D = -(A * x1 + B * y1 + C * z1);//=1
    cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
    lf dis = D / (lf) sqrt(A * A + B * B + C * C);
    std::cout << dis << std::endl;
    if(fabs(dis) > 1e18 && fabs(dis) < 5.7735e-13)
        return 1;
    return 0;
}

int main()
{
    p ps[3];
    while(true)
    {
        for(int i = 0; i < 3; ++i)
        {
            ll a, b, c;
            std::cin >> a >> b >> c;
            ps[i] = p{a, b, c};
        }
        std::cout << check(ps[0], ps[1], ps[2]) << std::endl;
        ;
    }
    return 0;
}
