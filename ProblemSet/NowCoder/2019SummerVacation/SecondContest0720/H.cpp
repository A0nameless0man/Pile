#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using LL     = long long;
const LL INF = 10000;
struct point
{
    LL  x, y;
    int index;
};
bool operator<(const point &a, const point &b)
{
    return a.x * INF + a.y < b.x * INF + b.y;
}
int main(void)
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int                n;
        std::vector<point> points;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            LL bufx, bufy;
            scanf("%lld%lld", &bufx, &bufy);
            points.push_back({ bufx, bufy, i });
        }
        std::sort(points.begin(), points.end());
        point key = points[n / 2 - 1];
        std::cout << "(" << key.x << "," << key.y << ")" << std::endl;
        std::cout << key.x - 1 << " " << +INF << " " << key.x + 1 << " " << 2 * key.y + 1 - INF;
    }
    return 0;
}