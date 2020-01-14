#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using LF     = long double;
const LF PCS = 0.000000000007;
const LF PI  = acos(-1);

LF square(LF a)
{
    return a * a;
}

LF normalizeAngle(LF a)
{
    return a - floor(a / (2 * PI)) * 2 * PI;
}

struct Point
{
    LF x, y;
    Point(LF xx = 0, LF yy = 0): x(xx), y(yy) {}
};

struct Round: public Point
{
    LF r;
    Round(LF xx = 0, LF yy = 0, LF rr = 0): Point(xx, yy), r(rr) {}
};

bool tanAble(const Round &a, const Round &b)
{
    return square(a.x - b.x) + square(a.y - b.y) > square(a.r - b.r);
}

LF angleOfVector(const LF &a, const LF &b)
{
    if(fabs(a) > PCS)
    {
        auto ans = atan(b / a);
        return ((a > 0) ? ans : ans + PI);
    }
    else
    {
        return (b / fabs(b) * 0.5 * PI);
    }
}

std::array<LF, 2> getTanAngle(const Round &a, const Round &b)
{
    Round dif       = Round(a.x - b.x, a.y - b.y, a.r - b.r);
    LF    angleBase = angleOfVector(-dif.x, -dif.y);
    LF    angleDif  = asin(dif.r / sqrt(square(dif.x) + square(dif.y)));
    return { { (angleBase + angleDif), (angleBase - angleDif) } };
}

std::array<Point, 4> getTanPoint(const Round &a, const Round &b)
{
    auto angle = getTanAngle(a, b);
    return { { Point(a.x + sin(angle[0]), a.y - cos(angle[0])),
               Point(a.x - sin(angle[1]), a.y + cos(angle[1])),
               Point(b.x + sin(angle[0]), b.y - cos(angle[0])),
               Point(b.x - sin(angle[1]), b.y + cos(angle[1])) } };
}

bool onRound(const Point &p, const Round &r)
{
    return (fabs(square(p.x - r.x) + square(p.y - r.y) - square(r.r)) < PCS);
}

bool onSameRound(const Point &pa, const Point &pb, const Round &r)
{
    return onRound(pa, r) && onRound(pb, r);
}

int main(void)
{
    int t;
    int n;
    std::cin >> t;
    while(t--)
    {
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
            rounds.push_back(Round(x, y, r));
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(tanAble(rounds[i], rounds[j]))
                {
                    auto ps = getTanPoint(rounds[i], rounds[j]);
                    for(auto p: ps)
                    {
                        points.push_back(p);
                    }
                }
            }
        }

        if(points.size() == 0)
        {
            LF r = 0;
            for(auto i: rounds)
            {
                r = std::max(r, i.r);
            }
            std::cout << std::setprecision(16) << r * 2 * PI << std::endl;
            continue;
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
            Point nextpoint;
            LF    angleDif = 2 * PI;
            hull.push_back(startPoint);
            for(auto &p: points)
            {
                LF dif = normalizeAngle(angleOfVector(p.x - startPoint.x, p.y - startPoint.y) -
                                        startAngle);
                if(dif < angleDif)
                {
                    nextpoint = p;
                    angleDif  = dif;
                }
            }
            startPoint = nextpoint;
            startAngle += angleDif;
        } while(startAngle < 2 * PI);
        if(hull[0].x == hull.rbegin()->x && hull[0].y == hull.rbegin()->y)
            hull.pop_back();

        LF ans = 0;
        for(size_t i = 0; i < hull.size(); ++i)
        {
            size_t a = i, b = (i + 1) % hull.size();
            for(size_t j = 0; j < rounds.size(); ++j)
            {
                if(onSameRound(hull[a], hull[b], rounds[j]))
                {
                    LF angle = normalizeAngle(
                      angleOfVector(hull[a].x - rounds[j].x, hull[a].y - rounds[j].y) -
                      angleOfVector(hull[b].x - rounds[j].x, hull[b].y - rounds[j].y));
                    if(angle > PI)
                        angle = 2 * PI - angle;
                    ans += angle * rounds[j].r;

                    // std::cout << "#" << angle << std::endl;
                    // std::cout << hull[a].x << ":" << hull[a].y << std::endl;
                    // std::cout << hull[b].x << ":" << hull[b].y << std::endl;
                    // std::cout << rounds[j].x << ":" << rounds[j].y << "by" << rounds[j].r
                    //           << std::endl;
                    goto nextPoint;
                }
            }
            ans += sqrt(square(hull[a].x - hull[b].x) + square(hull[a].y - hull[b].y));
        nextPoint:;
        }

        std::cout << std::setprecision(16) << ans << std::endl;
    }
    return 0;
}