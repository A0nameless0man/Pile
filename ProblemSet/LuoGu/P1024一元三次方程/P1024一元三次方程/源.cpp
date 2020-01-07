#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include <algorithm>
#include <ctype.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
template <typename T>
void swap(T &a, T &b)
{
    T t = a;
    a   = b;
    b   = t;
}
const int     MAX_N = 10007;
double        n, m, a, b, c, d;
inline double TheFunction(double x)
{
    return x * x * x * a + x * x * b + x * c + d;
}
double b_solve(double from, double to)  //ºŸ…Ëf(from)<0
{
    if(abs(from - to) < 0.00001)
    {
        return (from + to) / 2;
    }
    else
    {
        double mid = (from + to) / 2;
        if(TheFunction(mid) < 0)
        {
            return b_solve(mid, to);
        }
        else
        {
            return b_solve(from, mid);
        }
    }
}
void rev(void)
{
    a *= -1;
    b *= -1;
    c *= -1;
    d *= -1;
}
int main(void)
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif  // DEBUG

    while(scanf("%lf%lf%lf%lf", &a, &b, &c, &d) != EOF)
    {
        int    R_Count = 0;
        double left = -100, right = -100;
        if(a < 0)
        {
            rev();
        }
        while(R_Count < 3)
        {
            while(TheFunction(right) < 0.00001)
            {
                right += 0.5;
            }
            printf("%.2lf", b_solve(left, right));
            left = right;
            rev();
            R_Count++;
            if(R_Count != 3)
            {
                putchar(' ');
            }
            else
            {
                putchar('\n');
            }
        }
    }
#ifdef DEBUG
    system("pause");
    system("pause");
#endif  // DEBUG

    return 0;
}
