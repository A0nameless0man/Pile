#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

const long double ex = 0.000000000007;
const long double PI = acos(-1);
struct Point
{
    Point(long double x = 0, long double y = 0): x(x), y(y) {}
    long double x, y;
};

long double square(long double a)
{
    return a * a;
}

struct Round: public Point
{
    Round(long double x = 0, long double y = 0, long double r = 0): Point(x, y), r(r) {}
    long double r;
};

long double angleNormalize(long double a)
{
    return a - floor(a / (2 * PI)) * 2 * PI;
}

bool haveTan(const Round &a, const Round &b)
{
    return square(a.x - b.x) + square(a.y - b.y) > square(a.r - b.r);
}

long double getAngleOfVector(const long double &a, const long double &b, long double angle = 0)
{
    if(fabs(a) > ex)
    {
        auto ans = atan(b / a);
        return a > 0 ? ans : ans + PI;
    }
    else
    {
        return b / fabs(b) * 0.5 * PI;
    }
}

std::array<long double, 2> getTanAngle(const Round &a, const Round &b)
{
    Round       dif       = Round(a.x - b.x, a.y - b.y, a.r - b.r);
    long double angleBase = getAngleOfVector(-dif.x, -dif.y);
    long double angleDif  = asin(dif.r / sqrt(dif.x * dif.x + dif.y * dif.y));
    return { { angleNormalize(angleBase + angleDif), angleNormalize(angleBase - angleDif) } };
}  // 顺时针方向靠近a的边，顺时针方向靠近b的边；

std::array<Point, 4> getTanPoint(const Round &a, const Round &b)
{
    auto angle = getTanAngle(a, b);
    return { { Point(a.x + sin(angle[0]), a.y - cos(angle[0])),
               Point(a.x - sin(angle[1]), a.y + cos(angle[1])),
               Point(b.x + sin(angle[0]), b.y - cos(angle[0])),
               Point(b.x - sin(angle[1]), b.y + cos(angle[1])) } };
}

int main(void)
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int                n;
        std::vector<Round> rounds;
        std::vector<Point> points;
        std::vector<Point> hull;
        Point              startPoint(0, 0xfffff);
        Point              hullPoint;
        long double        startAngle = 0;
        std::cin >> n;

        for(int i = 0; i < n; ++i)
        {
            long double x, y, r;
            std::cin >> x >> y >> r;
            rounds.push_back({ x, y, r });
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(haveTan(rounds[i], rounds[j]))
                {
                    for(auto &i: getTanPoint(rounds[i], rounds[j]))
                    {
                        points.push_back(i);
                    }
                }
            }
        }
        for(auto &p: points)
        {
            if(p.y < startPoint.y)
            {
                startPoint = p;
            }
        }
        hullPoint = startPoint;
        do
        {
            Point       nextPoint;
            long double angleDif = 2 * PI;
            hull.push_back(startPoint);
            for(auto &p: points)
            {
                auto dif = angleNormalize(getAngleOfVector(p.x - startPoint.x, p.y - startPoint.y) -
                                          startAngle);
                // std::cout << dif << std::endl;
                if(dif < angleDif)
                {
                    nextPoint = p;
                    angleDif  = dif;
                }
            }
            startPoint = nextPoint;
            startAngle += angleDif;
        } while(startAngle < 2 * PI);
        hull.pop_back();
        // std::cout << hull.size() << std::endl;
        // for(auto &p: hull)
        // {
        //     std::cout << p.x << ":" << p.y << std::endl;
        // }
        auto onRound = [](Point &p, Round &r) -> bool {
            auto dx     = square(p.x - r.x);
            auto dy     = square(p.y - r.y);
            auto dr     = square(r.r);
            auto val    = dx + dy - dr;
            auto absval = fabs(val);
            auto ans    = (absval < ex);
            return ans;
        };
        auto onSameRound = [&](Point &a, Point &b) -> int {
            for(int i = 0; i < n; ++i)
            {
                auto resa = onRound(a, rounds[i]);
                auto resb = onRound(b, rounds[i]);
                if(resa && resb)
                {
                    return i;
                }
            }
            return static_cast<int>(-1);
        };
        long double ans = 0;
        for(size_t i = 0; i < hull.size(); ++i)
        {
            auto r = onSameRound(hull[i], hull[(i + 1) % hull.size()]);
            if(r != static_cast<int>(-1))
            {
                auto angle = angleNormalize(
                  getAngleOfVector(hull[i].x - rounds[r].x, hull[i].y - rounds[r].y) -
                  getAngleOfVector(hull[(i + 1) % hull.size()].x - rounds[r].x,
                                   hull[(i + 1) % hull.size()].y - rounds[r].y));
                angle = 2 * PI - angle;
                ans += angle * rounds[r].r;
                // std::cout << "#" << angle << std::endl;
                // std::cout << hull[i].x << ":" << hull[i].y << std::endl;
                // std::cout << hull[(i + 1) % hull.size()].x << ":" << hull[(i + 1) %
                // hull.size()].y
                //           << std::endl;
                // std::cout << rounds[r].x << ":" << rounds[r].y << "by" << rounds[r].r <<
                // std::endl;
            }
            else
            {
                ans += sqrt(square(hull[i].x - hull[(i + 1) % hull.size()].x) +
                            square(hull[i].y - hull[(i + 1) % hull.size()].y));
                // std::cout << "line" << std::endl;
            }
        }
        //std::cout << std::fixed << std::setprecision(11) << ans << std::endl;
        printf("%.11Lf\n", ans);
    }
    return 0;
}