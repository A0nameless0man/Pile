#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <iostream>
const int          MAX_N = 1007;
unsigned long long M[MAX_N][MAX_N];
unsigned long long qsqrt(unsigned long long n)
{
    unsigned long long l = 1, r = n;
    while(l < r)
    {
        unsigned long long mid = (l + r) / 2;
        if(mid * mid < n)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}
int main(void)
{
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // std::cin >> M[i][j];
            scanf("%lld", &M[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        int j = (i + 1) % n, k = (i + 2) % n;
        std::cout << (long long) sqrt((M[i][j] * M[i][k]) / M[j][k]) << " ";
    }
    std::cout << std::endl;
}