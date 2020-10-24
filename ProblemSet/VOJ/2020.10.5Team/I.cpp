#include <algorithm>
#include <cstdio>
#include <vector>
const long long INF = 0x7fffffffff;

struct State
{
    long long inheritedFrom;
    long long inheritedSince;
};

int main()
{
    // freopen("I.1.in", "r", stdin);
    long long n, m;
    while(scanf("%lld%lld", &n, &m) != EOF)
    {
        std::vector<std::vector<long long>> e;
        std::vector<std::vector<long long>> circles;
        std::vector<long long>              vis;
        std::vector<long long>              newEdge;
        std::vector<State>            states;
        std::vector<long long>              contribution;
        std::vector<long long>              cirContribution;
        std::vector<long double> ans;
        contribution.resize(n);
        newEdge.resize(n);
        vis.resize(n, -1);
        e.resize(n);
        for(long long i = 0; i < m; ++i)
        {
            long long u, v;
            scanf("%lld%lld", &u, &v);
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(long long i = 0; i < n; ++i)
        {
            states.push_back({ i, 0 });
        }
        for(long long i = 0; i < n; ++i)
        {
            State curState = states[i];
            long long   curColur = curState.inheritedFrom;
            for(auto edge: e[i])
            {
                State lastState = states[edge];
                contribution[lastState.inheritedFrom] +=
                  i - lastState.inheritedSince;
                states[edge] = { curColur, i };
            }
        }
        for(long long i = 0; i < n; ++i)
        {
            State curState = states[i];
            long long   curColur = curState.inheritedFrom;
            newEdge[i]     = curColur;
            contribution[curColur] +=
              n - curState.inheritedSince;
        }
        for(long long i = 0; i < n; ++i)
        {
            if(vis[i] == -1)
            {
                long long cur = i;

                while(vis[cur] == -1)
                {
                    vis[cur] = INF;
                    cur      = newEdge[cur];
                }

                if(vis[cur] == INF)
                {
                    // new Circul
                    long long circle = circles.size();
                    circles.emplace_back();
                    while(vis[cur] == INF)
                    {
                        vis[cur] = circle;
                        circles[circle].push_back(cur);
                        cur = newEdge[cur];
                    }
                    cur = i;
                    while(vis[cur] == INF)
                    {
                        vis[cur] = circle;
                        cur      = newEdge[cur];
                    }
                }
                else
                {
                    long long circle = vis[cur];
                    cur        = i;
                    while(vis[cur] == INF)
                    {
                        vis[cur] = circle;
                        cur      = newEdge[cur];
                    }
                }
            }
        }
        cirContribution.resize(circles.size());
        for(long long i = 0; i < n; ++i)
        {
            cirContribution[vis[i]] += contribution[i];
        }
#ifdef DEBUG
        for(long long i = 0; i < cirContribution.size(); ++i)
        {
            printf("%5d ", cirContribution[i]);
        }
        printf("\n");
#endif  // DEBUG
        for(long long i = 0; i < cirContribution.size(); ++i)
        {
            for(long long j = 0; j < circles[i].size(); ++j)
            {

                ans.push_back(
                  static_cast<long double>(cirContribution[i])
                  / (circles[i].size() * n));
            }
        }
        std::sort(ans.rbegin(), ans.rend());
        for(long long i = 0; i < ans.size(); ++i)
        {
            printf("%.6Lf\n", ans[i]);
        }
        // printf("\n");
    }
}