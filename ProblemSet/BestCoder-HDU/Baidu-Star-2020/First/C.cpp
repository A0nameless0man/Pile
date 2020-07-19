#include <algorithm>
#include <cstdio>
#include <iostream>

const int MAX_N = 1<<14;

int p[MAX_N][MAX_N];
// int **p;
// int cnt[MAX_N][MAX_N];

int main(void)
{
    // for(int i = 0; i < MAX_N; ++i)
    // {
    //     p[i] = static_cast<int *>(malloc(sizeof(int) * MAX_N));
    // }
    p[0][0] = 0;
    for(int i = 1; i < MAX_N; ++i)
    {
        p[0][i] = 0;
        p[i][0] = 0;
        for(int j = 1; j < MAX_N; ++j)
        {
            p[i][j] = 1;
        }
    }
    for(int i = 1; i < MAX_N; ++i)
    {
        for(int j = 1; j < MAX_N; ++j)
        {
            if(p[i][j])
            {
                for(int k = 2; i * k <= 1000 && j * k <= 1000; ++k)
                {
                    p[i * k][j * k] = 0;
                }
            }
        }
    }
    for(int i = 1; i < MAX_N; ++i)
    {
        for(int j = 1; j < MAX_N; ++j)
        {
            p[i][j] += std::max(p[i - 1][j], p[i][j - 1]);
#ifdef DEBUG
            if(p[i][j] == 19260817)
                std::cout << "p[" << i << "][" << j << "]=" << p[i][j] << "\n";
#endif
        }
    }

    int t;
    while(std::cin >> t)
    {
        for(int i = 0; i < t; ++i)
        {
            int a, b;
            // std::cin >> a >> b;
            scanf("%d%d", &a, &b);
            // std::cout << p[a][b] << std::endl;
            printf("%d\n", p[a][b]);
#ifdef DEBUG
            // for(int i = 1; i <= a; ++i)
            // {
            //     for(int j = 1; j <= b; ++j)
            //     {
            //         // p[i][j] += std::max(p[i - 1][j], p[i][j - 1]);
            //         std::cout << p[i][j] << " ";
            //     }
            //     std::cout << std::endl;
            // }
#endif  // DEBUG
        }
    }
}