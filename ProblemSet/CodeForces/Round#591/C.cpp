#include <algorithm>
#include <iostream>
#include <vector>
struct E
{
    size_t from;
    size_t to;
    size_t w;
};
int main(void)
{
    int q;
    std::cin >> q;
    while(q--)
    {
        int                 n, k;
        std::vector<E>      e;
        std::vector<size_t> bucket;
        std::cin >> n >> k;
        e.reserve(n);
        bucket.resize(n + 7);
        while(--n)
        {
            size_t f, t, w;
            std::cin >> f >> t >> w;
            e.push_back({ f, t, w });
        }
        std::sort(e.rbegin(), e.rend(), [](const E &a, const E &b) -> bool {
            return a.w < b.w;
        });
        size_t ans = 0;
        for(auto edge: e)
        {
            // std::cout<<'#'<<edge.from<<" "<<edge.to<<" "<<bucket[edge.from]<<"
            // "<<bucket[edge.to]<<std::endl;
            if(bucket[edge.from] < k && bucket[edge.to] < k)
            {
                ans += edge.w;
                bucket[edge.from]++;
                bucket[edge.to]++;
                // std::cout<<'#'<<edge.from<<" "<<edge.to<<" "<<edge.w<<std::endl;
            }
        }
        std::cout << ans << std::endl;
    }
}