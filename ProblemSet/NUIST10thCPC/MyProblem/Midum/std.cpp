#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <vector>

int decode(int i)
{
    return (i / 10000) * 1440 + 60 * (i % 10000 / 100) + i % 60;
}

int main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            std::array<int, 43200 + 1> ary = { 0 };
            int                        n;
            // std::cin >> n;
            scanf("%d", &n);
            for(int i = 0; i < n; ++i)
            {
                int a;
                // std::cin >> a;
                scanf("%d", &a);
                for(int j = 0; j < a; ++j)
                {
                    int beg, end;
                    // std::cin >> beg >> end;
                    scanf("%d%d", &beg, &end);
                    beg = decode(beg);
                    end = decode(end);
                    end = std::min(end, 43200);
                    ++ary[beg];
                    --ary[end];
                }
            }
#ifdef DEBUG
            for(int i = 0; i < 43200; ++i)
            {
                std::cout << ary[i] << " ";
            }
            std::cout << std::endl;
#endif  // DEBUG
            for(int i = 1; i < 43201; ++i)
            {
                ary[i] += ary[i - 1];
            }
            int a = 0, b = 0, c = 0;
            for(int i = 0; i < 43200; ++i)
            {
                if(ary[i] > 4)
                {
                    ++a;
                }
                else if(ary[i] == 0)
                {
                    if(i%1440 < 360 || i%1440 >= 1080)
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