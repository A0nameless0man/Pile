#include <iostream>
#include <vector>

int main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            int n, m;
            std::cin >> n >> m;
            int ans = m;
            ++n;
            std::vector<int> e(n, -1);
            std::vector<int> vis(n, -1);
            for(int i = 0; i < m; ++i)
            {
                int x, y;
                std::cin >> x >> y;
                if(x==y)
                {
                    --ans;
                }
                else
                {
                    e[x] = y;
                }
            }
            for(int i = 0; i < n; ++i)
            {
                if(e[i] != -1 && vis[i] == -1)
                {
                    int cur = i;
                    for(; cur != -1 && vis[cur] == -1;
                        cur = e[cur])
                    {
                        vis[cur] = i;
                    }
                    if(cur != -1)
                    {
                        ++ans;
                    }
                }
            }
            std::cout << ans << std::endl;
        }
    }
}