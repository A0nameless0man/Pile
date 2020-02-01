#include<cstdio>
#include<iostream>
#include<set>

int main(void)
{
    int t;
    while(std::cin>>t)
    {
        long long s, n, k;
        for(int i = 0; i < t;++i)
        {
            std::cin >> n >> s >> k;
            std::set<long long> up, down;
            for(long long i = std::max(1ll, s - k); i <= s;++i)
            {
                down.insert(i);
            }
            for(long long i  = s;i<=std::min(n,s+k);++i)
            {
                up.insert(i);
            }
            for(long long i = 0;i<k;++i)
            {
                long long buf;
                scanf("%lld", &buf);
                down.erase(buf);
                up.erase(buf);
            }
            long long ans = 1e9 + 7;
            if(!down.empty())
            {
                ans = std::min(ans, s - (*down.rbegin()));
            }
            if(!up.empty())
            {
                ans = std::min(ans, (*up.begin()) - s);
            }
            std::cout << ans << "\n";
        }
    }
}