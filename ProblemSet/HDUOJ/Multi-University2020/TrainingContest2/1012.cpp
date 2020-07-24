#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

const int MAX_N    = 100007;
const int MAX_M    = 27;
const int CHAR_SET = 26;
const int INF      = 0x7fffff;

int pos[MAX_N][CHAR_SET];
int curpos[CHAR_SET];

int  DP[MAX_N][MAX_M][MAX_M];
char A[MAX_N];
char B[MAX_M];

int main(void)
{
    int T;
    while(scanf("%d", &T) != EOF)
    {
        for(int caseid = 0; caseid < T; ++caseid)
        {
            int    q;
            size_t lena;
            size_t lenb;
            scanf("%s%s%d", A, B, &q);
            lena = strlen(A);
            lenb = strlen(B);
            for(size_t i = 0; i < lena; ++i)
            {
                A[i] -= 'a';
            }
            for(size_t i = 0; i < lenb; ++i)
            {
                B[i] -= 'a';
            }
            {
                for(int i = 0; i < CHAR_SET; ++i)
                {
                    pos[lena][i] = curpos[i] = INF;
                }
                for(size_t i = lena - 1; ~i; --i)
                {
                    curpos[A[i]] = i;
                    for(int j = 0; j < CHAR_SET; ++j)
                    {
                        pos[i][j] = curpos[j];
                    }
                }
#ifdef DEBUG
                for(size_t i = lena - 1; ~i; --i)
                {
                    // curpos[A[i]] = i;
                    for(int j = 0; j < lenb; ++j)
                    {
                        // pos[i][j] = curpos[j];
                        printf("%3d",
                               (pos[i][B[j]]) == INF
                                 ? -1
                                 : pos[i][B[j]]);
                    }
                    printf("\n");
                }
#endif  // debug
            }
            {
                for(size_t i = 0; i < lena; ++i)
                {
                    for(size_t k = 0; k < lenb; ++k)
                    {
                        DP[i][0][k] = pos[i][B[k]];
                        if(k)
                        {
                            DP[i][0][k] =
                              std::min(DP[i][0][k],
                                       DP[i][0][k - 1]);
                        }
                    }
                    for(size_t j = 1; j < lenb; ++j)  // lcs
                    {
                        for(size_t k = j; k < lenb;
                            ++k)  // B0~k
                        {
                            if(DP[i][j - 1][k - 1] != INF)
                            {
                                DP[i][j][k] =
                                  pos[DP[i][j - 1][k - 1]
                                      + 1][B[k]];
                                if(k != j)
                                {
                                    DP[i][j][k] = std::min(
                                      DP[i][j][k],
                                      DP[i][j][k - 1]);
                                }
                            }
                            else
                            {
                                DP[i][j][k] = INF;
                            }
                        }
                    }
                }
            }
            {
#ifdef DEBUG
                for(size_t i = 0; i < lena; ++i)
                {
                    for(size_t j = 0; j < lenb; ++j)  // lcs
                    {
                        for(size_t k = 0; k < lenb;
                            ++k)  // B0~k
                        {
                            printf(" %10d ", DP[i][j][k]);
                        }
                        printf("\n");
                    }
                    printf("-----------------\n");
                }
#endif  // debug
            }
            {
                for(int i = 0; i < q; ++i)
                {
                    int l, r;
                    scanf("%d%d", &l, &r);
                    --l;
                    --r;
                    int ans = 0;
                    for(; ans < lenb
                          && DP[l][ans][lenb - 1] <= r;
                        ++ans)
                    {
#ifdef DEBUG
                        printf("DP[%d][%d][%ld - 1]=%d\n",
                               l,
                               ans,
                               lenb,
                               DP[l][ans][lenb - 1]);
#else
                        continue;
#endif  // debug
                    }
#ifdef DEBUG
                    printf("ans=%d\n", ans);
#endif  // debug
        // --ans;
                    printf("%ld\n",
                           r - l + 1 + lenb - 2 * ans);
                }
            }
        }
    }
}