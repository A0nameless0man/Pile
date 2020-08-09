#include <algorithm>
#include <cstdio>
#include <vector>

int mian(void)
{
    int T;
    while(std::cin >> T)
    {
        int n;
        std::cin >> n;
        std::vector<long long> vecs;
        std::vector<long long> vecm;
        for(int i = 0; i < n; ++i)
        {
            int h, m, s;
            scanf("%d:%d:%d", &h, &m, &s);
            vech.push_back(3600 * h + 60 * m + s);
            vecm.push_back((60 * m + s) * 60);
        }
        std::sort(vech.begin(), vech.end());
        std::sort(vecm.begin(), vecm.end());
        
    }
}