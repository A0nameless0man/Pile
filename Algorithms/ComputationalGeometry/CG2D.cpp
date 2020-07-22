#include <algorithm>
#include <cmath>

template <typename T>
struct CG2D
{
    static constexpr T EXP = 1e-8;
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
    static T distence(const Point &lop, const Point &rop)
    {
        return (lop.sub(rop)).length();
    }
    static Point makePoint(const T &x, const T &y)
    {
        return { x, y };
    }
    // struct PVLine
    // {
    //     Point         a;
    //     Point         v;
    //     static PVLine makeLine(const Point &a,
    //                               const Point &b)
    //     {
    //         return { a, b.sub(a) };
    //     }
    //     bool isOnline(const Point &p,
    //                   const T         exp = T(0)) const
    //     {
    //         Point ap = p.sub(a);
    //         return std::abs(ap.det(v)) <= exp;
    //     }
    //     static bool isInterect(const PVLine &lop,
    //                            const PVLine &rop,
    //                            const T       exp = EXP)
    //     {
    //         return !(std::abs(lop.v.det(rop.v)) <=
    //         EXP);
    //     }
    //     static Point interect(const PVLine &lop,
    //                              const PVLine &rop)
    //     {
    //         T n = (lop.a.sub(rop.a)).det(lop.v)
    //               / rop.v.det(lop.v);
    //         return rop.a.add(rop.v.mul(n));
    //     }
    //     PVLine move(const Point &dir)
    //     {
    //         return { this->a.add(dir), this->v };
    //     }
    // };
    static bool testPointLength(void)
    {
        Point a    = makePoint(T(4.0), T(3.0));
        Point zero = makePoint(T(0.0), T(0.0));
        return std::abs(distence(a, zero) - T(5.0)) < EXP
               && std::abs(a.length() - T(5.0)) < EXP
               && std::abs(zero.length() < EXP);
    }
    static bool testPointNormel(void)
    {
        Point a = makePoint(T(10.0), T(10.0));
        Point b = makePoint(T(4.0), T(3.0));
        if(!((std::abs(a.normal().length() - T(1.0)) < EXP)
             && (std::abs(b.normal().length() - T(1.0))
                 < EXP)))
        {
            return 0;
        }
        return 1;
    }
    static bool testPointTurn90(void)
    {
        Point a = makePoint(T(10.0), T(10.0));
        return std::abs(distence(a.turn90().turn90(),
                                 a.rturn90().rturn90()))
                 < EXP
               && std::abs(
                    distence(a.turn90().rturn90(), a))
                    < EXP
               && std::abs(distence(
                    a.turn90().turn90().turn90().turn90(),
                    a.rturn90()
                      .rturn90()
                      .rturn90()
                      .rturn90()))
                    < EXP;
    }
    using TestFunType                = bool (*)(void);
    static constexpr size_t testcnt  = 3;
    const TestFunType tests[testcnt] = { testPointLength,
                                         testPointNormel,
                                         testPointTurn90 };
};

#include <iostream>
int main(void)
{
    using LB = long double;
    for(size_t i = 0; i < CG2D<LB>::testcnt; ++i)
    {
        std::cout << CG2D<LB>().tests[i]() << std::endl;
    }
}