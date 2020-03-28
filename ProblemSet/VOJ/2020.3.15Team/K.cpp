#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>

using LL = long long;

const int MAX_N = 807;
const int MAX_M = 50007;
const int INF   = 0x3f3f3f3f;

LL  dis[MAX_N - 1];
LL  pfdis[MAX_N];
int n, m;
struct enger
{
    std::vector<int> c[MAX_N];
    int              sf[MAX_N];
    int              pf[MAX_N];
    void             build(void)
    {
        {
            for(int i = 0; i < n; ++i)
            {
                std::sort(c[i].begin(), c[i].end(), std::greater<int>());
                sf[i] = pf[i] = -1;
            }
        }
        {
            int bestc = INF;
            int bestp = -1;
            for(int i = 0; i < n; ++i)
            {
                if(i)
                {
                    bestc += dis[i - 1];
                }
                if(!c[i].empty())
                {
                    int cur = *(c[i].rbegin());
                    if(bestc > cur)
                    {
                        bestc = cur;
                        bestp = i;
                    }
                }
                pf[i] = bestp;
            }
        }
        {
            int bestc = INF;
            int bestp = -1;
            for(int i = n - 1; ~i; --i)
            {
                if(i != n - 1)
                {
                    bestc += dis[i];
                }
                if(!c[i].empty())
                {
                    int cur = *(c[i].rbegin());
                    if(bestc > cur)
                    {
                        bestc = cur;
                        bestp = i;
                    }
                }
                sf[i] = bestp;
            }
        }
    }
    int at(int pos)
    {
        return c[pos].empty() ? INF : *(c[pos].rbegin());
    }
    int bestFrom(int pos)
    {
        int best  = INF;
        int bestp = -1;
        if(pf[pos] != -1 && best > at(pf[pos]))
        {
            best  = at(pf[pos]);
            bestp = pf[pos];
        }
        if(sf[pos] != -1 && best > at(sf[pos]))
        {
            best  = at(sf[pos]);
            bestp = sf[pos];
        }
        return bestp;
    }
    void pop(int pos)
    {
        if(!c[pos].empty())
        {
            c[pos].pop_back();
        }
        {
            int bestc = INF;
            int bestp = -1;
            for(int i = 0; i < n; ++i)
            {
                if(i)
                {
                    bestc += dis[i - 1];
                }
                if(!c[i].empty())
                {
                    int cur = *(c[i].rbegin());
                    if(bestc > cur)
                    {
                        bestc = cur;
                        bestp = i;
                    }
                }
                pf[i] = bestp;
            }
        }
        {
            int bestc = INF;
            int bestp = -1;
            for(int i = n - 1; ~i; --i)
            {
                if(i != n - 1)
                {
                    bestc += dis[i];
                }
                if(!c[i].empty())
                {
                    int cur = *(c[i].rbegin());
                    if(bestc > cur)
                    {
                        bestc = cur;
                        bestp = i;
                    }
                }
                sf[i] = bestp;
            }
        }
    }
};

enger engs[2];

int main(void)
{
    while(std::cin >> n >> m)
    {
        pfdis[0] = 0;
        for(int i = 0; i < n - 1; ++i)
        {
            scanf("%lld", dis + i);
            pfdis[i + 1] = pfdis[i] + dis[i];
        }
        for(int i = 0; i < 2; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int x, c;
                scanf("%d%d", &x, &c);
                engs[i].c[x-1].push_back(c);
            }
            engs[i].build();
        }
        {
            int sum = 0;
            for(int i = 0; i < m; ++i)
            {
                int                 best = INF;
                std::pair<int, int> bestpos;
                for(int j = 0; j < n; ++j)
                {
                    auto pos  = std::make_pair(j, engs[1].bestFrom(j));
                    int  cost = engs[0].at(pos.first) + engs[1].at(pos.second)
                               + std::abs(pfdis[pos.first] - pfdis[pos.second]);
                    if(cost < best)
                    {
                        best    = cost;
                        bestpos = pos;
                    }
                }
                sum += best;
                engs[0].pop(bestpos.first);
                engs[1].pop(bestpos.second);
                printf("%d\n", sum);
            }
        }
    }
    return 0;
}
/*
4 3
1 1 1
1 1
1 2
4 6
2 1
2 2
3 5
*/