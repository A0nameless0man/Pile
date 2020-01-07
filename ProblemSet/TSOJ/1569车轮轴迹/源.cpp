#define _CRT_SECURE_NO_WARNINGS  // shut up MS//NOT fo CPP//scanf VS. scanf_s
//#define DEBUG
//#define InFile
#include <algorithm>
#include <ctype.h>
#include <fstream>   //file
#include <iostream>  //stream
#include <math.h>
#include <sstream>  //stringstream
#include <stdio.h>
#include <string.h>
#include <string>
// STL
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
// STL
#ifdef InFile
#    include <Windows.h>  //sleep()
#    include <stdlib.h>   //system("pause")
#endif                    // InFile
#ifdef DEBUG
#    define Check(X) std::cout << "Express \"" << #    X << "\" is " << (X) << std::endl
#else
#    define Check(X) ;
#endif
// template <typename T> void swap(T &a, T &b)
//{
//	T t = a;
//	a = b;
//	b = t;
//}
// using namespace std;
using LL        = long long;
using ULL       = unsigned long long;
using LD        = long double;
const int MAX_N = 10007;
const LD  EXP   = 0.0000001;
const LD  Pi    = 3.1415926535897932384626433832795028841971693993751;
int       n, m, a, b, j, k;
LD        r;
inline LD square(LD n)
{
    return n * n;
}
inline LD f(LD a, LD b)
{
    return sqrtl(square(a) + square(b));
}
class Dot;
class Cir;
class Dir;
class Vec;
class Lin;
class Shape
{
public:
    virtual LD length(void) = 0;
};
class Dot
{
public:
    Dot(LD x = 0, LD y = 0): x(x), y(y)
    {
        ;
    }
    Dot operator+(const Dot &b) const
    {
        return Dot(x + b.x, y + b.y);
    }
    template <class stream>
    friend stream &operator>>(stream &is, Dot &a)
    {
        return is >> a.x >> a.y;
    }
    friend LD distent(const Dot &a, const Dot &b)
    {
        return sqrtl(square(a.x - b.x) + square(a.y - b.y));
    }
    LD x, y;
};
class Cir: virtual public Shape
{
public:
    virtual LD length(void)
    {
        return r * 2.0 * Pi;
    }
    Cir(const Dot &center, LD r): center(center), r(r)
    {
        ;
    }
    Cir(const Dot &center, const Dot &second): center(center), r(distent(center, second))
    {
        ;
    }
    bool contain(const Dot &from) const
    {
        return r > distent(center, b);
    }

private:
    Dot center;
    LD  r;
};
class Dir
{
public:
    operator LD()
    {
        return dir;
    }
    Dir(LD dir): dir(dir)
    {
        ;
    }
    Dir(const Dot &from, const Dot &to)
    {
        dir = atanl((to.y - from.y) / (to.x - from.x));
        if(to.x < from.x)
        {
            dir += Pi;
        }
    }

private:
    LD dir;  ////与x轴正方向的夹角;
};
class Vec: virtual public Shape
{
public:
    virtual LD length(void)
    {
        return INFINITY;
    }
    Vec(const Dot &from, LD dir): from(from), dir(dir)
    {
        ;
    }
    Vec(const Dot &from, const Dot &to): from(from), dir(from, to)
    {
        ;
    }

private:
    Dot from;
    Dir dir;  //与x轴正方向的夹角;
};
class Lin: virtual public Shape
{
public:
    virtual LD length(void)
    {
        return distent(from, to);
    }
    Lin(const Dot &from, const Dot &to): from(from), to(to)
    {
        ;
    }
    friend Dot cross(const Lin &a, const Lin &b)
    {
        LD a1 = (a.from.y - a.to.y), b1 = (a.from.x - a.to.y), c1 = (a1 * a.from.x - b1 * a.from.y);
        LD a2 = (b.from.y - b.to.y), b2 = (b.from.x - b.to.y), c2 = (a2 * a.from.x - b2 * b.from.y);
        // a1*x+b1*y==c1;
        // a2*x+b2*y==c2;
        return Dot((a1 * b2 - a2 * b1) / (b1 * c2 - b2 * c1),
                   (a1 * b2 - a2 * b1) / (a1 * c2 - a2 * c1));
    }

private:
    Dot from, to;
};
class Curve: virtual public Shape
{
public:
    Curve(Cir cir, Dir from, Dir to): cir(cir), from(from), to(to)
    {
        ;
    }
    virtual LD length(void)
    {
        return (to - from) / (2 * Pi) * cir.length();
    }

private:
    Cir cir;
    Dir from, to;
};
Dot dots[MAX_N];
int main(void)
{
#ifdef InFile
    std::fstream fin;
    fin.open("./in.txt", std::ios::in);
    std::cin.rdbuf(fin.rdbuf());
#endif  // InFile

    while(std::cin >> n >> r)
    {
        for(int i = 0; i < n; i++)
        {
            std::cin >> dots[i];
        }
        std::vector<Shape> Road;
        for(int i = 0; i < n - 1; i++)
        {
            Road.push_back(Lin(dots[i], dots[i + 1]));
        }
        std::vector<Shape> Track;

        LD ans = 0;
    }
#ifdef InFile
    system("pause");
    Sleep(-1);
#endif  // InFile
    return 0;
}
