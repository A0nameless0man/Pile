#include <algorithm>
#include <cmath>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <vector>

#define assert(x)                                      \
    if(!(x))                                           \
    {                                                  \
        std::cout << "Failed asset " << (#x) << " in " \
                  << __FUNCTION__ << " (line: "        \
                  << std::to_string(__LINE__) << " )"  \
                  << std::endl;                        \
        throw std::runtime_error(                      \
          "Assert " #x " Filed in line"                \
          + std::to_string(__LINE__));                 \
    }                                                  \
    else                                               \
    {                                                  \
        std::cout << "Passed asset " << (#x) << " in " \
                  << __FUNCTION__ << " (line: "        \
                  << std::to_string(__LINE__) << " )"  \
                  << std::endl;                        \
    }

template <typename T>
struct CG2D
{
    static constexpr T EXP = 1e-8;
    static int         sig(const T &t)
    {
        if(std::abs(t) <= EXP)
        {
            return 0;
        }
        else if(t > EXP)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    struct Point
    {
        T x;
        T y;
        T length(void) const
        {
            return sqrt(x * x + y * y);
        }
        Point normal() const
        {
            T len = this->length();
            return { this->x / len, this->y / len };
        }
        Point turn90() const
        {
            return { this->y, -(this->x) };
        }
        Point rturn90() const
        {
            return { -(this->y), (this->x) };
        }
        Point mul(const T &rop) const
        {
            return { this->x * rop, this->y * rop };
        }
        Point sub(const Point &rop) const
        {
            return { this->x - rop.x, this->y - rop.y };
        }
        Point add(const Point &rop) const
        {
            return { this->x + rop.x, this->y + rop.y };
        }
        T dot(const Point &rop) const
        {
            return this->x * rop.x + this->y * rop.y;
        }
        T det(const Point &rop) const
        {
            return this->x * rop.y - this->y * rop.x;
        }
    };
    static T distance(const Point &lop, const Point &rop)
    {
        return (lop.sub(rop)).length();
    }
    static Point makePoint(const T &x, const T &y)
    {
        return { x, y };
    }
    struct PVLine
    {
        Point         a;
        Point         v;
        static PVLine makeLine(const Point &a,
                               const Point &b)
        {
            return { a, b.sub(a) };
        }
        bool isOnline(const Point &p,
                      const T      exp = T(0)) const
        {
            Point ap = p.sub(a);
            return std::abs(ap.det(v)) <= exp;
        }
        static bool isInterect(const PVLine &lop,
                               const PVLine &rop,
                               const T       exp = EXP)
        {
            return !(std::abs(lop.v.det(rop.v)) <= EXP);
        }
        static Point interect(const PVLine &lop,
                              const PVLine &rop)
        {
            T n = (lop.a.sub(rop.a)).det(lop.v)
                  / rop.v.det(lop.v);
            return rop.a.add(rop.v.mul(n));
        }
        PVLine move(const Point &dir)
        {
            return { this->a.add(dir), this->v };
        }
    };
};
using LB = long double;
using CG = CG2D<LB>;

int main(void)
{
    int T;
    while(std::cin >> T)
        for(int t = 0; t < T; ++t)
        {
            int L, x, y, vx, vy, k;
            std::cin >> L >> x >> y >> vx >> vy >> k;
            LB left  = 0;
            LB right = 1e18;
            // auto      source = CG::makePoint(x, y);
            LB a[3];
            LB b[3];
            LB px[3] = { 0, L / 2.0, -L / 2.0 };
            LB py[3] = { sqrt(3.0) / 2.0 * L, 0.0, 0.0 };
            CG::Point p_ref =
              CG::makePoint(static_cast<LB>(x),
                            static_cast<LB>(y));
            CG::Point p_v =
              CG::makePoint(static_cast<LB>(vx),
                            static_cast<LB>(vy));
            CG::PVLine line_ref = CG::PVLine::makeLine(
              p_ref,
              CG::makePoint(static_cast<LB>(x + vx),
                            static_cast<LB>(y + vy)));
            {
                for(int i = 0; i < 3; ++i)
                {
                    CG::PVLine line_a =
                      CG::PVLine::makeLine(
                        CG::makePoint(px[i], py[i]),
                        CG::makePoint(px[(i + 1) % 3],
                                      py[(i + 1) % 3]));
                    CG::PVLine line_b = line_a.move(
                      line_a.v.normal().turn90().mul(
                        py[0]));
                    if(CG::PVLine::isInterect(line_ref,
                                              line_a))
                    {
                        auto it_p_a =
                          CG::PVLine::interect(line_ref,
                                               line_a);
                        auto it_p_b =
                          CG::PVLine::interect(line_ref,
                                               line_b);
                        a[i] = CG::distance(it_p_a, p_ref);
                        b[i] = CG::distance(it_p_b, it_p_a);
                    }
                    else
                    {
                        a[i] = static_cast<LB>(-1);
                    }
                }
            }
            while(std::abs(right - left) > 1e-5)
            {
                LB        mid = (left + right) / 2.0;
                long long sum = 0;
                for(int i = 0; i < 3; ++i)
                {
                    if(a[i] > 0 && mid > a[i])
                    {
                        sum += static_cast<long long>(
                                 (mid - a[i]) / b[i])
                               + 1;
                    }
                }
                if(sum >= k)
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }
            std::cout << std::setprecision(
              std::numeric_limits<LB>::digits10 + 1)
                      << left / p_v.length() << std::endl;
        }
}
/*
4
4000 0 1234 0 -1 1
4000 0 1732 1000 0 1000000
4000 0 1732 1000 0 1
4000 -1000 1 0 1000 925469
*/