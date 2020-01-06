#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//找出字母方阵中指定的字符串
const int   MAX_N                            = 107;
const char  TARGET[]                         = { "yizhong" };
char        M[MAX_N][MAX_N]                  = { 0 };
bool        Needed[MAX_N][MAX_N]             = { false };
int         step[8][2]                       = { { 0, 1 }, { 0, -1 }, { 1, 0 },  { -1, 0 },
                   { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };
int         PotentialStart[MAX_N * MAX_N][2] = { 0 };
int         PotentialCount                   = 0;
int         n;
inline bool Match(int x, int y, int i)
{
    return (x >= 0) && (y >= 0) && (x < n) && (y < n) && (M[x][y] == TARGET[i]);
}
void CheckStart(int x, int y)
{
    int _x, _y;
    for(size_t i = 0; i < 8; i++)
    {
        _x = x;
        _y = y;
        for(size_t j = 1; j < 7; j++)
        {
            _x += step[i][0];
            _y += step[i][1];
            if(!Match(_x, _y, j))
            {
                break;
            }
            if(j == 6)
            {
                Needed[_x = x][_y = y] = true;
                for(size_t a = 0; a < 6; a++)
                {
                    Needed[_x += step[i][0]][_y += step[i][1]] = true;
                }
            }
        }
    }
}
int main(void)
{
    scanf("%d", &n);
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            scanf(" %c", &M[j][i]);
            if(M[j][i] == TARGET[0])
            {
                PotentialStart[PotentialCount][0]   = j;
                PotentialStart[PotentialCount++][1] = i;
            }
        }
    }
    for(size_t i = 0; i < PotentialCount; i++)
    {
        CheckStart(PotentialStart[i][0], PotentialStart[i][1]);
    }
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(Needed[j][i])
            {
                printf("%c", M[j][i]);
            }
            else
            {
                putchar('*');
            }
        }
        putchar('\n');
    }
    return 0;
}
