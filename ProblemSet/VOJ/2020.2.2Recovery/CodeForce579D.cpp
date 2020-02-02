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
        for(int i = 0; i < n; ++i)
        {
            long long buf;
            scanf("%lld", &buf);
            vec.push_back(buf);
        }
        std::sort(vec.begin(), vec.end());
        for(int i = 0; i < k; ++i)
        {
            (*(vec.rbegin())) *= x;
        }
        long long ans = 0;
        for(auto i :vec)
        {
            ans |= i;
        }
        std::cout << ans << std::endl;
    }
}
