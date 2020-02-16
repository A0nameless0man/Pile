#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main(void)
{
    int n, k, x;
    while(std::cin >> n >> k >> x)
    {
        std::vector<long long> vec;
        std::vector<long long> prefix, suffix;
        long long              ans = 0;
        for(int i = 0; i < n; ++i)
        {
            long long buf;
            scanf("%lld", &buf);
            vec.push_back(buf);
        }
        prefix = vec;
        suffix = vec;
        for(size_t i = 1; i < prefix.size(); ++i)
        {
            prefix[i] |= prefix[i - 1];
        }
        for(size_t i = suffix.size() - 2; ~i; --i)
        {
            suffix[i] |= suffix[i + 1];
        }
        for(size_t i = 0; i < vec.size(); ++i)
        {
            auto cur = vec[i];
            for(int j = 0; j < k; ++j)
            {
                cur *= x;
            }
            if(i>0)
            {
                cur |= prefix[i - 1];
            }
            if(i<vec.size()-1)
            {
                cur |= suffix[i + 1];
            }
            if(cur>ans)
            {
                ans = cur;
            }
        }
        std::cout << ans << std::endl;
    }
}
/*
Time: 2020-02-16 12:19:05
Describe: Greddy + PrefixSum
Statue: Upsolved
*/