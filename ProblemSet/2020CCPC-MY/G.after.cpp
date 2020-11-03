#include <algorithm>
#include <cstdio>

using LL = long long;

const char H[] = "Horse";
const char R[] = "Rabbit";

int       c[4];
const int memRange = 10;
int       dead[memRange][memRange][memRange][memRange];

void init()
{
    for(int i = 0; i < memRange; ++i)
    {
        for(int j = 0; j < memRange; ++j)
        {
            for(int k = 0; k < memRange; ++k)
            {
                for(int l = 0; l < memRange; ++l)
                {
                    dead[i][j][k][l] = -1;
                }
            }
        }
    }
}

bool lose(int a, int b, int c, int d)
{
    if(dead[a][b][c][d] != -1)
    {
        return dead[a][b][c][d];
    }
    else
    {
        // #ifdef DEBUG
        //         printf("(-_-) %d %d %d %d\n", a, b, c,
        //         d);
        // #endif  // DEBUG
        bool hope = false;
        if(a > 0 && lose(a - 1, b, c, d))
        {
            hope = true;
            // #ifdef DEBUG
            //             printf("%d %d %d %d ==> %d %d %d
            //             %d\n",
            //                    a,
            //                    b,
            //                    c,
            //                    d,
            //                    a - 1,
            //                    b,
            //                    c,
            //                    d);
            // #endif  // DEBUG
        }
        if(b >= 2 && lose(a, b - 2, c + 1, d))
        {
            hope = true;
            // #ifdef DEBUG
            //             printf("%d %d %d %d ==> %d %d %d
            //             %d\n",
            //                    a,
            //                    b,
            //                    c,
            //                    d,
            //                    a,
            //                    b - 2,
            //                    c + 1,
            //                    d);
            // #endif  // DEBUG
        }
        if(b >= 1 && c >= 1 && lose(a, b - 1, c - 1, 1))
        {
            hope = true;
            // #ifdef DEBUG
            //             printf("%d %d %d %d ==> %d %d %d
            //             %d\n",
            //                    a,
            //                    b,
            //                    c,
            //                    d,
            //                    a,
            //                    b - 1,
            //                    c - 1,
            //                    1);
            // #endif  // DEBUG
        }
#ifdef DEBUG
        printf("%d %d %d %d is %s\n",
               a,
               b,
               c,
               d,
               hope ? "Win" : "Lose");
#endif  // DEBUG
        dead[a][b][c][d] = !hope;
        return dead[a][b][c][d];
    }
}

bool judge(void)
{
    if(c[1] == 0 && c[2] == 0 && c[3] == 0)
    {
        if(c[0] > 1)
        {
            return c[0] % 2 == 0;
        }
        else
        {
            return false;
        }
    }
    c[0] %= 2;
    c[1] %= 3;
    c[2] = std::min(c[2], 5);
    c[3] = std::min(c[3], 5);
    return !lose(c[0], c[1], c[2], c[3]);
}

int main(void)
{
    int T;
    init();
    while(scanf("%d", &T) != EOF)
    {
        for(int cc = 1; cc <= T; ++cc)
        {
            for(int i = 0; i < 4; ++i)
            {
                scanf("%d", &c[i]);
            }
            printf("Case #%d: %s\n", cc, judge() ? R : H);
        }
    }
    return 0;
}
/*
Case #1: Horse
Case #2: Rabbit
*/
