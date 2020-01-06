#include <algorithm>
#include <iostream>
#include <map>
#include <set>
int main(void)
{
    int T, n;
    std::cin >> T;
    n = T;
    std::set<std::pair<long, long> > points;
    while(T--)
    {
        long x, y;
        std::cin >> x >> y;
        points.insert({ x, y });
    }
    std::map<std::pair<long, long>, long> midPoint;
    for(auto i = points.begin(); i != points.end(); ++i)
    {
        for(auto j = points.begin(); j != i; ++j)
        {
            std::pair<long, long> mid = { i->first + j->first, i->second + j->second };
            midPoint[mid] += 2;
        }
    }
    for(auto p: points)
    {
        ++midPoint[{ p.first * 2, p.second * 2 }];
    }
    long max = 0;
    for(auto p: midPoint)
    {
        max = std::max(max, p.second);
    }
    std::cout << n - max << std::endl;
}