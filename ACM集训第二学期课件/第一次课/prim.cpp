#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > e[5005];
int                     dis[5005];
int                     vis[5005];
int                     n, m, ans;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(make_pair(y, z));
        e[y].push_back(make_pair(x, z));
    }
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[1] = 0;
    int t  = 0;
    while(1)
    {
        int u    = -1;
        int minn = 0x3f3f3f3f;
        for(int i = 1; i <= n; ++i)
        {
            if(!vis[i] && dis[i] < minn)
            {
                minn = dis[i];
                u    = i;
            }
        }
        if(u == -1)
            break;
        ++t;
        ans += minn;
        vis[u] = 1;
        for(int i = 0; i < e[u].size(); ++i)
            dis[e[u][i].first] = min(dis[e[u][i].first], e[u][i].second);
    }
    if(t != n)
        cout << "orz" << endl;
    else
        cout << ans << endl;
}
