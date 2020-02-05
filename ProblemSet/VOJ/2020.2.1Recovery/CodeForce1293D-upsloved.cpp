#include <algorithm>
#include <iostream>
#include <vector>

struct Point
{
    long long x, y;
};

long long dis(const Point &a, const Point &b)
{
    // std::cout << a.x << ":" << a.y << "<--->" << b.x << ":" << b.y << "==>"
    //           << std::abs(a.x - b.x) + std::abs(a.y - b.y) << std::endl;
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

Point operator*(const Point &a, const Point &b)
{
    return Point { a.x * b.x, a.y * b.y };
}

Point operator+(const Point &a, const Point &b)
{
    return Point { a.x + b.x, a.y + b.y };
}

bool operator<(const Point &a, const Point &b)
{
    return a.x < b.x && a.y < b.y;
}

template <typename OS>
OS &operator>>(OS &os, Point &p)
{
    return os >> p.x >> p.y;
}
int main(void)
{
    Point     _0, a, b, s;
    long long t;
    while(std::cin >> _0 >> a >> b >> s >> t)
    {
        std::vector<Point>     pvec;
        std::vector<long long> anses;
        pvec.push_back(_0);
        do
        {
            pvec.push_back(pvec[pvec.size() - 1] * a + b);
        } while(pvec[pvec.size() - 1] + b
                < Point { ((1ll << 62) - 1) / a.x, ((1ll << 62) - 1) / a.y });
        // std::cout << pvec.size() << std::endl;
        anses.resize(pvec.size());
        for(size_t i = 0; i < pvec.size(); ++i)
        {
            // std::cout << pvec[i].x << ":" << pvec[i].y << std::endl;
            if(t >= dis(s, pvec[i]))
            {
                long long disleft  = t - dis(s, pvec[i]);
                long long disrleft = disleft;
                long long ans = 1, rans = 1;
                for(size_t down = i - 1; ~down && disrleft >= dis(pvec[down], pvec[down + 1]);
                    --down)
                {
                    disrleft -= dis(pvec[down], pvec[down + 1]);
                    ++rans;
                }
                for(size_t up = i + 1; i < pvec.size() && disleft >= dis(pvec[up], pvec[up - 1]);
                    ++up)
                {
                    disleft -= dis(pvec[up], pvec[up - 1]);
                    ++ans;
                }
                anses[i] = std::max(ans, rans);
            }
        }
        std::cout << *std::max_element(anses.begin(), anses.end()) << std::endl;
    }
}
