#include <iostream>

int g[5000][5000];

int main(void)
{
    int n, m, a, b;
    while(std::cin >> n >> m >> a >> b)
    {
        int disx = b - m + 1;
        int disy = a - n + 1;
        for(int i = 0; i < a; ++i)
        {
            for(int j = 0; j < b; ++j)
            {
                g[i][j] = 0;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int cur;
                std::cin >> cur;
                if(cur)
                {
                    int poi = i + disy;
                    int poj = j + disx;
                    ++g[i][j];
                    ++g[poi][poj];
                    --g[i][poj];
                    --g[poi][j];
                }
            }
        }
        for(int i = 1; i < a; ++i)
        {
            for(int j = 0; j < b; ++j)
            {
                g[i][j] += g[i - 1][j];
            }
        }
        for(int i = 0; i < a; ++i)
        {
            for(int j = 1; j < b; ++j)
            {
                g[i][j] += g[i][j - 1];
            }
        }
        int max = 0;
        for(int i = 0; i < a; ++i)
        {
            for(int j = 0; j < b; ++j)
            {
                if(g[i][j] > max)
                {
                    max = g[i][j];
                }
                // g[i][j] = 0;
                // std::cout << g[i][j] << " ";
            }
            // std::cout << std::endl;
        }
        for(int i = 0; i < a; ++i)
        {
            for(int j = 0; j < b; ++j)
            {
                std::cout << g[i][j] * 100 / max << " ";
            }
            std::cout << std::endl;
        }
    }
}