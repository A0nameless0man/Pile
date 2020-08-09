#include <algorithm>
#include <iostream>

const int MAX_N = 1007;
const int MAX_W = 1007;

long long DP[2][MAX_N * MAX_W];
int       W[2][MAX_N];
long long V[2][MAX_N];
long long INF = 0x3f3f3f3f3f3f;
int       main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            int n[2];
            for(int i = 0; i < 2;++i)
            {
                std::cin >> n[i];
            }
            for(int i = 0; i < 2; ++i)
            {
                for(int j = 0; j < n[i];++j)
                {
                    std::cin >> W[i][j] >> V[i][j];
                }
                for(int j = 0; j < n[i];)
            }
        }
    }
}