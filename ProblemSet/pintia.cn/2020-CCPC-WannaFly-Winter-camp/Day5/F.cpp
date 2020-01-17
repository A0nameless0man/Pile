#include <iostream>

const long long MAX_N = 5000;

long long cnt[MAX_N][2];

long long square(long long i)
{
    return i * i;
}

int main(void)
{
    long long n, a, b, c, p, d;
    while(std::cin >> n >> a >> b >> c >> p >> d)
    {
        for(long long i = 0; i < n; ++i)
        {
            cnt[i][0] = cnt[i][1] = 0;
        }
        for(long long i = 0; i < n; ++i)
        {
            for(long long j = 0; j < i; ++j)
            {
                bool color = ((a * square(i + j+2) + b * square(j - i) + c) % p > d);
                ++cnt[i][color];
                ++cnt[j][color];
                // std::cout << color;
            }
            // std::cout << std::endl;
        }
        long long sum = 0;
        for(long long i = 0; i < n; ++i)
        {
            sum += cnt[i][0] * cnt[i][1];
            // std::cout << cnt[i][0] << " " << cnt[i][1] << std::endl;
        }
        sum /= 2;
        long long all = n * (n - 1) * (n - 2) / 6;
        std::cout << all - sum << std::endl;

        // std::cout << sum << std::endl;
        // std::cout << all << std::endl;
        // {
        //     long long fcnt[MAX_N] = { 0 };
        //     for(long long i = 0; i < n; ++i)
        //     {
        //         fcnt[i] = 0;
        //     }
        //     auto cor = [&](long long i, long long j) -> bool {
        //         return ((a * square(i + j+2) + b * square(j - i) + c) % p > d);
        //     };
        //     std::cout << "Force Begin" << std::endl;
        //     for(long long i = 0; i < n; ++i)
        //     {
        //         for(long long j = 0; j < i; ++j)
        //         {
        //             for(long long k = 0; k < j; ++k)
        //             {
        //                 long long sta = cor(i, j) + cor(j, k) + cor(i, k);
        //                 if(sta == 0 || sta == 3)
        //                 {
        //                     std::cout << i << " " << j << " " << k << std::endl;
        //                 }
        //                 else
        //                 {
        //                     if(cor(i, j) ^ cor(j, k))
        //                     {
        //                         fcnt[j]++;
        //                     }
        //                     if(cor(i, j) ^ cor(i, k))
        //                     {
        //                         {
        //                             fcnt[i]++;
        //                         }
        //                     }
        //                     if(cor(j, k) ^ cor(i, k))
        //                     {
        //                         fcnt[k]++;
        //                     }
        //                 }
        //             }
        //         }

        //     }
        //         for(long long i = 0; i < n; ++i)
        //         {
        //             std::cout << fcnt[i] << std::endl;
        //         }
        //     std::cout << "Force End" << std::endl;
        // }
    }
}
/*
\10011
1\0000
00\001
000\10
1001\0
10100\

2 3 6
4 1 4
4 1 4
4 1 4
3 2 6
3 2 6
*/