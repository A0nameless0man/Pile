#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
/*
Time: 2020-01-23 11:22:54
Describe: Accepted after corrected my lca
Statue: ACCEPTED
*/
#define ULL unsigned long long

using LL = int;

const LL MAX_N = 1000000;
// const LL    MAX_N = 10;
ULL         n;
char        s[MAX_N];
LL          sa[MAX_N];
LL          rnk[MAX_N];
LL          b[MAX_N];
LL          sum[MAX_N];
LL          h[MAX_N];
LL          st[MAX_N][30];
ULL         prefixVal[MAX_N];
ULL         pow10[MAX_N];
const ULL   MOD = 998244353;
inline bool c(ULL i, ULL j)
{
    return s[i] < s[j];
};
void buildSa(void)
{
    ULL n = strlen(s);
    for(ULL i = 0; i < n; ++i)
    {
        sa[i] = i;
    }
    std::sort(sa, sa + n, c);
    rnk[sa[0]] = 0;
    for(ULL i = 1; i < n; i++)
    {
        rnk[sa[i]] = rnk[sa[i - 1]];
        if(c(sa[i - 1], sa[i]))
        {
            rnk[sa[i]]++;
        }
    }
    for(ULL k = 1; rnk[sa[n - 1]] < n - 1; k <<= 1)
    {
        ULL m = 0;
        for(ULL i = n - k; i < n; i++)
        {
            b[m++] = i;
        }
        for(int i = 0; i < n; i++)
        {
            if(sa[i] >= k)
            {
                b[m++] = sa[i] - k;
            }
        }
        memset(sum, 0, sizeof(sum));
        for(ULL i = 0; i < n; i++)
        {
            sum[rnk[i]]++;
        }
        for(ULL i = 1; i < n; i++)
        {
            sum[i] += sum[i - 1];
        }
        for(ULL i = n - 1; ~i; i--)
        {
            sa[--sum[rnk[b[i]]]] = b[i];
        }
        std::swap(sum, rnk);
        rnk[sa[0]] = 0;
        for(ULL i = 1; i < n; i++)
        {
            rnk[sa[i]] = rnk[sa[i - 1]];
            if(sum[sa[i - 1]] < sum[sa[i]] || sa[i - 1] + k >= n
               || sum[sa[i - 1] + k] < sum[sa[i] + k])
            {
                rnk[sa[i]]++;
            }
        }
    }
    for(ULL i = 0, j = 0; i < n; i++)
    {
        if(j)
        {
            j--;
        }
        if(rnk[i] == n - 1)
        {
            continue;
        }
        while(i + j < n && sa[rnk[i] + 1] + j < n && s[i + j] == s[sa[rnk[i] + 1] + j])
        {
            j++;
        }
        h[rnk[i]] = st[rnk[i]][0] = j;
    }
    for(ULL i = 1; (1L << (i - 1)) < n; ++i)
    {
        for(ULL j = 0; j < n; ++j)
        {
            if((1L << (i - 1)) + j < n)
            {
                // st[j][i] = std::min(st[j][i - 1], st[j + (1 << i)][i - 1]);
                st[j][i] = std::min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
            }
            else
            {
                st[j][i] = st[j][i - 1];
            }
        }
    }
}

ULL LCA(ULL i, ULL j, ULL n = MAX_N)
{
    if(i == j)
    {
        return n - i;
    }
    if(i >= n || j >= n)
    {
        return 0;
    }
    ULL l = std::min(rnk[i], rnk[j]);
    ULL r = std::max(rnk[i], rnk[j]);
    --r;
    if(r != l)
    {
        ULL dis    = r - l;
        ULL logDis = 30;
        while((1L << logDis) > dis)
        {
            --logDis;
        }
        return std::min(st[l][logDis], st[r - (1 << logDis) + 1][logDis]);
    }
    else
    {
        return st[l][0];
    }
}

ULL ans[MAX_N];

