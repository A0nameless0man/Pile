#include <iostream>
#include <vector>

using ULL = unsigned long long;

inline ULL pow(ULL pow, ULL base, const ULL mod)
{
    ULL ans = 1;
    while(pow)
    {
        if(pow & 1)
        {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        pow >>= 1;
    }
    return ans;
}

int main(void)
{
    ULL n, k;
    while(std::cin >> n >> k)
    {
        std::vector<ULL>              A(n), ans(n);
        std::vector<char>             vis(n, 0);
        std::vector<std::vector<ULL>> R;
        for(ULL i = 0; i < n; ++i)
        {
            std::cin >> A[i];
            --A[i];
        }
        for(ULL i = 0; i < n; ++i)
        {
            if(!vis[i])
            {
                ULL              cur = A[i];
                std::vector<ULL> r;
                r.push_back(i);
                while(cur != i)
                {
                    vis[cur] = 1;
                    r.push_back(cur);
                    cur = A[cur];
                }
                R.push_back(std::move(r));
            }
        }
        for(auto &r: R)
        {
            // ULL offset = pow(r.size() - 2, k, r.size());
            ULL offset;
            for(ULL i = 0; i < r.size(); ++i)
            {
                if((k * i) % r.size() == 1)
                {
                    offset = i;
                    break;
                }
            }
            for(ULL i = 0; i < r.size(); ++i)
            {
                // ans[r[(i + offset) % r.size()]] = r[i];
                ans[r[i]] = r[(i + offset) % r.size()];
                // ans[r[i]] = r[(i +r.size()- offset) % r.size()];
            }
#ifdef DEBUG
            // for(auto &r: R)
            // {
            std::cout << "offset:" << offset << std::endl;
            for(auto &e: r)
            {
                std::cout << e + 1 << " ";
            }
            std::cout << std::endl;
            // }
#endif  // DEBUG
        }
        for(auto pos: ans)
        {
            std::cout << pos + 1 << " ";
        }
        std::cout << std::endl;
    }
}
/*
3 998244353
2 3 1
5 998244353
1 3 5 2 4
5 998244353
4 5 1 2 3
5 998244353
2 3 1 5 4
5 998244353
2 3 4 5 1
7 998244353
4 2 6 5 7 3 1
7 998244353
1 4 5 3 6 7 2
6 998244353
2 3 4 5 6 1
*/

/*
3 1 2
1 3 5 2 4
2 3 4 5 1
3 1 2 5 4
3 4 5 1 2
4 2 6 5 7 3 1
1 7 4 2 3 5 6
6 1 2 3 4 5
*/