#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline int read();
const int  M = 5016, MOD = 1000000007;

int toque[M];
int que[M][M];
ll  LRU_hash[M][M];
int main(void)
{
#ifdef _LITTLEFALL_
    freopen("in.txt", "r", stdin);
#endif

    int T = read();
    while(T--)
    {
        int n = read(), q = read();
        memset(que[0], 0, (n + 1) * sizeof(que[0][0]));
        for(int i = 1, qlen = 0; i <= n; ++i)
        {
            memcpy(que[i], que[i - 1], (n + 1) * sizeof(que[0][0]));
            int now = read(), pos = 0;
            for(int j = 1; j <= qlen; ++j)
                if(que[i][j] == now)
                    pos = j, j = qlen + 1;
            for(int j = (pos ? pos : ++qlen); j; --j)
                que[i][j] = que[i][j - 1];
            que[i][1] = now;

            for(int j = 1; j <= n; ++j)
                LRU_hash[i][j] = (LRU_hash[i][j - 1] * (n + 1) + que[i][j]) % MOD;
        }
        while(q--)
        {
            int m     = read();
            ll  hashv = 0;
            for(int i = 1; i <= m; ++i)
            {
                toque[i] = read();
                hashv    = (hashv * (n + 1) + toque[i]) % MOD;
            }
            int suc = 0;
            for(int i = 0; i <= n; ++i)
                if(LRU_hash[i][m] == hashv)
                {
                    int flag = 1;
                    for(int j = 1; j <= m; ++j)
                        if(que[i][j] != toque[j])
                            flag = 0, j = m + 1;
                    if(flag)
                        suc = 1, i = n + 1;
                }
            printf("%s\n", suc ? "Yes" : "No");
        }
    }

    return 0;
}

inline int read()
{
    int  x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x  = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
