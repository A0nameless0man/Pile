#include <cstdio>

int main(void)
{
    int T;
    while(scanf("%d", &T) != EOF)
    {
        for(int t = 0; t < T; ++t)
        {
            int map[3][3];
            int ans = 0;
            for(int i = 0; i < 3; ++i)
            {
                for(int j = 0; j < 3; ++j)
                {
                    scanf("%d", &map[i][j]);
                }
            }
            for(int i = 0; i < 3; ++i)
            {
                for(int j = 0; j < 3; ++j)
                {
                    int win = true;
                    for(int m = 0; m < 3; ++m)
                    {
                        for(int n = 0; n < 3; ++n)
                        {
                            if(i != m && j != n)
                            {
                                int x  = 3 - i - m;
                                int y  = 3 - j - n;
                                int sg = 0;
                                for(int a = 0; a < 3; ++a)
                                {
                                    for(int b = 0; b < 3;
                                        ++b)
                                    {
                                        if(a == x && b == y)
                                        {
                                            sg ^= map[a][b];
                                        }
                                        else if(
                                          (a != i || b != j)
                                          && (a != m
                                              || b != n))
                                        {
                                            sg ^=
                                              map[a][b] - 1;
                                        }
                                    }
                                }
                                if(!sg)
                                {
                                    win = false;
                                }
                            }
                        }
                    }
                    if(win)
                    {
                        ++ans;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
}