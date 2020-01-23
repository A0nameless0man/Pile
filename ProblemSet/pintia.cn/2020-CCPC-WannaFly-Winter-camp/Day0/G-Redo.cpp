#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using LF     = long double;
const LF PCS = 1e-8;
const LF PI  = acos(-1);

int sign(const LF &a)
/*
Time: 2020-01-22 11:14:02
Describe: return the sign of given value
Statue: CHECKED
*/
{
    if(a > PCS)
    {
        return 1;
    }
    if(a < -PCS)
    {
        return -1;
    }
    return 0;
}

LF square(LF a)
/*
Time: 2020-01-22 11:14:51
Describe: return the squared value of given long double ,aka y=x^2
Statue: CHECKED
*/
{
    return a * a;
}

LF normalizeAngle(LF a)
/*
Time: 2020-01-22 11:16:33
Describe: transfer a given angle in to range [0,2pi)
Statue: CHECKED
*/
{
    return a - floor(a / (2 * PI)) * 2 * PI;
}

struct Point
{
    LF x, y;
    Point(LF xx = 0, LF yy = 0): x(xx), y(yy) {}
};

Point sub(const Point &a, const Point &b)
/*
Time: 2020-01-22 11:18:47
Describe: point sub point aka "a-b"
Statue: CHECKED
*/
{
    return Point { a.x - b.x, a.y - b.y };
}

LF dot(const Point &a, const Point &b)
/*
Time: 2020-01-22 11:22:09
Describe: actually ,this is det
Statue: CHECKED
*/
{
    return (a.x * b.y - a.y * b.x);
}

LF directionJudge(const Point &a, const Point &b, const Point &c)
{
    return dot(sub(b, a), sub(c, b));
}

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
    return atan2(b, a);
    // if(fabs(a) > PCS)
    // {
    //     auto ans = atan(b / a);
    //     return ((a > 0) ? ans : ans + PI);
    // }
    // else
    // {
    //     return (b / fabs(b) * 0.5 * PI);
    // }
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
    return { { Point(a.x + a.r * sin(angle[0]), a.y - a.r * cos(angle[0])),
               Point(a.x - a.r * sin(angle[1]), a.y + a.r * cos(angle[1])),
               Point(b.x + b.r * sin(angle[0]), b.y - b.r * cos(angle[0])),
               Point(b.x - b.r * sin(angle[1]), b.y + b.r * cos(angle[1])) } };
}

int onRound(const Point &p, const Round &r)
{
    return (sign(square(p.x - r.x) + square(p.y - r.y) - square(r.r)));
}

bool onSameRound(const Point &pa, const Point &pb, const Round &r)
{
    return onRound(pa, r) == 0 && onRound(pb, r) == 0;
}

