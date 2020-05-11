#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int INF = 0x7fffffff;

struct P
{
    int x;
    int y;
};

struct E
{
    int r;
    int c;
    int d;  // dis
};

struct G
{
    std::vector<std::vector<E>> edges;
    std::vector<P>              points;
};

struct Rec
{
    int cost;  // dis*C[type]
    int dest;  // dest point
};

int square(int op)
{
    return op * op;
}

int dis(const P &lop, const P &rop)
{
    int l    = 0;
    int r    = 200;
    int disr = square(lop.x - rop.x) + square(lop.y - rop.y);
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(square(mid) < disr)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

bool operator<(const Rec &lop, const Rec &rop)
{
    return rop.cost < lop.cost;
}

std::vector<int> bfs(const G &g, const int s, const int B)
{
    const int                b = B + 1;
    std::priority_queue<Rec> que;
    std::vector<int>         disv;
    // std::vector<int>         disv(g.edges.size() * b, INF);
    for(int i = 0; i < g.edges.size() * b; ++i)
    {
        disv.push_back(INF);
    }
    que.push({ 0, s });
    while(!que.empty())
    {
        auto cur = que.top();
        que.pop();
        if(cur.cost > disv[cur.dest])
        {
            continue;
        }
        else
        {
            for(const auto &i: g.edges[cur.dest / b])
            {
                int curdis = cur.dest % b + i.d;
                int curp   = i.r * b + curdis;
                if(curdis < b && disv[curp] > cur.cost + i.c)
                {
                    disv[curp] = cur.cost + i.c;
                    que.push({ disv[curp], curp });
                }
            }
        }
    }
    return disv;
}

int main(void)
{
    int x, y, m, n, B, C, T, N;
    while(std::cin >> x >> y >> m >> n >> B >> C >> T)
    {
        G                g;
        std::vector<int> c;
        {
            // for(int i = 0; i < B; ++i)
            {
                g.points.push_back({ x, y });
            }
            c.push_back(C);
            for(int i = 0; i < T; ++i)
            {
                int buf;
                std::cin >> buf;
                c.push_back(buf);
            }
            std::cin >> N;
            g.edges.resize(N + 2);
            for(int i = 0; i < N; ++i)
            {
                int _x, _y, l;
                std::cin >> _x >> _y >> l;
                g.points.push_back({ _x, _y });
                for(int j = 0; j < l; ++j)
                {
                    int r, t;
                    std::cin >> r >> t;
                    g.edges[i + 1].push_back({ r + 1, t, 0 });
                    g.edges[r + 1].push_back({ i + 1, t, 0 });
                }
            }
            g.points.push_back({ m, n });
            for(int i = 0; i < N; ++i)
            {
                g.edges[0].push_back({ i + 1, 0, 0 });
                g.edges[i + 1].push_back({ 0, 0, 0 });
                g.edges[i + 1].push_back({ N + 1, 0, 0 });
                g.edges[N + 1].push_back({ i + 1, 0, 0 });
            }
            g.edges[N + 1].push_back({ 0, 0, 0 });
            g.edges[0].push_back({ N + 1, 0, 0 });
#ifdef DEBUG
            {
                std::cout << "Point" << std::endl;
                for(auto p: g.points)
                {
                    std::cout << p.x << ":" << p.y << std::endl;
                }
            }
            {
                std::cout << "edges:" << std::endl;
                for(int i = 0; i < N + 2; ++i)
                {
                    for(auto e: g.edges[i])
                    {
                        std::cout << e.r << ":" << e.c << " ";
                    }
                    std::cout << std::endl;
                }
            }
            std::cout << "C[]:" << std::endl;
            for(auto cost: c)
            {
                std::cout << cost << " ";
            }
            std::cout << std::endl;
#endif
            for(int i = 0; i < N + 2; ++i)
            {
                for(auto &e: g.edges[i])
                {
                    e.d = std::min(101, dis(g.points[i], g.points[e.r]));
                    e.c = c[e.c] * e.d;
                }
            }
            auto ans  = bfs(g, 0, B);
            auto cost = INF;
            for(int i = 0; i < (B + 1); ++i)
            {
                cost = std::min(cost, ans[(N + 1) * (B + 1) + i]);
            }
            if(cost == INF)
            {
                cost = -1;
            }
            std::cout << cost << std::endl;
#ifdef DEBUG
            {
                std::cout << "ans:" << std::endl;
                for(int i = 0; i < N + 2; ++i)
                {
                    for(int j = 0; j < B + 1; ++j)
                    {
                        std::cout << ans[i * (B + 1) + j] << " ";
                    }
                    std::cout << std::endl;
                }
            }
            {
                std::cout << "edges:" << std::endl;
                for(int i = 0; i < N + 2; ++i)
                {
                    for(auto e: g.edges[i])
                    {
                        std::cout << e.r << ":" << e.c << ":" << e.d << " ";
                    }
                    std::cout << std::endl;
                }
            }
#endif
        }
    }
}
