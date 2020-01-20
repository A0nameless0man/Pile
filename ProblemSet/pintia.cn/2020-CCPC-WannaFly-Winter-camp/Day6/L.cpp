#include <cstdio>
#include <iostream>
#include <vector>

using Status = long long;
/*
Time: 2020-01-18 19:12:42
Describe: FindOut What when wrong
Statue: TODO
*/

const long long MAX_STA = 1 << 20;
const long long INF     = (1 << 30);
const long long MAX_N   = 20;

std::vector<long long> G[MAX_N];  // the inputed graph
long long              n;         // the size of inputed graph
long long              m;         // the number of edge in the inputed graph
long long              q;         // the amount of query

Status    staGraph[MAX_STA];  // the graph of status,one leaving edge for each vertix
long long dis[MAX_STA];       // the distence from start point

long long              GainOnCircle[MAX_N];
long long              chainLen;
long long              circleLen;
long long              totalLen;
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
        dis[i] = INF;
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
    long long curDis = 0;

    for(long long i = 0; i < n; ++i)
    {
        kOnChain[i].clear();
        GainOnCircle[i] = 0;
        // GainOnChain[i]  = 0;
    }

    while(dis[cur] == INF)
    {
        for(long long i = 0; i < n; ++i)
        {
            if((cur >> i) & 1)
            {
                kOnChain[i].push_back(curDis);
                // ++GainOnChain[i];
            }
        }
        dis[cur] = curDis;

        cur = staGraph[cur];
        ++curDis;
    }
    circleLen          = curDis - dis[cur];
    chainLen           = dis[cur];
    totalLen           = curDis;
    long long roundLen = circleLen;
    while(roundLen--)
    {
        for(long long i = 0; i < n; ++i)
        {
            if((cur >> i) & 1)
            {
                ++GainOnCircle[i];
                // --GainOnChain[i];
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
        {
            for(long long i = 0; i < n; ++i)
            {
                G[i].clear();
            }
        }

        Status s = 0;
        for(long long i = 0; i < n; i++)
        {
            long long buf;
            scanf("%lld", &buf);
            if(buf == 1)
            {
                s |= ((1) << i);
            }
        }
        for(long long i = 0; i < m; ++i)
        {
            long long x, y;
            // std::cin >> x >> y;
            /*
            Time: 2020-01-20 11:16:49
            Describe: Excepion when reading?
            Statue: ToDebug
            */
            scanf("%lld%lld", &x, &y);  // x-->y => y influence x ==> y-->x is the edge we need
            --x;                        // convert 1 based counting to 0 based counting
            --y;
            G[y].push_back(x);  // record edge
        }

        {
            buildStaGraph();  // build graph
            dfs(s);           // search
        }

        {
            for(long long i = 0; i < q; ++i)
            {
                long long x, k;
                long long ans = 0;
                scanf("%lld%lld", &x, &k);  // quest
                --x;
                if(k <= kOnChain[x].size())  // if the k is small enough to
                {
                    // prlong longf("%d\n", kOnChain[x][k]);
                    if(k)  // if k is greater than 0;
                    {
                        ans = kOnChain[x][k - 1];
                    }
                    else
                    {
                        ans = 0;  // it takes on effort to reach 0 times of black
                    }
                }
                else
                {
                    if(GainOnCircle[x] == 0)
                    {
                        ans = -1;
                    }
                    else
                    {
                        long long cir =
                          (k - kOnChain[x].size() + GainOnCircle[x] - 1) / GainOnCircle[x];
                        long long extra = k - cir * GainOnCircle[x];
                        // std::cout << cir << "X" << extra << std::endl;
                        // +(kOnChain[x].size() - GainOnCircle[x]);
                        //(GainOnChain[x],kOnCain[x].size()]
                        // extra - (kOnChain[x].size()-GainOnCircle[x]) \in (0,GainOnCircle]
                        ans += circleLen * cir;
                        if(extra)
                        {
                            ans += kOnChain[x][extra - 1];
                        }
                    }
                }
                printf("%lld\n", ans);
            }
        }
    }
}
/*
3 2 9
0 1 1
1 2
2 1
1 2
2 2
3 2
3 1
1 1
2 1
1 0
2 0
3 0
3 2 9
0 0 1
1 2
2 1
1 2
2 2
3 2
3 1
1 1
2 1
1 0
2 0
3 0
3 2 9
1 1 1
1 2
2 1
1 5
2 5
3 5
3 1
1 1
2 1
1 0
2 0
3 0
*/