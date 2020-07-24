#include <algorithm>
#include <cmath>
#include <deque>
#include <exception>
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
    static bool testSig(void)
    {
        // return sig(T(0.0)) == 0 && sig(T(2.0) * EXP) == 1
        //        && sig(T(-0.9) == 0) && sig(T(-2.0)) == -1
        //        && sig(T(-0.0) == 0);
        try
        {

            assert((sig(T(0.0)) == 0));
            assert((sig(T(2.0) * EXP) == 1));
            assert((sig(T(-0.9) * EXP) == 0));
            assert((sig(T(-2.0) * EXP) == -1));
            assert((sig(T(-2.0)) == -1));
            assert((sig(T(-0.0)) == 0));
            assert((sig(T(-0.0) * EXP) == 0));
            return 1;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 0;
        }
    }
    static bool testPointLength(void)
    {
        Point a    = makePoint(T(4.0), T(3.0));
        Point zero = makePoint(T(0.0), T(0.0));
        try
        {
            assert(std::abs(distance(a, zero) - T(5.0))
                   < EXP);
            assert(std::abs(a.length() - T(5.0)) < EXP);
            assert(std::abs(zero.length() < EXP));
            return 1;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 0;
        }
    }
    static bool testPointNormel(void)
    {
        Point a = makePoint(T(10.0), T(10.0));
        Point b = makePoint(T(4.0), T(3.0));
        try
        {
            assert(std::abs(a.normal().length() - T(1.0))
                   < EXP);
            assert(std::abs(b.normal().length() - T(1.0))
                   < EXP);
            assert(
              a.normal()
                .sub(makePoint(T(5.0), T(5.0)).normal())
                .length()
              < EXP);
            assert(
              b.normal()
                .sub(makePoint(T(8.0), T(6.0)).normal())
                .length()
              < EXP);
            return 1;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 0;
        }
    }
    static bool testPointTurn90(void)
    {
        Point a = makePoint(T(10.0), T(10.0));
        try
        {
            assert(std::abs(distance(a.turn90().turn90(),
                                     a.rturn90().rturn90()))
                   < EXP);
            assert(
              std::abs(distance(a.turn90().rturn90(), a))
              < EXP);
            assert(
              std::abs(distance(
                a.turn90().turn90().turn90().turn90(),
                a.rturn90().rturn90().rturn90().rturn90()))
              < EXP) return 1;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 0;
        }
    }
    static bool testPointMulT(void)
    {
        Point a = makePoint(T(5.0), T(-5.0));
        Point b = makePoint(T(-5.0), T(5.0));
        Point c = makePoint(T(10.0), T(-10.0));
        try
        {
            assert(distance(a.mul(T(-1.0)), b) < EXP);
            assert(distance(a.mul(T(2.0)), c) < EXP);
            assert(distance(a.mul(T(1.0)), a) < EXP);
            return 1;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 0;
        }
    }
    using TestFunType                    = bool (*)(void);
    const std::vector<TestFunType> tests = {
        testSig,
        testPointLength,
        testPointNormel,
        testPointTurn90,
        testPointMulT
    };
};

int main(void)
{
    using LB = long double;
    CG2D<LB> cg;
    for(size_t i = 0; i < cg.tests.size(); ++i)
    {
        // std::cout << fun() << std::endl;
        if(!cg.tests[i]())
        {
            std::cout << "Faile on " << i << std::endl;
            std::cin >> std::ws;
            return -1;
        }
        else
        {
            std::cout << "Sucess on " << i << std::endl;
        }
    }
    std::cin >> std::ws;
    return 0;
}