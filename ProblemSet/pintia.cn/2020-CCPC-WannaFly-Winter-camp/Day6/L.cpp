#include <cstdio>
#include <iostream>
#include <vector>

using Status = long long;

const long long MAX_STA = 1 << 20;
const long long INF     = ~(1 << 30);
const long long MAX_N   = 20;

std::vector<long long> G[MAX_N];
long long              n;
long long              m;
long long              q;

Status    staGraph[MAX_STA];
long long dis[MAX_STA];

long long              GainOnCircle[MAX_N];
long long              GainOnChain[MAX_N];
long long              chainLen;
long long              circleLen;
std::vector<long long> kOnChain[MAX_N];

void binout(long long i)
{
    while(i)
    {
        std::cout << (i & 1);
        i >>= 1;
    }
    std::cout << std::endl;
}

inline bool getCurColor(Status s, long long node)
{
    return (s >> node) & 1;
}

inline Status nextStatue(Status cur)
{
    Status next = 0;
    for(long long i = 0; i < n; ++i)
    {
        bool curc = 0;
        for(const auto &e: (G[i]))
        {
            curc ^= getCurColor(cur, e);
        }
        next |= (curc << i);
    }
    return next;
}

inline void buildStaGraph(void)
{
    // Status cur = 0;
    for(Status i = 0; i < (1 << n); ++i)
    {
        // degreeCnt[i] = 0;
        dis[MAX_STA] = 0;
    }
    for(Status i = 0; i < (1 << n); ++i)
    {
        staGraph[i] = nextStatue(i);
        // ++degreeCnt[staGraph[i]];
    }
}

void dfs(Status s)
{
    Status    cur    = s;
    long long curDis = 1;

    for(long long i = 0; i < n; ++i)
    {
        kOnChain[i].clear();
        GainOnCircle[i] = 0;
        GainOnChain[i]  = 0;
    }

    while(!dis[cur])
    {
        for(long long i = 0; i < n; ++i)
        {
            if((cur >> i) & 1)
            {
                kOnChain[i].push_back(curDis);
                ++GainOnChain[i];
            }
        }
        dis[cur] = curDis;
        cur      = staGraph[cur];
        ++curDis;
    }
    long long roundLen = curDis - dis[cur];
    chainLen           = dis[cur] - 1;
    circleLen          = roundLen;
    while(roundLen--)
    {
        for(long long i = 0; i < n; ++i)
        {
            if((cur >> i) & 1)
            {
                ++GainOnCircle[i];
                --GainOnChain[i];
            }
        }
        cur = staGraph[cur];
    }
}

int main(void)
{
    // while(std::cin>>n>>m>>q)
    while(scanf("%lld%lld%lld", &n, &m, &q) != EOF)
    {
        Status s = 0;
        for(long long i = 0; i < n; i++)
        {
            long long buf;
            scanf("%lld", &buf);
            if(buf)
            {
                s |= ((1) << i);
            }
        }
        for(long long i = 0; i < m; ++i)
        {
            long long x, y;
            // std::cin >> x >> y;
            scanf("%lld%lld", &x, &y);
            --x;
            --y;
            G[y].push_back(x);
        }

        {
            buildStaGraph();
            dfs(s);
        }

        {
            for(long long i = 0; i < q; ++i)
            {
                long long x, k;
                long long ans = 0;
                scanf("%lld%lld", &x, &k);
                --x;
                if(k < kOnChain[x].size())
                {
                    // prlong longf("%d\n", kOnChain[x][k]);
                    if(k)
                    {
                        ans = kOnChain[x][k - 1];
                    }
                    else
                    {
                        ans = 1;
                    }
                }
                else
                {
                    k -= GainOnChain[x];
                    if(GainOnCircle[x] == 0)
                    {
                        ans = 0;
                    }
                    else
                    {
                        long long cir   = (k - GainOnChain[x] - GainOnCircle[x]) / GainOnCircle[x];
                        long long extra = (k) -cir * GainOnCircle[x];
                        ans += circleLen * cir;
                        ans += kOnChain[x][extra - 1];
                    }
                }
                printf("%lld\n", ans - 1);
            }
        }
    }
}
/*
3 2 9
1 0 0
1 2
2 1
1 2
2 2
3 1
1 1
2 1
3 1
1 0
2 0
3 0
*/