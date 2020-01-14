#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

#define ULL unsigned long long

const ULL   MAX_N = 10000007;
char        s[MAX_N];
ULL         sa[MAX_N];
ULL         rnk[MAX_N];
ULL         b[MAX_N];
ULL         sum[MAX_N];
ULL         h[MAX_N];
inline bool c(ULL i, ULL j)
{
    return s[i] < s[j];
};
void buildSa(void)
{
    ULL n = strlen(s);
    for(ULL i = 0; i < n; i++)
    {
        sa[i] = i;
    }
    std::sort(sa, sa + n, c);
    rnk[sa[0]] = 0;
    for(ULL i = 0; i < n; i++)
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
            if(sum[sa[i - 1]] < sum[sa[i]] || sa[i - 1] + k >= n ||
               sum[sa[i - 1] + k] < sum[sa[i] + k])
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
        h[rnk[i]] = j;
    }
}

ULL ans[MAX_N];

int main(void)
{
    while(scanf("%s", s) != EOF)
    {
        buildSa();
        ULL             n = strlen(s);
        std::stack<ULL> st;
        for(ULL i = n - 1; ~i; --i)
        {
            while(!st.empty() && rnk[st.top()] > rnk[i])
            {
                st.pop();
            }
            ans[i] = (st.empty()) ? n : st.top();
            if(st.empty() || rnk[st.top()] < rnk[i])
            {
                st.push(i);
            }
        }

        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; ++i)
        {
            int l, k;
            scanf("%d%d", &l, &k);
            if(k > 1)
            {
                // printf("%d %lld\n", l, ans[l-1]);
                ULL saffixWide = ans[l - 1] - l + 1;
                // if(rnk[l-1]!=0)
                // {
                //     std::cout << "$" << h[rnk[l - 1] - 1] << std::endl;
                // }
                if(rnk[l-1]!=0 && h[rnk[l - 1] - 1] < saffixWide)
                {
                    std::cout << l << " " << ans[l - 1] << std::endl;
                }
                else
                {
                    ULL hz  = h[rnk[l - 1] - 1] / saffixWide + 1;
                    ULL len = ((hz - 1) / k + 1) * saffixWide;
                    // std::cout << "#" << h[rnk[l - 1] - 1] << std::endl;
                    // std::cout << "*" << saffixWide << " " << hz << " " << len << std::endl;
                    if(hz % k == 0 && hz * saffixWide != n - l + 1)
                    {
                        // std::cout << "A" << std::endl;
                        std::cout << l + hz * saffixWide -len<< " " << n << std::endl;
                    }
                    else
                    {
                        // std::cout << "B" << std::endl;
                        std::cout << l << " " << l + len - 1 << std::endl;
                    }
                }
            }
            else
            {
                // printf("%d %lld\n", l, n);
                std::cout << l << " " << n << std::endl;
            }
        }
    }

    return 0;
}
/*
ababababab
|/|/|/|/|
  |/|/|/| K related cell(len/(k*t))*t

|-|?|-|00
  |?|-|00 ! floor(hz/2)*t~n

*|-|-|-|zz \/-
*  |-|-|zz
abababa 1 1 3
ababa 1 1 2
ababa 1 1 3

*/

/*
ababab

ab    |2||||
abab  |4||||
ababab|0||||
b     |1||||
bab   |3||||
babab |0||||

*/