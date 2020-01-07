#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
template <typename T>
void swap(T &a, T &b)
{
    T t = a;
    a   = b;
    b   = t;
}

const int   MAX_N = 1007;
bool        map[MAX_N][MAX_N];
inline void putdot(int x, int y)
{
    printf(">(%d,%d)", y, x);
}
int DFS(int x, int y)
{
    if(x == 1 && y == 1)
    {
        printf("(1,1)");
        return 0;
    }
    else
    {
        int r = -1;
        if(y != 1 && map[x][y - 1])
        {
            if((r = DFS(x, y - 1)) != -1)
            {
                putdot(x, y);
                return r;
            }
        }
        if(x != 1 && map[x - 1][y])
        {
            if((r = DFS(x - 1, y)) != -1)
            {
                putdot(x, y);
                return r;
            }
        }
        return r;
    }
}
int n, m, a, b, j, k;
int main(void)
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif  // DEBUG

    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &b);
                map[j][i] = b == 1;
            }
        }
        DFS(m, n);
        putchar('\n');
    }
    return 0;
}