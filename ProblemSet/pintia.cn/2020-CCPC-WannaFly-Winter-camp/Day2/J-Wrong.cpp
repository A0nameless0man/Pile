#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

#define ULL unsigned long long

using LL = int;

const LL    MAX_N = 10000007;
char        s[MAX_N];
LL          sa[MAX_N];
LL          rnk[MAX_N];
LL          b[MAX_N];
LL          sum[MAX_N];
LL          h[MAX_N];
LL          st[MAX_N][30];
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
        st[rnk[i]][0] = j;
    }
    for(ULL i = 1; i < n; i <<= 1)
    {
        for(ULL j = 0; j < n; ++j)
        {
            if((1 >> i) + j < n)
            {
                st[j][i] = std::min(st[j][i - 1], st[j + (1 << i)][i - 1]);
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
        return std::min(st[l][logDis], st[r - (1 << logDis)][logDis]);
    }
    else
    {
        return st[l][0];
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
            ULL prefixWide = ans[l - 1] - (l - 1);
            ULL lca        = LCA(l - 1, l + prefixWide - 1);
            ULL hz         = lca / prefixWide + 1;
            ULL upperLen   = ((hz - 1) / k + 1) * prefixWide;
            ULL lowerLen   = ((hz) / k) * prefixWide;
            ULL allLen     = hz * prefixWide;
            // if(hz >= k && hz % k == 0 && l + hz * prefixWide - 1 != n)  //整除
            if(n != l + allLen - 1)
            {
                if(hz % k != 0)
                {
                    std::cout << l << " " << l + upperLen - 1 << std::endl;
                }
                else
                {
                    std::cout << l + hz * prefixWide - lowerLen << " " << n << std::endl;
                }
            }
            else
            {
                std::cout << l << " " << l + upperLen - 1 << std::endl;
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

/*
if(s<all suffix of s)
s is Lyndon

every char is a substring

merge any sub string when s_i<s_(i+1)

must cut on Lyndon

so it's like sub_1^(p_1)+sub_2^(p_2) ...

as we know,sub_1>sub_2

that is sub_1+sub_2>sub_2 ,and this will do no harm to our ans
*/