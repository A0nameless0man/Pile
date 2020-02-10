#include<iostream>
#include<cstdio>

struct Vec2
{
    long long x, y;
}

Vec2 operator-(const Vec2&a,const Vec2&b)
{
    return Vec2 { a.x - b.x, a.y - b.y };
}

long long det(const Vec2 &a, const Vec2 &b)
{
    return a.x * b.y - a.y * b.x;
}

Vec2 readVec2(void)
{
    Vec2 buf;
    scanf("%lld%lld", &buf.x, &buf.y);
    return buf;
}

