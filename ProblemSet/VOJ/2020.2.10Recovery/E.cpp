#include <algorithm>
#include <cstdio>
#include <iostream>
const long long MAX_N     = 1007;
const long long dir[4][2] = { { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };

long long input[MAX_N][MAX_N];
long long DP[4][MAX_N][MAX_N];

void upDate(long long &a, long long b)
{
    if(b > a)
    {
        a = b;
    }
}

int main(void)
{
    long long n, m;
    while(std::cin >> n >> m)
    {
        for(long long i = 0; i <= n + 1; ++i)
        {
            for(long long j = 0; j <= m + 1; ++j)
            {
                input[i][j] = 0;
                for(long long k = 0; k < 4; ++k)
                {
                    DP[k][i][j] = 0;
                }
            }
        }
        for(long long i = 1; i <= n; ++i)
        {
            for(long long j = 1; j <= m; ++j)
            {
                scanf("%lld", &input[i][j]);
            }
        }
        // for(long long k = 0; k < 4; ++k)
        for(long long i = 1; i <= n; ++i)
            for(long long j = 1; j <= m; ++j)
            {
                // DP[k][i][j] =
                //   std::max(DP[k][i][j + dir[k][1]], DP[k][i + dir[k][0]][j]) + input[i][j];
                DP[0][i][j] = std::max(DP[0][i - 1][j], DP[0][i][j - 1]) + input[i][j];  // _|
                DP[1][n - i + 1][j] = std::max(DP[1][n - i + 2][j], DP[1][n - i + 1][j - 1])
                                      + input[n - i + 1][j];  // /|
                DP[2][i][m - j + 1] = std::max(DP[2][i - 1][m - j + 1], DP[2][i][m - j + 2])
                                      + input[i][m - j + 1];  // |_
                DP[3][n - i + 1][m - j + 1] =
                  std::max(DP[3][n - i + 2][m - j + 1], DP[3][n - i + 1][m - j + 2])
                  + input[n - i + 1][m - j + 1];  //
            }
        long long ans = 0;
#ifdef DEBUG
        for(long long k = 0; k < 4; ++k)
        {
            for(long long i = 0; i <= n + 1; ++i)
            {
                for(long long j = 0; j <= m + 1; ++j)
                {
                    std::cout << DP[k][i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "-----------" << std::endl;
        }
#endif
        for(long long i = 2; i < n; ++i)
        {
            for(long long j = 2; j < m; ++j)
            {
                long long curans = 0;
                upDate(curans,
                       DP[0][i - 1][j] + DP[1][i][j - 1] + DP[2][i][j + 1] + DP[3][i + 1][j]);
                upDate(curans,
                       DP[0][i][j - 1] + DP[1][i + 1][j] + DP[2][i - 1][j] + DP[3][i][j + 1]);
                upDate(ans, curans);
#ifdef DEBUG
                std::cout << curans << " ";
#endif
            }
#ifdef DEBUG
            std::cout << std::endl;
#endif
        }
        std::cout << ans << std::endl;
    }
}