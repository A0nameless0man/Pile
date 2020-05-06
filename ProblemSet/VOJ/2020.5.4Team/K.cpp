#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using LF     = long double;
const LF PCS = 1e-8;
const LF PI  = acos(-1);
/*
Time: 2020-01-23 11:11:44
Describe: accepted after change pcs from 1e-20 to 1e-8
Statue: ACCEPTED
*/
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

// LF normalizeAngle(LF a)
// /*
// Time: 2020-01-22 11:16:33
// Describe: transfer a given angle in to range [0,2pi)
// Statue: CHECKED
// */
// {
//     return a - floor(a / (2 * PI)) * 2 * PI;
// }

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

LF angleOfVector(const LF &a, const LF &b)
{
    return atan2(b, a);
}

LF disPointToLine(const Point &p, const Point &line_a, const Point &line_b)
{
    LF a = (line_a.y - line_b.y);
    LF b = -(line_a.x - line_b.x);
    LF c = dot(line_a, line_b);
    // line : a*x+b*y+c==0
    LF dis = (a * p.x + b * p.y + c) / (sqrt(square(a) + square(b)));
    return std::abs(dis);
}

int main(void)
{
    long long r;
    long long n;
    while(std::cin >> n >> r)
    {
        std::vector<Point> points;
        std::vector<Point> hull;
        // std::cin >> n;

        {  // input points
            for(int i = 0; i < n; ++i)
            {
                LF x, y;
                std::cin >> x >> y;
                points.push_back(Point(x, y));
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

            // {  // remove close points;
            //     decltype(points) singlePoints;

            //     for(size_t i = 0; i < points.size(); ++i)
            //     {
            //         const auto &a = points[i];
            //         const auto &b = points[(i + 1) % points.size()];
            //         if(sign(a.x - b.x) != 0 || sign(a.y - b.y) != 0)
            //         {
            //             singlePoints.push_back(a);
            //         }
            //     }
            //     std::swap(points, singlePoints);
            // }

            std::vector<Point> vecStc;
            for(size_t i = 0; i < points.size(); ++i)
            {
                while(
                  vecStc.size() >= 2
                  && directionJudge(vecStc[vecStc.size() - 2], vecStc[vecStc.size() - 1], points[i])
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
                while(
                  vecStc.size() >= 2
                  && directionJudge(vecStc[vecStc.size() - 2], vecStc[vecStc.size() - 1], points[j])
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
        {
            for(auto p:hull)
            {
                std::cout << p.x << ":" << p.y << std::endl;
            }
        }
        {
            LF min_w = r * 20;
            for(long long line = 0, p = 1; line < hull.size(); ++line)
            {
                const Point &line_a = hull[line];
                const Point &line_b = hull[(line + 1) % hull.size()];
                while(disPointToLine(hull[p % hull.size()], line_a, line_b)
                      < disPointToLine(hull[(p + 1) % hull.size()], line_a, line_b))
                // while(std::abs(dot(hull[p % hull.size()] - line_a, hull[p % hull.size()] -
                // line_b))
                //       < std::abs(dot(hull[(p+1) % hull.size()] - line_a, hull[(p+1) %
                //       hull.size()] - line_b)))
                {
                    ++p;
                }
                min_w = std::min(min_w, disPointToLine(hull[p % hull.size()], line_a, line_b));
            }
            std::cout << std::setprecision(std::numeric_limits<LF>::digits10 + 1) << min_w
                      << std::endl;
        }
    }
    return 0;
}

/*
4 100
0 0 1 1 2 2 1 5
*/