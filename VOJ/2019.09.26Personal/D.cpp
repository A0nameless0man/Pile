//#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define C(x) std::cout << #x << ":\t" << (x) << std::endl;
struct rec
{
    int  y;
    bool water;
};
rec Rec(int y, int z)
{
    return { y, z == 1 };
}
bool operator<(const rec a, const rec b)
{
    return a.y < b.y;
}
int sqrt(int i)
{
    return i * i;
}
int main(void)
{
    int T, t = 0;

    // scanf("%d",&T);
    std::cin >> T;
    while(T--)
    {
        int m, n;
        {
            std::cin >> n >> m;
        }
        std::vector<int>                      divider;
        std::vector<std::priority_queue<rec>> recs;
        divider.reserve(n - 1);
        recs.resize(n);
        int ans = 0;
        {
            for(int i = 0; i < n - 1; i++)
            {
                int tmp;
                std::cin >> tmp;
                divider.push_back(tmp);
            }
            divider.push_back(1000000007);
            for(int i = 0; i < m; i++)
            {
                int x, y, z;
                std::cin >> x >> y >> z;
                if(y <= divider[i] && y <= divider[i + 1])
                {
                    recs[x].push(Rec(y, z));
                }
            }
        }
        {
            for(int i = 0; i < n; i++)
            {
                while(!recs[i].empty())
                {
                    std::cout << i << ':' << recs[i].top().y << std::endl;
                    recs[i].pop();
                }
            }
        }
        {
            std::cout << "Case #" << ++t << ": " << ans << std::endl;
        }
    }

    return 0;
}