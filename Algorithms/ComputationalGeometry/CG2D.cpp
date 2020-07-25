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
        T    x;
        T    y;
        bool isEqualTo(const Point &rop)
        {  // faster
            return sig(std::abs(this->x - rop.x)) == 0
                   && sig(std::abs(this->y - rop.y)) == 0;
        }
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
            return sig(ap.det(v)) == 0;
        }
        static bool isInterect(const PVLine &lop,
                               const PVLine &rop,
                               const T       exp = EXP)
        {
            return sig(lop.v.det(rop.v)) != 0;
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
    static bool testPointIsEqualTo(void)
    {
        T     x       = T(0.5);
        T     y       = T(0.5);
        T     offset1 = T(T(0.6) * EXP);
        T     offset2 = T(T(0.8) * EXP);
        Point a       = makePoint(T(x), T(y));
        Point b = makePoint(T(x + offset1), T(y - offset1));
        Point c = makePoint(T(x - offset2), T(y + offset2));
        try
        {
            assert(a.isEqualTo(b));
            assert(a.isEqualTo(c));
            assert(!b.isEqualTo(c));
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
            assert(a.turn90().turn90().isEqualTo(
              a.rturn90().rturn90()));
            assert(a.turn90().rturn90().isEqualTo(a));
            assert(a.turn90()
                     .turn90()
                     .turn90()
                     .turn90()
                     .isEqualTo(a.rturn90()
                                  .rturn90()
                                  .rturn90()
                                  .rturn90()));
            return 1;
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
    static bool testPointSub(void)
    {
        Point a = makePoint(T(3.0), T(4.0));
        Point b = makePoint(T(4.0), T(3.0));
        Point c = makePoint(T(-1.0), T(1.0));
        try
        {
            assert(a.sub(b).isEqualTo(c));
            assert(a.sub(c).isEqualTo(b));
            return 1;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 0;
        }
    }
    static bool testPointAdd(void)
    {
        Point a = makePoint(T(3.0), T(4.0));
        Point b = makePoint(T(4.0), T(3.0));
        Point c = makePoint(T(-1.0), T(1.0));
        try
        {
            assert(c.add(b).isEqualTo(a));
            assert(b.add(c).isEqualTo(a));
            return 1;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 0;
        }
    }
    static bool testPointDot(void)
    {
        Point a = makePoint(T(3.0), T(4.0));
        Point b = makePoint(T(4.0), T(-3.0));
        Point c = makePoint(T(-4.0), T(3.0));
        Point d = makePoint(T(12.0), T(5.0));
        T     e = T(56.0);
        T     f = T(25.0);
        try
        {
            assert(sig(a.dot(b)) == 0);
            assert(sig(a.dot(c)) == 0);
            assert(sig(b.dot(a)) == 0);
            assert(sig(b.dot(c) + f) == 0);
            assert(sig(c.dot(a)) == 0);
            assert(sig(c.dot(b) + f) == 0);
            assert(sig(a.dot(d) - e) == 0);
            assert(sig(d.dot(a) - e) == 0);
            return 1;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return 0;
        }
    }
    static bool testPointDet(void)
    {
        Point a = makePoint(T(3.0), T(4.0));
        Point b = makePoint(T(12.0), T(5.0));
        Point c = makePoint(T(4.0), T(-3.0));
        Point d = makePoint(T(-4.0), T(3.0));
        Point e = makePoint(T(6.0), T(8.0));
        Point f = makePoint(T(-6.0), T(-8.0));
        T     g = T(33.0);
        T     h = T(25.0);
        try
        {
            assert(sig(a.det(b) + g) == 0);
            assert(sig(b.det(a) - g) == 0);
            assert(sig(a.det(c) + h) == 0);
            assert(sig(c.det(a) - h) == 0);
            assert(sig(a.det(d) - h) == 0);
            assert(sig(d.det(a) + h) == 0);
            assert(sig(a.det(e)) == 0);
            assert(sig(e.det(a)) == 0);
            assert(sig(a.det(f)) == 0);
            assert(sig(f.det(a)) == 0);
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
        testSig,         testPointIsEqualTo,
        testPointLength, testPointNormel,
        testPointTurn90, testPointMulT,
        testPointSub,    testPointAdd,
        testPointDot,    testPointDet
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