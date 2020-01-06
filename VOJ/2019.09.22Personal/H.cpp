#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
// std::unordered_map<char , int[2]> DIR = {{'U',{-1,0}},{'D',{1,0}},{'L',{0,-1}},{'R',{0,1}}};
bool graid[1007][1007] = { 0 };
int  sqrt(int i)
{
    return i * i;
}
inline void tryMove(int &x, int &y, const char o)
{
    int nx = x, ny = y;
    switch(o)
    {
        case 'U':
            nx--;
            break;
        case 'D':
            nx++;
            break;
        case 'L':
            ny--;
            break;
        case 'R':
            ny++;
            break;
        default:
            break;
    }
    if(graid[nx][ny])
    {
        return;
    }
    else
    {
        x = nx;
        y = ny;
        return;
    }
}

int main(void)
{
    int T;
    std::cin >> T;
    int t = 0;
    while(T--)
    {
        int n, m, o, l;
        // std::cin >> n >> m >> o >> l;
        scanf("%d%d%d%d", &n, &m, &o, &l);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                graid[i][j] = false;
            }
        }
        for(int i = 0; i <= n + 1; i++)
        {
            graid[i][0] = graid[i][m + 1] = true;
        }
        for(int j = 0; j <= m + 1; j++)
        {
            graid[0][j] = graid[n + 1][j] = true;
        }
        for(int i = 0; i < o; i++)
        {
            int x, y;
            // std::cin >> x >> y;
            scanf("%d%d", &x, &y);
            graid[x][y] = true;
        }
        // std::string order;
        char order[2007];
        // std::cin >> order;
        scanf("%s", order);
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(!graid[i][j])
                {
                    int cx = i, cy = j;
                    // for (auto c : order)
                    for(int i = 0; i < l; i++)
                    {
                        tryMove(cx, cy, order[i]);
                    }
                    ans += sqrt(i - cx) + sqrt(j - cy);
                }
            }
        }
        std::cout << "Case #" << ++t << ": " << ans << std::endl;
    }
}