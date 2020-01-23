#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
/*
Time: 2020-01-23 11:22:54
Describe: Accepted after corrected my lca
Statue: ACCEPTED
*/
#define ULL unsigned long long

using LL = int;

const LL    MAX_N = 1000000;
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

ULL LCA(ULL i, ULL j, ULL n = 0xfffff)
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

            // std::cout << l << "#" << k << std::endl;
            // std::cout << "&" << n << std::endl;
            // if(ans[l-1]==n)
            // {
            //     std::cout << l << " " << n << std::endl;
            //     continue;
            // }
            ULL  prefixWide = ans[l - 1] - (l - 1);
            ULL  lca        = LCA(l - 1, l + prefixWide - 1, n);
            ULL  hz         = lca / prefixWide + 1;
            ULL  upperLen   = ((hz - 1) / k + 1) * prefixWide;
            ULL  lowerLen   = ((hz) / k) * prefixWide;
            ULL  allLen     = hz * prefixWide;
            bool tail       = (n != l + allLen - 1);
            // if(hz >= k && hz % k == 0 && l + hz * prefixWide - 1 != n)  //整除
            // if(n != l + allLen - 1)
            // {
            //     if(hz % k != 0)
            //     {
            //         if(hz < k)
            //         {
            //             std::cout << l << " " << l + prefixWide - 1 << std::endl;
            //         }
            //         else
            //         {
            //             std::cout << l << " " << l + upperLen - 1 << std::endl;
            //         }
            //     }
            //     else
            //     {
            //         std::cout << l + hz * prefixWide - lowerLen << " " << n << std::endl;
            //     }
            // }
            // else
            // {
            //     std::cout << l << " " << l + upperLen - 1 << std::endl;
            // }
            if(k == 1)
            {
                std::cout << l << " " << n << '\n';
            }
            else if(hz < k)
            {
                std::cout << l << " " << l + prefixWide - 1 << '\n';
            }
            else
            {
                if(hz % k == 0)
                {
                    if(!tail)
                    {
                        std::cout << l << " " << l + lowerLen - 1 << '\n';
                    }
                    else
                    {
                        std::cout << l + allLen - lowerLen << " " << n << '\n';
                    }
                }
                else
                {
                    std::cout << l << " " << l + upperLen - 1 << '\n';
                }
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

/*
abababab
2
8 3
8 4
*/
/*
accddcaaad 1 9 1
accddcaaad 64 1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10 2 1 2 2 2 3 2 4 2 5 2 6 2 7 2 8 2 9 2 10 3 1
3 2 3 3 3 4 3 5 3 6 3 7 3 8 3 9 3 10 4 1 4 2 4 3 4 4 4 5 4 6 4 7 4 8 4 9 4 10 5 1 5 2 5 3 5 4 5 5 5
6 5 7 5 8 5 9 5 10 6 1 6 2 6 3 6 4 6 5 6 6 6 7 6 8 6 9 6 10 7 1 7 2 7 3 7 4 7 5 7 6 7 7 7 8 7 9 7 10
8 1 8 2 8 3 8 4 8 5 8 6 8 7 8 8 8 9 8 10
*/