bool comp(int i, int j)
{
    if(i == j)
    {
        return false;
    }
    /*
    S[0:i) + S[0:j) ? S[0:j) + S[0:i)
    */
    if(i < j)
    {
        /*
        S[0:j) ? S[i:j) + S[0:i)
        */
        auto lca = LCA(0, i, n);
        if(lca < j - i)
        {
            return rnk[0] < rnk[i];
        }
        else
        {
            return rnk[j - i] < rnk[0];
        }
    }
    else
    {
        auto lca = LCA(0, j, n);
        if(lca < i - j)
        {
            return rnk[j] < rnk[0];
        }
        else
        {
            return rnk[0] < rnk[i - j];
        }
    }
}

int main(void)
{
    while(scanf("%s", s) != EOF)
    {
        buildSa();
        n = strlen(s);
        std::vector<int> vec(n);
        {
            for(ULL i = 1; i <= n; ++i)
            {
                vec[i - 1] = i;
                // vec.push_back(i)
            }
#ifdef DEBUG
            for(ULL i = 0; i < n; ++i)
            {
                // vec[i] = i;
                std::cout << rnk[i] << " ";
            }
            std::cout << std::endl;
            for(ULL i = 0; i < n; ++i)
            {
                // vec[i] = i;
                std::cout << sa[i] << " ";
            }
            std::cout << std::endl;
            for(int j = 0; j < 3; ++j)
            {
                for(ULL i = 0; i < n; ++i)
                {
                    // vec[i] = i;
                    std::cout << st[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            for(ULL i = 0; i < n; ++i)
            {
                for(ULL j = 0; j < n; ++j)
                {
                    // vec[i] = i;
                    std::cout << LCA(i, j, n) << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            for(ULL i = 1; i <= n; ++i)
            {
                for(ULL j = 1; j <= n; ++j)
                {
                    // vec[i] = i;
                    std::cout << comp(i, j) << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
#endif
        }
        {
            std::sort(vec.rbegin(), vec.rend(), comp);
#ifdef DEBUG
            for(ULL i = 0; i < n; ++i)
            {
                std::cout << vec[i] << "-";
            }
            std::cout << std::endl;
            for(ULL i = 0; i < n; ++i)
            {
                for(ULL j = 0; j < vec[i]; ++j)
                {
                    std::cout << s[j];
                }
                std::cout << " ";
            }
            std::cout << std::endl;
            for(ULL i = 0; i < n; ++i)
            {
                for(ULL j = 0; j < vec[i]; ++j)
                {
                    std::cout << s[j];
                }
                // std::cout << " ";
            }
            std::cout << std::endl;
#endif
        }
        {  // ULL prefixVal[MAX_N];
           // ULL pow10[MAX_N];
            prefixVal[0] = (s[0] - '0') % MOD;
            pow10[0]     = 1;
            for(ULL i = 1; i < n; ++i)
            {
                prefixVal[i] = (prefixVal[i - 1] * 10 + s[i] - '0') % MOD;
            }
            for(ULL i = 1; i <= n; ++i)
            {
                pow10[i] = 10 * pow10[i - 1] % MOD;
            }

#ifdef DEBUG
            {
                for(ULL i = 0; i < n; ++i)
                {
                    std::cout << s[i] << " ";
                }
                std::cout << std::endl;
                for(ULL i = 0; i < n; ++i)
                {
                    std::cout << prefixVal[i] << " ";
                }
                std::cout << std::endl;
                for(ULL i = 0; i <= n; ++i)
                {
                    std::cout << pow10[i] << " ";
                }
                std::cout << std::endl;
            }
#endif  // DEBUG
        }
        {
            ULL ans = 0;
            // for(auto pos: vec)
            for(ULL i = 0; i < n; ++i)
            {
                ans = (ans * pow10[vec[i]] % MOD + prefixVal[vec[i] - 1]) % MOD;
#ifdef DEBUG
                std::cout << ans << " ";
#endif  // DEBUG
            }
#ifdef DEBUG
            std::cout << "\n";
#endif  // DEBUG
            std::cout << ans << std::endl;
        }
    }
    return 0;
}
/*
5105105
5
51
5105
51051
5105105
510510
510

5 51 ? 51 5 ok
51 5105 ? 5105 51 ok
5105105
*/