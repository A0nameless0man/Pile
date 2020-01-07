// Description
// Debu is a big cola drinker, but he can't help it.

// In order to drink less cola, he designed the following device:

// A tank that is nearly infinite in length and height, with an infinite amount of cola at the
// bottom.

// In the middle of the tank there are two planks, The planks are positioned infinitely far from the
// edge of the tank and the distance between planks and cola is infinite，two planks may intersect,

// Debu will turn the tank upside down at noon (completed in a moment), and the cola will fall down
// vertically.and speed of the cola is quickly，cola reach the bottom int a moment，so some

// cola may be retained by the planks(because two planks may intersect), and Debu will drink the
// cola retained by the planks

// At night Debu will repeat the process and enjoy the cola again.

// Now let's calculate how many volumes of cola Debu can drink in a day.(The width of planks and
// tank is 1)

// Input
// The first line is an integer T,represents the number of test case(1<=T<=1e5).

// Each test case has 8 integers: x1, y1, x2, y2, x3, y3, x4, y4.

// (x1, y1), (x2, y2) are the endpoints of one baffle, and (x3, y3), (x4, y4) are the endpoints of
// the

// other baffle，each integer doesn't exceeding 10,000.

// Output
// For each test case output a single line containing a real number with precision up to two decimal
// places - the volumes of cola.

#include <algorithm>
#include <iomanip>
#include <iostream>
namespace hg
{
double x1, y1, x2, y2, x3, y3, x4, y4;
struct Vec
{
    double x, y;
};
double operator*(const Vec &a, const Vec &b)
{
    return a.x * b.x + a.y * b.y;
}
double operator^(const Vec &a, const Vec &b)
{
    return a.x * b.y - a.y * b.x;
}
struct Point
{
    double x, y;
};
Vec operator-(const Point &a, const Point &b)
{
    return { a.x - b.x, a.y - b.y };
}
Vec operator*(const Vec &a, const double b)
{
    return { a.x * b, a.y * b };
}
Point operator+(const Point &a, const Vec &b)
{
    return { a.x + b.x, a.y + b.y };
}
struct Line
{
    Point a, b;
};
bool cross(const Line &a, const Line &b)
{
    Vec aV = a.a - a.b;
    Vec m = b.a - a.b, n = b.b - a.b;
    Vec bV = b.a - b.b;
    Vec x = a.a - b.b, y = a.b - b.b;
    return (aV ^ m) * (aV ^ n) <= 0 && (bV ^ x) * (bV ^ y) <= 0;
}
void correctSide(Line &l)
{
    if(l.a.y < l.b.y)
    {
        std::swap(l.a, l.b);
    }
}
void shrinkDownTo(Line &l, double y)
{
    double x = (y - l.b.y) / (l.a.y - l.b.y);
    l.a      = l.b + (l.a - l.b) * x;
}
void shrinkUpTo(Line &l, double y)
{
    double x = (l.a.y - y) / (l.a.y - l.b.y);
    l.b      = l.a + (l.b - l.a) * x;
}
int t;
int main(void)
{
    std::cin >> t;
    while(t--)
    {
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Point _1 = { x1, y1 }, _2 = { x2, y2 }, _3 = { x3, y3 }, _4 = { x4, y4 };
        Line  m = { _1, _2 }, n = { _3, _4 };
        if(cross(m, n))
        {
            correctSide(m);
            correctSide(n);
            if(m.a.y > n.a.y)
            {
                shrinkDownTo(m, n.a.y);
            }
            else
            {
                shrinkDownTo(n, n.a.y);
            }
            if(m.b.y < n.b.y)
            {
                shrinkUpTo(m, n.b.y);
            }
            else
            {
                shrinkUpTo(n, m.b.y);
            }
            std::cout << std::fixed << std::setprecision(2)
                      << ((std::abs(m.a.x - n.a.x) + std::abs(m.b.x - n.b.x)) / 2) * (m.a.y - m.b.y)
                      << std::endl;
        }
        else
        {
            std::cout << "0.00" << std::endl;
        }
    }
    return 0;
}
}  // namespace hg
int main(void)
{
    return hg::main();
}