int main(void)
{
    int t;
    int n;
    while(std::cin >> t)
    {
        while(t--)
        {
            std::vector<Round> rounds;
            std::vector<Point> points;
            std::vector<Point> hull;
            Point              startPoint(0, 0xfffff);
            Point              hullPoint;
            long double        startAngle = 0;
            std::cin >> n;

            {  // input rounds
                for(int i = 0; i < n; ++i)
                {
                    long double x, y, r;
                    std::cin >> x >> y >> r;
                    rounds.push_back(Round(x, y, r));
                }
            }

            {  // caculate tango point
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
            }
            // {
            //     std::cout << "###Points" << std::endl;
            //     for(auto p: points)
            //     {
            //         std::cout << p.x << ":" << p.y << std::endl;
            //     }
            //     std::cout << "PointsEnd" << std::endl;
            // }
            // {  // check if a great round covered all
            //     bool  oneRound = true;
            //     Round r        = Round { 0, 0, 0 };

            //     for(auto i: rounds)
            //     {
            //         if(i.r > r.r)
            //         {
            //             r = i;
            //         }
            //     }
            //     for(const auto &p: points)
            //     {
            //         if(onRound(p, r) > 0)
            //         {
            //             oneRound = false;
            //             break;
            //         }
            //     }
            //     if(oneRound)
            //     {
            //         std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
            //                   << r.r * 2 * PI << std::endl;
            //         // throw 1;
            //         continue;
            //     }
            // }

            {  // add extra point
                for(const auto &r: rounds)
                {
                    for(LF i = 0; i < 2 * PI; i += 0.1 * PI)
                    {
                        points.push_back(Point(r.x + r.r * cos(i), r.y + r.r * sin(i)));
                    }
                }
            }

            {  // a better way to caculate convex hull
                std::sort(points.begin(), points.end(), [](const Point &a, const Point &b) -> bool {
                    if(sign(a.x - b.x) != 0)
                    {
                        return a.x < b.x;
                    }
                    else
                    {
                        return a.y < b.y;
                    }
                });
                {  // remove close points;
                    decltype(points) singlePoints;

                    for(size_t i = 0; i < points.size(); ++i)
                    {
                        const auto &a = points[i];
                        const auto &b = points[(i + 1) % points.size()];
                        if(sign(a.x - b.x) != 0 || sign(a.y - b.y) != 0)
                        {
                            singlePoints.push_back(a);
                        }
                    }
                    std::swap(points, singlePoints);
                }
                std::vector<Point> vecStc;
                for(size_t i = 0; i < points.size(); ++i)
                {
                    while(vecStc.size() >= 2
                          && directionJudge(vecStc[vecStc.size() - 2],
                                            vecStc[vecStc.size() - 1],
                                            points[i])
                               < 0)
                    {
                        vecStc.pop_back();
                    }
                    vecStc.push_back(points[i]);
                }
                for(size_t i = 0; i < vecStc.size() - 1; ++i)
                {
                    hull.push_back(vecStc[i]);
                }
                vecStc.clear();
                for(size_t i = 0; i < points.size(); ++i)
                {
                    size_t j = points.size() - i - 1;
                    while(vecStc.size() >= 2
                          && directionJudge(vecStc[vecStc.size() - 2],
                                            vecStc[vecStc.size() - 1],
                                            points[j])
                               < 0)
                    {
                        vecStc.pop_back();
                    }
                    vecStc.push_back(points[j]);
                }
                for(size_t i = 0; i < vecStc.size() - 1; ++i)
                {
                    hull.push_back(vecStc[i]);
                }
            }

            {  // calcuate ans and output
                LF ans = 0;

                // std::cout << "###caculating ..." << std::endl;
                for(size_t i = 0; i < hull.size(); ++i)
                {
                    size_t a = i, b = (i + 1) % hull.size();
                    LF     thisLen = 0;
                    bool   onRound = false;
                    // std::cout << "Point pair:" << std::endl;
                    // std::cout << hull[a].x << ":" << hull[a].y << std::endl;
                    // std::cout << hull[b].x << ":" << hull[b].y << std::endl;
                    for(size_t j = 0; j < rounds.size(); ++j)
                    {
                        if(onSameRound(hull[a], hull[b], rounds[j]))
                        {
                            LF angle = normalizeAngle(
                              -angleOfVector(hull[a].x - rounds[j].x, hull[a].y - rounds[j].y)
                              + angleOfVector(hull[b].x - rounds[j].x, hull[b].y - rounds[j].y));
                            // if(angle > PI)
                            //     angle = 2 * PI - angle;
                            thisLen = angle * rounds[j].r;

                            // std::cout << "#onRound" << angle << std::endl;
                            // std::cout << rounds[j].x << ":" << rounds[j].y << "by" << rounds[j].r
                            //   << std::endl;
                            onRound = true;
                            break;
                        }
                    }
                    if(!onRound)
                    {
                        thisLen =
                          sqrt(square(hull[a].x - hull[b].x) + square(hull[a].y - hull[b].y));
                    }
                    // std::cout << "contirbution:" << thisLen << std::endl;
                    ans += thisLen;
                }
                // std::cout << "###end###" << std::endl;
                std::cout << std::setprecision(std::numeric_limits<LF>::digits10 + 1) << ans
                          << std::endl;
            }
        }
    }
    return 0;
}
/*
0 -1
0 1
1 -1
*/
/*
0 2
1 -2
*/
/*
-4
*/