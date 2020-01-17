#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using LL = long long;

const long long MAX_N = 100;
const long long MAX_M = 10;
const long long MAX_W = 5000;

int  AcceptCount[MAX_M];
bool Accepted[MAX_N][MAX_M];
int  MemberAcceptCount[MAX_N];
int  SubmitCount[MAX_N];
int  MaxContinueFail[MAX_N][MAX_M];
int  CurentContinueFail[MAX_N][MAX_M];

// std::vector<char> Submits[MAX_N][MAX_M];

long long square(long long i)
{
    return i * i;
}

void init(void)
{
    for(LL m = 0; m < MAX_M; ++m)
    {
        AcceptCount[m] = 0;
        for(LL n = 0; n < MAX_N; ++n)
        {
            Accepted[n][m]           = false;
            MaxContinueFail[n][m]    = 0;
            CurentContinueFail[n][m] = 0;
            // Submits[n][m].clear();
        }
    }
    for(LL n = 0; n < MAX_N; ++n)
    {
        MemberAcceptCount[n] = 0;
        SubmitCount[n]       = 0;
    }
}

int main(void)
{
    long long n, m, w;

    while(std::cin >> n >> m >> w)
    {
        {
            init();
        }

        {
            int x, y, c;
            for(LL wi = 0; wi < w; ++wi)
            {
                std::cin >> x >> y >> c;
                --x;
                --y;
                // Submits[x][y].push_back(c);
                if(c)
                {
                    if(!Accepted[x][y])  // Is His First Accept
                    {
                        Accepted[x][y] = true;
                        ++AcceptCount[y];
                        ++MemberAcceptCount[x];
                    }
                    CurentContinueFail[x][y] = 0;
                }
                else
                {
                    ++CurentContinueFail[x][y];
                    MaxContinueFail[x][y] =
                      std::max(CurentContinueFail[x][y], MaxContinueFail[x][y]);
                }
                ++SubmitCount[x];
            }
        }

        {
            auto Rule = [&](LL i) -> LL {
                {  // Rule 1
                    if(SubmitCount[i] == 0)
                    {
                        return 998244353;
                    }
                }

                {  // Rule 2
                    if(MemberAcceptCount[i] == 0)
                    {
                        return 1000000;
                    }
                }

                {  // Rule 3
                    if(MemberAcceptCount[i] == m)
                    {
                        return 0;
                    }
                }

                LL ans = 0;
                
                {//Rule 4 && 5
                    for(LL mi = 0; mi < m;++mi)
                    {
                        if(AcceptCount[mi]>0&&!Accepted[i][mi])
                        {
                            ans += 20;
                            if(AcceptCount[mi]>=n/2)
                            {
                                ans += 10;
                            }
                        }
                    }
                }

                {//Rule 6 && 7
                    for(LL mi = 0; mi < m; ++mi)
                    {
                        ans += square(MaxContinueFail[i][mi]);
                        if(!Accepted[i][mi])
                        {
                            ans += square(MaxContinueFail[i][mi]);
                        }
                    }
                }

                return ans;
            };
            for(LL i = 0; i < n; ++i)
            {
                std::cout << Rule(i) << std::endl;
            }
        }

    }
}