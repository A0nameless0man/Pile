#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

struct Point
{
    long double x;
    long double y;
};

long double det(const Point &lop, const Point &rop)
{
    return lop.x * rop.y - rop.x * lop.y;
}

Point operator-(const Point &lop, const Point &rop)
{
    return Point({ lop.x - rop.x, lop.y - rop.y });
}
long double dis(const Point &lop, const Point &rop)
{
    auto diff = lop - rop;
    return std::sqrt(diff.x * diff.x + diff.y * diff.y);
}
long double dis(const Point &lopa, const Point &lopb, const Point &rop)
{
    long double a = lopa.y - lopb.y;
    long double b = lopa.x - lopb.x;
    long double c = -det(lopa, lopb);
    return (c + a * rop.x + b * rop.y) / std::sqrt(a * a + b * b);
}
Point operator+(const Point &lop, const Point &rop)
{
    return Point({ lop.x + rop.x, lop.y + rop.y });
}

Point operator*(const Point &lop, const long double &rop)
{
    return Point({ lop.x * rop, lop.y * rop });
}

struct Ploy
{
    std::vector<Point> points;
    Ploy &             addPoint(const Point &p)
    {
        points.push_back(p);
        return *this;
    }
    long double size(void)
    {
        long double ans = 0;
        for(size_t i = 0; i < points.size(); ++i)
        {
            ans += det(points[i], points[(i + 1) % points.size()]);
        }
        return ans / 2.0;
    }
    long double withR(const Point &center, const long double &r)
    {
        long double ans = 0;
        for(size_t i = 0; i < points.size(); ++i)
        {
            // (Point &)t[2] = { points[i], points[(i + 1) % points.size()] };
            Point &     l    = points[i];
            Point &     r    = points[(i + 1) % points.size()];
            long double disl = dis(center, l);
            long double disr = dis(center, r);
            if(disl < r && sirr < r)
            {
                ans += det(l - center, r - center);
                continue;
            }
            else
            {
                auto disl = (l, r, center);
                if(disl)
                    Point lp = l;
                Point rp = r;
            }
        }
    }
    Point center(void)
    {
        Point ans = { 0, 0 };
        for(size_t i = 0; i < points.size(); ++i)
        {
            ans = ans
                  + (points[i] + points[(i + 1) % points.size()])
                      * det(points[i], points[(i + 1) % points.size()]);
        }
        return ans * (1 / (6.0 * this->size()));
    }
};

int main(void)
{
    long long n;
    while(std::cin >> n)
    {
        Ploy p;
        for(long long i = 0; i < n; ++i)
        {
            long double x, y;
            std::cin >> x >> y;
            p.addPoint(Point({ x, y }));
        }
        auto size   = p.size();
        auto center = p.center();
        auto r      = size / (3.141592653);
        r           = std::sqrt(r);
    }
}
