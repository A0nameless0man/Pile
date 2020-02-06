#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

class Problem
{
private:
    std::vector<long long> parent;

    std::vector<std::vector<long long>> tree;

    std::vector<long long> subTreeSize;

    std::vector<long double> expt;

    long long n;
    long long doSubTree(long long cur = 0)
    {
        long long ans = 0;
        for(const auto &child: tree[cur])
        {
            ans += doSubTree(child);
        }
        return subTreeSize[cur] = ans + 1;
    }

public:
    Problem(long long _n): n(_n)
    {
        parent.resize(n);
        tree.resize(n);
        subTreeSize.resize(n);
        expt.resize(n);
    }

    void addEdge(long long u, long long v)
    {
        --u;
        --v;
        parent[u] = v;
        tree[v].push_back(u);
    }

    void caculateSubTreeSize(void)
    {
        doSubTree();
    }

    void predicd(void)
    {
        std::queue<long long> que;
        expt[0] = 1.0;
        for(auto c: tree[0])
        {
            que.push(c);
        }
        while(!que.empty())
        {
            long long cur = que.front();
            que.pop();
            expt[cur] =
              expt[parent[cur]]
              + static_cast<long double>(subTreeSize[parent[cur]] - subTreeSize[cur] - 1) / 2 + 1.0;
              for(auto c:tree[cur])
              {
                  que.push(c);
              }
        }
    }

    void p(void)
    {
        for(size_t i = 0; i < expt.size(); ++i)
        {
            printf("%Lf", expt[i]);
            if(i != expt.size() - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
        // for(size_t i = 0; i < expt.size(); ++i)
        // {
        //     printf("%lld", subTreeSize[i]);
        //     if(i != expt.size() - 1)
        //     {
        //         printf(" ");
        //     }
        //     else
        //     {
        //         printf("\n");
        //     }
        // }
    }
};

int main(void)
{
    long long n;
    while(std::cin >> n)
    {
        Problem p(n);
        for(long long i = 2; i <= n; ++i)
        {
            long long buf;
            scanf("%lld", &buf);
            p.addEdge(i, buf);
        }
        p.caculateSubTreeSize();
        p.predicd();
        p.p();
    }
}