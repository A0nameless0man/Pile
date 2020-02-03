#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>

int main(void)
{
    int n, m;
    while(std::cin >> n >> m)
    {
        std::vector<std::vector<int>> matrix;
        std::vector<std::vector<int>> raw;
        long long                     ans = 0;
        matrix.resize(n);
        raw.resize(n);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int buf;
                scanf("%d", &buf);
                matrix[i].push_back(buf);
                raw[i].push_back(j + m * i + 1);
            }
        }
        for(int i = 0; i < m; ++i)
        {
            long long                     partAns = n;
            std::vector<std::vector<int>> posRec;
            std::vector<int>              gain;
            gain.resize(n);
            for(int j = 0; j < n; ++j)
            {
                auto nxt = matrix[j][i];
                if((nxt - 1) % m == i && (nxt - 1) / m < n)
                {
                    ++gain[(j - (nxt - 1) / m + n) % n];
                }
            }
            for(int j = 0; j < n; ++j)
            {
                gain[j] -= j;
            }
            partAns -= *(std::max_element(gain.begin(), gain.end()));
            ans += partAns;
            // std::cout << partAns << std::endl;
        }
        std::cout << ans << std::endl;
    }
}