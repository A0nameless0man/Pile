#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

constexpr size_t INF = static_cast<size_t>(-1);

template <typename T>
struct G
{
    std::vector<std::unordered_set<T>> edges;
    G(T size): edges(size) {}
    G &add(const T &u, const T &v)
    {
        edges[u].insert(v);
        return *this;
    }

    size_t dis(const T &u, const T &v)
    {
        std::vector<size_t> dis(edges.size(), INF);
        std::queue<T>       next;
        next.push(u);
        dis[u] = 0;
        while(!next.empty())
        {
            T cur = next.front();
            next.pop();
            for(auto n: edges[cur])
            {
                if(n == v)
                {
                    return dis[cur] + 1;
                }
                if(dis[n] > dis[cur] + 1)
                {
                    dis[n] = dis[cur] + 1;
                    next.push(n);
                }
            }
        }
        return INF;
    }
};

int main(void)
{
    size_t n, m;
    while(std::cin >> n >> m)
    {
        G g(n);
        for(size_t i = 0; i < m; ++i)
        {
            size_t u, v;
            std::cin >> u >> v;
            g.add(u, v);
        }
        size_t q;
        std::cin >> q;
        for(size_t i = 0; i < q; ++i)
        {
            size_t u, v;
            std::cin >> u >> v;
            auto dis = g.dis(u, v);
            if(dis != INF)
            {
                std::cout << dis << "\n";
            }
            else
            {
                std::cout << "-1\n";
            }
        }
    }
}