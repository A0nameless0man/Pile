#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>

using ULL = unsigned long long;
/*
Time: 2020-01-23 11:30:01
Describe: time complexity isn't good enough
Statue: TIME LIMIT EXCITED
*/
const ULL MOD = 998244353;

inline int log2(ULL i)
{
    int ans = 1;
    while(i >> ans)
        ++ans;
    return ans - 1;
}

inline ULL first1(ULL i)
{
    if(i)
        return 1 << log2(i);
    else
        return 0;
}

inline ULL before(ULL i, int offset)
{
    return (i >> offset) << offset;
}

bool is2pow(ULL i)
{
    return i == first1(i);
}

ULL square(ULL i)
{
    return i * i % MOD;
}

int main(void)
{
    // std::cout << "beg" << std::endl;
    ULL n, q;
    // scanf("%d", &n);
    while(scanf("%lld%lld", &n, &q) != EOF)
    {
        std::map<ULL, ULL>           elementCount;
        std::unordered_map<ULL, ULL> contribution;
        std::unordered_map<ULL, ULL> prefixCnt;
        {  // input
            for(ULL i = 0; i < n; ++i)
            {
                ULL a;
                // std::cin >> a;
                scanf("%lld", &a);
                ++elementCount[a];
            }
            ++elementCount[(1 << 31)];
        }
        // std::cout << "readed" << std::endl;

        // if(false)
        {  // saffix
            ULL segmaCon = 0;
            ULL segmaCnt = 0;
            ULL lastPos  = 0;
            for(auto it: elementCount)
            {
                segmaCon = contribution[it.first] =
                  (segmaCon + (it.first - lastPos - 1) * (square(segmaCnt))
                   + square(segmaCnt + it.second))
                  % MOD;
                prefixCnt[it.first] = segmaCnt;
                lastPos             = it.first;
                segmaCnt += it.second;
            }
        }
        // std::cout << "pre" << std::endl;

        {
            auto pairQuery = [&](ULL l, ULL r) -> ULL {
                // return 0;
                if(l > r)
                {
                    std::swap(l, r);
                }
                // std::cout << "Pair" << l << " " << r << std::endl;
                // l<=lit.first<=r<=rit.first;
                //
                //+(lit.first,rit.first]=rit.second-lit.second
                //+[l,lit.first)=(lit.first-l)*square(lpcnt)=>[l,lit)(lit,rit]
                //+[lit.first,lit.first]=square(lpcnt+lcnt)=>[l,rit]
                //-(r,rit.first)=(rit.first -r-1)*square(rpcnt)
                //-[rit.first,rit.first]=square(rpcnt+rcnt)
                // auto lit = contribution.lower_bound(l);
                // auto rit = contribution.lower_bound(r);

                auto itl = elementCount.lower_bound(l);
                auto itr = elementCount.lower_bound(r);
                if(itl->second == (1 << 31))
                {
                    return 0;
                }

                auto lbound = itl->first;
                auto rbound = itr->first;
                auto lpcnt  = prefixCnt[lbound];
                auto rpcnt  = prefixCnt[rbound];
                auto lcnt   = itl->second;
                auto rcnt   = itr->second;
                auto lit    = contribution[lbound];
                auto rit    = contribution[rbound];
                ULL  ans    = 0;
                ans += rit - lit;
                // ans %= MOD;
                ans += (lbound - l) * square(lpcnt);
                // ans %= MOD;
                ans += square(lpcnt + lcnt);
                if(r != rbound)
                {
                    //-(r,rit.first)=(rit.first -r-1)*square(rpcnt)
                    //-[rit.first,rit.first]=square(rpcnt+rcnt)
                    // ans %= MOD;
                    ans -= (((rbound - r - 1) * square(rpcnt)));
                    // ans %= MOD;
                    ans -= ((square(rpcnt + rcnt)));
                }
                ans %= MOD;
                // std::cout << "ans: " << ans << std::endl;
                return ans;
            };
            auto xorQuery = [&](ULL l, ULL r, ULL x) -> ULL {
                // make every pair match r-l = 2^k-1,k<__builtin_ffsll(r)-1
                // ++r;
                // return 0;
                ULL ans = 0;
                // ULL cnt = 0;
                if(l == 0)
                {
                    ans += pairQuery(x, x);
                    // ++cnt;
                    l = 1;
                }
                while(l < r)
                {
                    int k = __builtin_ctzll(l);
                    while(r < l + (1 << k) - 1)
                    {
                        --k;
                    }
                    ULL next = l + (1 << k);
                    ULL px   = before(x, k);
                    ans += pairQuery(l ^ px, (next - 1) ^ px);
                    // ++cnt;
                    ans %= MOD;
                    l = next;
                }
                if(l == r)
                {
                    ans += pairQuery(l ^ x, l ^ x);
                    // ++cnt;
                }
                ans %= MOD;
                // std::clog << cnt << std::endl;
                return ans;
            };
            for(ULL qi = 0; qi < q; ++qi)
            {  // query
                ULL l, r, x;
                // std::cin >> l >> r >> x;
                scanf("%lld%lld%lld", &l, &r, &x);
                // std::cout << xorQuery(l, r, x) << std::endl;
                printf("%lld", xorQuery(l, r, x));
                putchar('\n');
            }
        }
        // for(auto i: contribution)
        // {
        //     std::cout << i.first << " " << i.second << std::endl;
        // }

        // acm.debug();
    }
    return 0;
}
/*
4 7 1 2 3 4
2 3 0
1 10 0
1 11 0
1 12 0
1 15 0
1 16 0
1 17 0
*/