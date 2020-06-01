#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
const int MAX_M_N = 1000007;
char      bufer[MAX_M_N];

bool blockMyWay(std::vector<std::vector<bool>> &map)
{
    struct P
    {
        int x;
        int y;
        int dir;
    };
    std::stack<P> stc;
    stc.push({ 0, 0, 0 });
    while(!stc.empty())
    {
        auto cur = stc.top();
        stc.pop();
        if(cur.dir > 1)
        {
            continue;
        }
        int xnext = cur.x + !(cur.dir);
        int ynext = cur.y + (cur.dir);
        if(xnext > m || ynext > n) {
            cur.dir++;
            stc.puhs(cur);
        }
        if(map[xnext, ynext]) {}
    }
}

int main(void)
{
    int m, n;
    while(std::cin >> m >> n)
    {
        std::vector<std::vector<bool>> map;
        map.resize(m, std::vector<bool>(n));
        for(int i = 0; i < m; ++i)
        {
            gets_s(bufer, MAX_M_N);
            for(int j = 0; i < n; ++j)
            {
                if(bufer[j] == '.')
                {
                    map[i][j] = true;
                }
                else
                {
                    map[i][j] = false;
                }
            }
        }
    }
}