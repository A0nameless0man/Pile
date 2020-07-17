#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

const double EPS = 0.00000000001;
using LL         = long long;
// using LLL = __int128;
struct P
{
    LL x, y;
};

// bool operator<(const P &lop, const P &rop)
// {
//     if(lop.x != rop.x)
//     {
//         return lop.x < rop.x;
//     }
//     else
//     {
//         return lop.y < rop.y;
//     }
// }

P operator-(const P &lop, const P &rop)
{
    return { lop.x - rop.x, lop.y - rop.y };
}

LL sqdis(const P &v)
{
    return v.x * v.x + v.y * v.y;
}

LL dot(const P &lop, const P &rop)
{
    return lop.x * rop.x + lop.y * rop.y;
}

LL det(const P &lop, const P &rop)
{
    return lop.y * rop.x - lop.x * rop.y;
}

LL sq(LL rop)
{
    if(rop > 0)
        return rop * rop;
    else
        return -rop * rop;
}

const P zero = { 0, 0 };

LL gcd(LL lop, LL rop)
{
    // if(lop == 0)
    // {
    //     return rop;
    // }
    // else
    // {
    //     return gcd(rop % lop, lop);
    // }
    while(lop)
    {
        LL tmp = lop;
        lop    = rop % lop;
        rop    = tmp;
    }
    return rop;
}

int main(void)
{
    LL n;
    while(std::cin >> n)
    {
        std::vector<P> points;
        points.reserve(n);
        for(LL i = 0; i < n; ++i)
        {
            LL x, y;
            // std::cin >> x >> y;
            scanf("%lld%lld", &x, &y);
            points.push_back({ x, y });
        }

        LL ans = 0;
        for(LL i = 0; i < n; ++i)
        {
            P                    p = points[i];
            std::map<double, LL> bucket;
            // std::unordered_map<LL, LL> bucket;
            for(LL j = 0; j < n; ++j)
            {
                if(j != i)
                {
                    P a     = points[j];
                    P pa    = p - a;
                    P azero = a;
#ifdef DEBUG
                    // std::cout << "curr p : ( " << p.x << " : " << p.y << " )" << std::endl;
                    // std::cout << "curr a : ( " << a.x << " : " << a.y << " )" << std::endl;
                    // std::cout << "det(a,p)" << det(a, p) << std::endl;
                    // std::cout << std::endl;
#endif  // DEBUG
                    if(det(a, p) < 0)
                    {
                        LL up   = sq(dot(pa, azero));
                        LL down = sqdis(pa) * sqdis(azero);
                        // LL     gc    = gcd(std::abs(up), down);
                        double angle = static_cast<double>(up) / down;
                        // ++bucket[up * 1000000 / down];
                        // if(bucket.lower_bound(angle))
                        auto itp = bucket.equal_range(angle);
#ifdef DEBUG
                        std::cout << "angle " << angle << " [" << itp.first->first << " , "
                                  << itp.second->first << " ]" << std::endl;
#endif  // DEBUG

                        if(itp.first != bucket.end() && std::abs(angle - itp.first->first) < EPS)
                        {
                            ++(itp.first->second);
                        }
                        else if(itp.second != bucket.end()
                                && std::abs(itp.second->first - angle) < EPS)
                        {
                            ++(itp.second->second);
                        }
                        else
                        {
                            ++(bucket[angle]);
                        }

                        // ++bucket[(up / gc) * 998244353 + down / gc];
                    }
                }
            }
#ifdef DEBUG
            // std::cout << "cur p : ( " << p.x << " : " << p.y << " )" << std::endl;
            // std::cout << std::endl;
#endif  // DEBUG
        // for(auto it: bucket)
            for(auto i = bucket.begin(); i != bucket.end(); ++i)
            {
                // auto it = *i;
#ifdef DEBUG
                std::cout << "angle : " << i->first << std::endl;
                std::cout << "point : " << i->second << std::endl;
                std::cout << std::endl;
#endif  // DEBUG
                if(i->second > ans)
                {
                    ans = i->second;
                }
            }
        }
        std::cout << ans + 1 << std::endl;
    }
}