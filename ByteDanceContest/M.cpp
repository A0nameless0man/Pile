#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
int main(void)
{
    int                   n, m;
    std::vector<unsigned> a, b;
    while(std::cin >> n >> m)
    {
        a.clear();
        b.clear();
        for(int i = 0; i < n; ++i)
        {
            int ai;
            // std::cin >> ai;
            scanf("%d", &ai);
            a.push_back(ai % m);
        }
        for(int i = 0; i < n; ++i)
        {
            int bi;
            // std::cin >> bi;
            scanf("%d", &bi);
            b.push_back(bi % m);
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        int predictX;
        int x = 0x7fffffff;
        // while (!found)
        for(int offset = 0; offset < n; ++offset)
        {
            predictX = ((b[offset] + m) - a[0]) % m;
            for(int i = 0; i < n; ++i)
            {
                if((a[i] + predictX) % m != b[(i + offset) % n] % m)
                {
                    predictX = 0x7fffffff;
                    break;
                }
            }
            x = std::min(x, predictX);
        }
        std::cout << x << std::endl;
    }
}