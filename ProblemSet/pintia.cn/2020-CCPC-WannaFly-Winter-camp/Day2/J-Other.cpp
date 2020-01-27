// #include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<set>
#include<cstring>

using namespace std;
typedef long long ll;
const int         N = 2e5 + 10;
char              s[N];
int               len[N], cnt[N];

const int LOGN = 17;

namespace SA
{
int sa[N], rk[N], ht[N], s[N << 1], t[N << 1], p[N], cnt[N], cur[N];
#define pushS(x) sa[cur[s[x]]--] = x
#define pushL(x) sa[cur[s[x]]++] = x
#define inducedSort(v)                 \
    fill_n(sa, n, -1);                 \
    fill_n(cnt, m, 0);                 \
    for(int i = 0; i < n; i++)         \
        cnt[s[i]]++;                   \
    for(int i = 1; i < m; i++)         \
        cnt[i] += cnt[i - 1];          \
    for(int i = 0; i < m; i++)         \
        cur[i] = cnt[i] - 1;           \
    for(int i = n1 - 1; ~i; i--)       \
        pushS(v[i]);                   \
    for(int i = 1; i < m; i++)         \
        cur[i] = cnt[i - 1];           \
    for(int i = 0; i < n; i++)         \
        if(sa[i] > 0 && t[sa[i] - 1])  \
            pushL(sa[i] - 1);          \
    for(int i = 0; i < m; i++)         \
        cur[i] = cnt[i] - 1;           \
    for(int i = n - 1; ~i; i--)        \
        if(sa[i] > 0 && !t[sa[i] - 1]) \
    pushS(sa[i] - 1)
void sais(int n, int m, int *s, int *t, int *p)
{
    int n1 = t[n - 1] = 0, ch = rk[0] = -1, *s1 = s + n;
    for(int i = n - 2; ~i; i--)
        t[i] = s[i] == s[i + 1] ? t[i + 1] : s[i] > s[i + 1];
    for(int i = 1; i < n; i++)
        rk[i] = t[i - 1] && !t[i] ? (p[n1] = i, n1++) : -1;
    inducedSort(p);
    for(int i = 0, x, y; i < n; i++)
    {
        if(~(x = rk[sa[i]]))
        {
            if(ch < 1 || p[x + 1] - p[x] != p[y + 1] - p[y])
                ch++;
            else
            {
                for(int j = p[x], k = p[y]; j <= p[x + 1]; j++, k++)
                {
                    if((s[j] << 1 | t[j]) != (s[k] << 1 | t[k]))
                    {
                        ch++;
                        break;
                    }
                }
            }
            s1[y = x] = ch;
        }
    }
    if(ch + 1 < n1)
        sais(n1, ch + 1, s1, t + n, p + n1);
    else
    {
        for(int i = 0; i < n1; i++)
            sa[s1[i]] = i;
    }
    for(int i = 0; i < n1; i++)
        s1[i] = p[sa[i]];
    inducedSort(s1);
}
template <typename T>
int mapCharToInt(int n, const T *str)
{
    int m = *max_element(str, str + n);
    fill_n(rk, m + 1, 0);
    for(int i = 0; i < n; i++)
        rk[str[i]] = 1;
    for(int i = 0; i < m; i++)
        rk[i + 1] += rk[i];
    for(int i = 0; i < n; i++)
        s[i] = rk[str[i]] - 1;
    return rk[m];
}
int sz;
// Ensure that str[n] is the unique lexicographically smallest character in str.
struct RMQ
{
    int  dp[N][LOGN];
    void init(int *a, int n)
    {
        for(int i = 1; i <= n; i++)
            dp[i][0] = a[i];
        int lgn = __lg(n);
        for(int i = 1; i <= lgn; i++)
        {
            for(int j = 1; j <= n - (1 << i) + 1; j++)
                dp[j][i] = min(dp[j][i - 1], dp[j + (1 << i - 1)][i - 1]);
        }
    }
    int query(int l, int r)
    {
        int lgt = __lg(r - l + 1);
        return min(dp[l][lgt], dp[r - (1 << lgt) + 1][lgt]);
    }
} rmq;
template <typename T>
void suffixArray(int n, const T *str)
{
    sz    = n;
    int m = mapCharToInt(++n, str);
    sais(n, m, s, t, p);
    for(int i = 0; i < n; i++)
        rk[sa[i]] = i;
    for(int i = 0, h = ht[0] = 0; i < n - 1; i++)
    {
        int j = sa[rk[i] - 1];
        while(i + h < n && j + h < n && s[i + h] == s[j + h])
            h++;
        if(ht[rk[i]] = h)
            h--;
    }
    rmq.init(ht, n);
}

int lcp(int i, int j)
{
    if(i == j)
        return sz - i;
    i = rk[i], j = rk[j];
    if(i > j)
        swap(i, j);
    return rmq.query(i + 1, j);
}
#ifdef local
void debug(const char *s, int n)
{
    for(int i = 0; i <= n; i++)
        cout << i << ' ' << s + sa[i] << endl;
    for(int i = 0; i <= n; i++)
        cout << i << ' ' << ht[i] << endl;
}
#else
#    define debug(...) \
        if(0)          \
            cout << "a" << endl;
#endif
}  // namespace SA

int nxt[N];

int main()
{
#ifdef local
    freopen("in.txt", "r", stdin);
#endif  // local
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int q;
    cin >> s + 1 >> q;
    int n = strlen(s + 1);// n 是字符串长度
    SA::suffixArray(n, s + 1);
    set<int> st;//用 set 处理 第一个右边的小于我的后缀
    for(int i = 1; i <= n; i++)
    {
        auto it = st.lower_bound(SA::sa[i] + 1);
        if(it != st.end())
            nxt[SA::sa[i] + 1] = *it;
        else
            nxt[SA::sa[i] + 1] = n + 1;
        st.insert(SA::sa[i] + 1);
    }
    for(int i = 1; i <= n; i++)
    {
        int j = nxt[i];
        int h = SA::lcp(i - 1, j - 1);
        if(h < j - i)
            len[i] = j - i, cnt[i] = 1;//连距离也算好
        else
        {
            cnt[i] = (h + j - i) / (j - i);
            len[i] = j - i;
        }
    }
    while(q--)
    {
        int st, k;
        cin >> st >> k;
        // cout << st << "#" << '\n';
        int f = st + len[st] * cnt[st] - 1 != n;
        if(k == 1)
            cout << st << ' ' << n << '\n';
        else if(cnt[st] + 1 <= k)
            cout << st << ' ' << st + len[st] - 1 << '\n';
        else
        {
            int z = cnt[st] / k;
            if(cnt[st] % k == 0)
            {
                if(!f)
                    cout << st << ' ' << st + len[st] * z - 1 << '\n';
                else
                    cout << st + (cnt[st] - z) * len[st] << ' ' << n << '\n';
            }
            else
            {
                cout << st << ' ' << st + len[st] * (z + 1) - 1 << '\n';
            }
        }
    }
    return 0;
}