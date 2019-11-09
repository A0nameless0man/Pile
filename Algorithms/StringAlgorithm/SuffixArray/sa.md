```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define ULL  unsigned long long
const ULL MAX_N = 10000007;
char s[MAX_N];
ULL sa[MAX_N];
ULL rnk[MAX_N];
ULL b[MAX_N];
ULL sum[MAX_N];
ULL h[MAX_N];
inline bool c(ULL i, ULL j) { return s[i] < s[j]; };
void buildSa(void)
{
    ULL n = strlen(s);
    for (ULL i = 0; i < n; i++)
    {
        sa[i] = i;
    }
    std::sort(sa, sa + n, c);
    rnk[sa[0]] = 0;
    for (ULL i = 0; i < n; i++)
    {
        rnk[sa[i]] = rnk[sa[i - 1]];
        if(c(sa[i - 1], sa[i]))
        {
            rnk[sa[i]]++;
        }
    }
    for (ULL k = 1; rnk[sa[n - 1]] < n - 1; k <<= 1)
    {
        ULL m = 0;
        for (ULL i = n - k; i < n; i++)
        {
            b[m++] = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (sa[i] >= k)
            {
                b[m++] = sa[i] - k;
            }
        }
        memset(sum, 0, sizeof(sum));
        for (ULL i = 0; i < n; i++)
        {
            sum[rnk[i]]++;
        }
        for (ULL i = 1; i < n; i++)
        {
            sum[i] += sum[i - 1];
        }
        for (ULL i = n - 1; ~i; i--)
        {
            sa[--sum[rnk[b[i]]]] = b[i];
        }
        std::swap(sum, rnk);
        rnk[sa[0]] = 0;
        for (ULL i = 1; i < n; i++)
        {
            rnk[sa[i]] = rnk[sa[i - 1]];
            if(sum[sa[i - 1]] < sum[sa[i]] || sa[i - 1] + k >= n || sum[sa[i - 1] + k] < sum[sa[i] + k])
            {
                rnk[sa[i]]++;
            }
        }
    }
    for (ULL i = 0, j = 0; i < n; i++)
    {
        if (j)
        {
            j--;
        }
        if (rnk[i] == n - 1)
        {
            continue;
        }
        while (s[i + j] == s[sa[rnk[i] + 1] + j])
        {
            j++;
        }
        h[rnk[i]] = j;
    }
}
int main(void)
{
    scanf("%s", s);
    buildSa();
    ULL n = strlen(s);
    for (ULL i = 0; i < n; i++)
        printf("%llu ", sa[i] + 1);
    printf("\n");
    for (ULL i = 0; i < n - 1; i++)
        printf("%llu ", h[i]);
    printf("\n");
    return 0;
}
```