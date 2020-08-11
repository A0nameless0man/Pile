#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main(void)
{
    int T;
    while(scanf("%d", &T) != EOF)
    {
        for(int t = 0; t < T; ++t)
        {
            int n, l;
            std::cin >> n >> l;
            std::vector<int> v(n);
            for(int i = 0; i < n; ++i)
            {
                v[i] = (i <= ((n - 1) / 2) ? (1 + i * 2)
                                           : (n - i) * 2);
            }
#ifdef DEBUG
            for(int i = 0; i < n; ++i)
            {
                std::cout << v[i] << " ";
            }
            std::cout << std::endl;
            for(int i = 0; i < n - l; ++i)
            {
                std::cout << v[i] << " ";
            }
            std::cout << std::endl;
#endif  // DEBUG
        }
    }
}