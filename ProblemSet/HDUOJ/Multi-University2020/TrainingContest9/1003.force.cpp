#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

std::vector<double>                            val;
std::vector<std::vector<std::tuple<int, int>>> points;

int main(void)
{
    int T;
    while(std::cin >> T)
    {
        val.clear();
        points.clear();
        points.resize(T);
        for(int t = 0; t < T; ++t)
        {
            // for(int scale = 1; scale < 20; ++scale)
            {
                long long m, n, k;
                k = t;
                m = 500000;
                n = 500000;
                // std::cin >> n >> m >> k;
                long long range = std::max(n, m) + 1;
                std::vector<char> used(range);
                long long         x = 0, y = 0;
                long long         sx = 0, sy = 0;
                while(x < range && y < range)
                {
                    used[x] = 1;
                    used[y] = 1;
                    sx += x;
                    sy += y;
                    // points[t].push_back(
                    //   std::make_tuple(x, y));
                    // std::cout << x << ":" << y <<
                    // std::endl;
                    ++x;
                    y += k + 2;
                    while(x < range && y < range
                          && (used[x] || used[y]))
                    {
                        ++x;
                        ++y;
                    }
                }
                // val.push_back(static_cast<double>(sy) /
                // sx); std::cout << static_cast<double>(sy)
                // / sx
                //           << " ";
                printf("%10F %10F",
                       static_cast<double>(sy) / sx,
                       static_cast<double>(sx) / (sy - sx));
            }
            std::cout << std::endl;
        }
        // int l = -10;
        // int r = 10;
        // for(int a = 0; a <= r; ++a)
        // {
        //     for(int b = 0; b <= r; ++b)
        //     {
        //         for(int c = l; c <= r; ++c)
        //         {
        //             for(int d = l; d <= r; ++d)
        //             {
        //                 for(int e = l; e <= r; ++e)
        //                 {
        //                     for(int f = l; f <= r; ++f)
        //                     {
        //                         char flag = true;
        //                         for(int k = 0;
        //                             k < T && flag;
        //                             ++k)
        //                         {
        //                             double ans =
        //                               sqrt(a + b * k) / c
        //                               +
        //                               static_cast<double>(
        //                                   d + e * k)
        //                                   / f;
        //                             for(size_t i = 0;
        //                                 i <
        //                                 points[k].size()
        //                                 && i < 10;
        //                                 ++i)
        //                             {
        //                                 int x = ans * i;
        //                                 int y =
        //                                   ans * ans * i;
        //                                 if(std::make_tuple(
        //                                      x,
        //                                      y)
        //                                    !=
        //                                    points[k][i])
        //                                 {
        //                                     flag = false;
        //                                 }
        //                             }
        //                         }
        //                         if(flag)
        //                         {
        //                             std::cout
        //                               << a << " " << b
        //                               << " " << c << " "
        //                               << d << " " << e
        //                               << " " << f << " "
        //                               << std::endl;
        //                         }
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        std::cout << "finish" << std::endl;
    }
}