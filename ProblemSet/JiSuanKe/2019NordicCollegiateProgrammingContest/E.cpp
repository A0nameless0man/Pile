#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for((i) = (s); (i) <= (e); ++(i))

struct Node
{
    int         parent;
    vector<int> children;

    ll   flow_sum;
    bool is_know(void)
    {
        return flow_sum != 0;
    }

    int children_unknown_cnt = 0;
    ll  children_sum         = 0;
};

const int MAXN = 3e5 + 7;
Node      graph[MAXN];
int       n;

void init()
{
    scanf("%d", &n);
    int i;
    asc(i, 2, n)
    {
        int pi;
        scanf("%d", &pi);
        graph[i].parent = pi;
        graph[pi].children.push_back(i);
    }

    asc(i, 1, n)
    {
        auto &nd = graph[i];
        int   ai;
        scanf("%d", &ai);
        nd.flow_sum = ai;
        auto &par   = graph[nd.parent];
        if(!nd.is_know())
        {
            ++(par.children_unknown_cnt);
        }
        par.children_sum += nd.flow_sum;
    }
}

void solve()
{
    queue<int> q;
    int        i;
    asc(i, 1, n)
    {
        auto &cur = graph[i];
        auto &par = graph[cur.parent];
        if(cur.is_know())
        {
            if(cur.children_unknown_cnt == 1
               || cur.children_unknown_cnt == cur.flow_sum - cur.children_sum)
            {
                for(auto j: cur.children)  // type 2 and 3
                {
                    if(!(graph[j].is_know()))
                    {
                        q.push(j);
                    }
                }
            }
        }
        else if(par.children_unknown_cnt == 1)
        {
            q.push(i);  // type 1
        }
    }
    while(!q.empty())
    {
        auto i = q.front();
        q.pop();
        auto &cur = graph[i];
        auto &par = graph[cur.parent];
        if(cur.is_know())
        {
            continue;
        }

        if(cur.children_unknown_cnt == 0)
        {
            cur.flow_sum = cur.children_sum;  // type 1
        }
        else if(par.is_know())
        {
            if(par.children_unknown_cnt == 1)
            {
                cur.flow_sum = par.flow_sum - par.children_sum;  // type 2
            }
            else if(par.children_unknown_cnt == par.flow_sum - par.children_sum
                    && par.children_unknown_cnt != 0)
            {
                cur.flow_sum = 1;  // type 3
            }
            else
            {
                return;
                // std::cerr << "unsloveable in queue" << std::endl;
                // exit(100);
            }
        }
        else
        {
            return;
            // std::cerr << "unsloveable in queue" << std::endl;
            // exit(100);
        }
        {  // update par
            --(par.children_unknown_cnt);
            par.children_sum += cur.flow_sum;
            if(cur.flow_sum == 0)
            {
                return;
            }
        }

        {
            if(par.is_know()
               && (par.children_unknown_cnt == 1
                   || (par.children_unknown_cnt == par.flow_sum - par.children_sum
                       && par.children_unknown_cnt != 0)))
            {
                for(auto j: par.children)
                {
                    if(!(graph[j].is_know()))
                    {
                        q.push(j);
                    }
                }
            }
        }
        {
            if(cur.children_unknown_cnt == 1
               || (cur.children_unknown_cnt == cur.flow_sum - cur.children_sum
                   && cur.children_unknown_cnt != 0))
            {
                for(auto j: cur.children)
                {
                    if(!(graph[j].is_know()))
                    {
                        q.push(j);
                    }
                }
            }
        }
        {
            if(!par.is_know() && par.children_unknown_cnt == 1)
            {
                q.push(cur.parent);
            }
        }
    }
}

bool check()
{
    int i;
    asc(i, 1, n)
    {
        auto &nd = graph[i];
        if(nd.is_know())
        {
            if(!nd.children.empty() && nd.flow_sum != nd.children_sum)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // freopen("E.1.in", "r", stdin);

    init();
    solve();
    if(check())
    {
        for(int i = 1; i <= n; ++i)
        {
            printf("%lld\n", graph[i].flow_sum);
        }
    }
    else
    {
        printf("impossible\n");
    }
}