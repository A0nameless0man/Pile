#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include<windows.system.h>
//迷宫，输出可行路径数
const int   MAXDOTS = 5;
bool        map[MAXDOTS][MAXDOTS];
bool        passed[MAXDOTS][MAXDOTS];
int         m, n, t, fx, fy;
int         step[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
inline bool InAble(int x, int y)
{
    return x >= 0 && y >= 0 && y < n && x < m && (!map[x][y]) && (!passed[x][y]);
}
inline bool IsFinal(int x, int y)
{
    return x == fx && y == fy;
}
int dfs(int sx, int sy)
{
    passed[sx][sy] = true;
    int sum        = 0;
    for(size_t i = 0; i < 4; i++)
    {
        int x = sx + step[i][0];
        int y = sy + step[i][1];
        if(InAble(x, y))
        {
            if(IsFinal(x, y))
            {
                sum += 1;
            }
            else
            {
                sum += dfs(x, y);
            }
        }
    }
    passed[sx][sy] = false;
    return sum;
}
int main(void)
{
    int _sx, _sy, bx, by;
    scanf("%d%d%d%d%d%d%d", &n, &m, &t, &_sx, &_sy, &fx, &fy);
    _sx--;
    _sy--;
    fx--;
    fy--;
    for(size_t i = 0; i < m; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            map[i][j]    = false;
            passed[i][j] = false;
        }
    }
    for(size_t i = 0; i < t; i++)
    {
        scanf("%d%d", &bx, &by);
        map[bx - 1][by - 1] = true;
    }
    printf("%d\n", dfs(_sx, _sy));
    // system("pause");
    return 0;
}