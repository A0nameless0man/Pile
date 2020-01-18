// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define N 21
#define M 1010
#define G 1 << 21
using namespace std;

vector<int> g[N];
int         n;
int         lgh[G];//dis from begin status
int cnt[N], tot[G][N], ans[N][G];
int  cyc;      // final point and the first point on circle
int  cyclen;   // full pathlen
int  pathlen;  // the len of chain
bool col[N], vis[G];

void dfs(int u, int len)
{
    // cout<<u<<","<<len<<endl;
    lgh[u] = len;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i++)
    {
        tot[len][i] = tot[len - 1][i] + col[i];
        if(col[i])
        {
            ans[i][tot[len][i]] = len;
        }
        for(auto j: g[i])
        {
            cnt[j] += col[i];
        }
    }
    int tmp = 0;
    for(int i = 1; i <= n; i++)
    {
        // cout<<cnt[i]<<";";
        col[i] = (bool) (cnt[i] & 1);
        tmp    = tmp << 1 | col[i];
    }
    if(vis[tmp])
    {
        cyc     = tmp;
        pathlen = lgh[tmp] - 1;
        cyclen  = len;
        return;
    }
    vis[tmp] = 1;
    dfs(tmp, len + 1);
}

int main()
{
    int m, q, x, k, u, v;
    cin >> n >> m >> q;
    int tmp = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> col[i];
        tmp = tmp << 1 | col[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    vis[tmp] = 1;
    dfs(tmp, 1);
    //	cout<<pathlen<<"!"<<cyclen<<endl;
    while(q--)
    {
        cin >> x >> k;
        if(k <= tot[cyclen][x])
            cout << ans[x][k] - 1 << endl;
        else
        {
            k -= tot[pathlen][x];
            int t = (tot[cyclen][x] - tot[pathlen][x]);
            if(t == 0)
                cout << -1 << endl;
            else
            {
                int tms = (k - 1) / t;
                k       = (k - 1) % t + 1;
                k += tot[pathlen][x];
                cout << ans[x][k] + tms * (cyclen - pathlen) - 1 << endl;
            }
        }
    }
    return 0;
}