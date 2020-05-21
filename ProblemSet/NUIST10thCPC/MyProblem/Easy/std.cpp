#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <vector>

int main(void)
{
    std::cerr << "watching" << std::endl;
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            std::array<int, 1441> ary = { 0 };
            int                   n;
            // std::cin >> n;
            scanf("%d", &n);
            for(int i = 0; i < n; ++i)
            {
                int a;
                // std::cin >> a;
                scanf("%d", &a);
                if(a > 10)
                {
                    std::cerr << "cust too many" << std::endl;
                }
                for(int j = 0; j < a; ++j)
                {
                    int beg, end;
                    // std::cin >> beg >> end;
                    scanf("%d%d", &beg, &end);
                    beg = 60 * (beg / 100) + beg % 100;
                    end = 60 * (end / 100) + end % 100;
                    end = std::min(end, 1440);
                    for(int i = beg; i < end; ++i)
                    {
                        ++ary[i];
                    }
                }
            }
#ifdef DEBUG
            for(int i = 0; i < 1440; ++i)
            {
                std::cout << ary[i] << " ";
            }
            std::cout << std::endl;
#endif  // DEBUG
        // for(int i = 1; i < 1441; ++i)
        // {
        //     ary[i] += ary[i - 1];
        // }
            int a = 0, b = 0, c = 0;
            for(int i = 0; i < 1440; ++i)
            {
                if(ary[i] > 4)
                {
                    ++a;
                }
                else if(ary[i] == 0)
                {
                    if(i < 360 || i >= 1080)
                    {
                        ++c;
                    }
                    else
                    {
                        ++b;
                    }
                }
            }
            // std::cout << a << " " << b << " " << c << std::endl;
            printf("%d %d %d\n", a, b, c);
        }
    }
}