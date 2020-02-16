#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using ULL = unsigned long long;

using LL = int;

const LL MAX_N = 100007;

template <class T>
struct Comp
{
    T *t;
    Comp(T ta[]): t(ta) {}
    bool operator()(ULL i, ULL j)
    {
        return t[i] < t[j];
    }
};

struct SA
{
    char        s[MAX_N];
    LL          sa[MAX_N];
    LL          rnk[MAX_N];
    LL          b[MAX_N];
    LL          sum[MAX_N];
    LL          h[MAX_N];
    LL          st[MAX_N][30];
    ULL         n;
    inline bool c(ULL i, ULL j)
    {
        return s[i] < s[j];
    };
    void buildSa(void)
    {
        n = strlen(s);
        for(ULL i = 0; i < n; ++i)
        {
            sa[i] = i;
        }
        std::sort(sa, sa + n, Comp(s));
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
        for(ULL i = 1; (1 << (i - 1)) < n; ++i)
        {
            for(ULL j = 0; j < n; ++j)
            {
                if((1 << (i - 1)) + j < n)
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

    ULL LCA(ULL i, ULL j)
    {
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
            ULL logDis = 15;
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
};

SA both, a, b;

int main(void)
{
    while(scanf("%s%s", a.s, b.s) != EOF)
    {
        a.buildSa();
        b.buildSa();
        {
            ULL i = 0;
            while(i < a.n)
            {
                both.s[i] = a.s[i];
                ++i;
            }
            // both.s[i] = 'a' - 1;
            both.s[i] = 'z' + 1;
            ++i;
            for(ULL j = 0; j < b.n; ++j)
            {
                both.s[i + j] = b.s[j];
            }
            both.s[i + b.n] = '\0';
        }
        both.buildSa();
#ifdef DEBUG
        for(ULL i = 0; i < a.n; ++i)
        {
            printf("%d ", a.rnk[i]);
        }
        printf("\n");
        for(ULL i = 0; i < a.n; ++i)
        {
            printf("%s\\%d\n", &a.s[a.sa[i]], a.h[i]);
        }
        for(ULL i = 0; i < b.n; ++i)
        {
            printf("%d ", b.rnk[i]);
        }
        printf("\n");
        for(ULL i = 0; i < b.n; ++i)
        {
            printf("%s\\%d\n", &b.s[b.sa[i]], b.h[i]);
        }
        for(ULL i = 0; i < both.n; ++i)
        {
            printf("%d ", both.rnk[i]);
        }
        printf("\n");
        for(ULL i = 0; i < both.n; ++i)
        {
            printf("%s\\%d\n", &both.s[both.sa[i]], both.h[i]);
        }
        printf("\n");
#endif  // DEBUG
        int minlena[MAX_N], minlenb[MAX_N];
        {
            for(int i = 0; i < a.n; ++i)
            {
                auto r = a.rnk[i];
                auto m     = (r != a.n - 1) ? a.h[r] : 0;
                auto n     = (r != 0) ? a.h[r - 1] : 0;
                minlena[i] = std::max(m, n);
                if(minlena[i] + i == a.n)
                {
                    minlena[i] = 0xffffff;
                }
            }
            for(int i = 0; i < b.n; ++i)
            {
                auto r = b.rnk[i];
                auto m     = (r != b.n - 1) ? b.h[r] : 0;
                auto n     = (r != 0) ? b.h[r - 1] : 0;
                minlenb[i] = std::max(m, n);
                if(minlenb[i] + i == b.n)
                {
                    minlenb[i] = 0xffffff;
                }
            }
        }
        int ans = 0xffffff;
        {
            for(int i = 0; i < a.n; ++i)
            {
                for(int j = 0; j < b.n; ++j)
                {
                    auto lca = both.LCA(i, a.n + 1 + j);
                    if(lca < ans)
                    {
                        auto d = std::max(minlena[i], minlenb[j]);
                        ++d;
#ifdef DEBUG
                        printf("%s %s lca:%d d:%d di:%d dj:%d\n",
                               &a.s[i],
                               &b.s[j],
                               lca,
                               d,
                               minlena[i],
                               minlenb[j]);
#endif  // DEBUG
                        if(d <= lca)
                        {
                            ans = d;
                        }
                    }
                }
            }
        }
        if(ans == 0xffffff)
        {
            ans = -1;
        }
        std::cout << ans << std::endl;
    }
}
