#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

std::vector<std::vector<int>> edges;
std::vector<int>              sub_tree_size;
std::vector<long long>        sub_tree_sum;
std::vector<int>              depth;

int size_dfs(int v)
{
    int sum = 1;
    for(auto c: edges[v])
    {
        sum += size_dfs(c);
    }
    sub_tree_size[v] = sum;
    return sum;
}
void sum_dfs(int v, long long lastsum = 0)
{
    long long sum         = sub_tree_size[v] + lastsum;
    sub_tree_sum[v] = sum;
    for(auto c: edges[v])
    {
        sum_dfs(c, sum);
    }
}
void deepth_dfs(int v, int depth_val = 1)
{
    depth[v] = depth_val;
    ++depth_val;
    for(auto c: edges[v])
    {
        deepth_dfs(c, depth_val);
    }
}

int32_t main(void)
{
    int T;
    while(EOF != scanf("%d", &T))
    {
        for(int t = 0; t < T; t++)
        {
            int       n;
            long long ans = 0;
            {
                scanf("%d", &n);
                edges.clear();
                edges.resize(n);
                sub_tree_sum.clear();
                sub_tree_sum.resize(n);
                sub_tree_size.clear();
                sub_tree_size.resize(n);
                depth.clear();
                depth.resize(n);
                for(int i = 1; i < n; ++i)
                {
                    int p;
                    scanf("%d", &p);
                    --p;
                    edges[p].push_back(i);
                }
            }
            {
                deepth_dfs(0);
                size_dfs(0);
                sum_dfs(0);
#ifdef DEBUG
                std::cout << "sub_tree_size[]:\n";
                for(int i = 0; i < n; ++i)
                {
                    std::cout << sub_tree_size[i] << " ";
                }
                std::cout << std::endl;
                std::cout << "sub_tree_sum[]:\n";
                for(int i = 0; i < n; ++i)
                {
                    std::cout << sub_tree_sum[i] << " ";
                }
                std::cout << std::endl;
                std::cout << "depth[]:\n";
                for(int i = 0; i < n; ++i)
                {
                    std::cout << depth[i] << " ";
                }
                std::cout << std::endl;
#endif  // DEBUG
            }
            {
                for(int i = 0; i < n; ++i)
                {
                    ans += sub_tree_size[i];
                }
#ifdef DEBUG
                std::cout << "ans:" << ans << std::endl;
#endif  // DEBUG
            }
            {
                long long bestgain = 0;
                for(int i = 0; i < n; ++i)
                {
                    if(edges[i].size() == 0)
                    {
                        long long curgain =
                          static_cast<long long>(n)
                            * static_cast<long long>(
                              depth[i])
                          - sub_tree_sum[i];
                        if(curgain > bestgain)
                        {
                            bestgain = curgain;
                        }
                    }
                }
                ans += bestgain;
#ifdef DEBUG
                std::cout << "ans:" << ans << std::endl;
#endif  // DEBUG
            }
            std::cout << ans << std::endl;
        }
    }
}