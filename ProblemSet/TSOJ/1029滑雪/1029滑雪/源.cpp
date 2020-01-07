#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int        map[107][107]            = { 0 }, c, r, _x, _y;
int        distence[107][107]       = { 0 };
int        ways[4][2]               = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int        startpoint[107 * 107][2] = { 0 };
inline int max(int a, int b)
{
    return a > b ? a : b;
}
inline bool InRang(int x, int y)
{
    if(x < 0 || y < 0 || x >= c || y >= r)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool IsStartPoint(int x, int y)
{
    for(size_t m = 0; m < 4; m++)
    {
        _x = x + ways[m][0];
        _y = y + ways[m][1];
        if(InRang(_x, _y) && map[_x][_y] > map[x][y])
        {
            return false;
        }
    }
    return true;
}
int FindStratPoint(void)
{
    int StartPointCount = 0;
    for(size_t i = 0; i < c; i++)
    {
        for(size_t j = 0; j < r; j++)
        {
            if(IsStartPoint(i, j))
            {
                startpoint[StartPointCount][0]   = i;
                startpoint[StartPointCount++][1] = j;
            }
        }
    }
    return StartPointCount;
}
int DeepFirstSearch(int x, int y)
{
    int mx = 0, a;
    if(!InRang(x, y))
    {
        return 0;
    }
    else
    {
        for(size_t i = 0; i < 4; i++)
        {
            _x = x + ways[i][0];
            _y = y + ways[i][1];
            if(InRang(_x, _y) && map[_x][_y] < map[x][y] && distence[_x][_y] <= distence[x][y])
            {
                distence[_x][_y] = distence[x][y] + 1;
                mx               = max(mx, DeepFirstSearch(_x, _y));
            }
        }
        return mx + 1;
    }
}
int main(void)
{
    while(scanf("%d%d", &r, &c) != EOF)
    {
        int mx = 0;
        for(size_t i = 0; i < r; i++)
        {
            for(size_t j = 0; j < c; j++)
            {
                scanf("%d", &map[j][i]);
                distence[j][i] = 0;
            }
        }
        int strcon = FindStratPoint();
        for(size_t i = 0; i < strcon; i++)
        {
            mx = max(DeepFirstSearch(startpoint[i][0], startpoint[i][1]), mx);
        }
        printf("%d\n", mx);
    }
}