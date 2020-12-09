#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    while(true)
    {
        int n = 0;
        std::cin >> n;
        if(std::cin.eof())
        {
            break;
        }
        std::vector<int> N, M;
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            std::cin >> tmp;
            N.push_back(tmp);
        }
        int m = 0;
        std::cin >> m;
        for(int i = 0; i < m; ++i)
        {
            int tmp;
            std::cin >> tmp;
            M.push_back(tmp);
        }
        int a, b;
        std::cin >> a >> b;
        std::sort(N.begin(), N.end());
        std::sort(M.begin(), M.end());
        int an =
          N.end() - std::lower_bound(N.begin(), N.end(), a);
        int bn =
          N.end() - std::lower_bound(N.begin(), N.end(), b);
        int am =
          M.end() - std::lower_bound(M.begin(), M.end(), a);
        int bm =
          M.end() - std::lower_bound(M.begin(), M.end(), b);

        std::cout << std::min(std::min(an + bm, am + bn),
                              std::min(an + bn, am + bm)
                                + 1)
                       + 2
                  << std::endl;
    }
}