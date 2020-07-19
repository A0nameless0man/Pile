#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

const int MAX_N = 507;
int       map[MAX_N][MAX_N];
int       rndNeed[MAX_N][MAX_N];
const int INF = 0x0fffffff;

int judge(int x, int y, int n)
{
    std::vector<int> res;
    int              curres = map[x][y];
    int              ressum = 0;
    int              ans    = 0;
    for(int i = std::max(x - 3, 1); i <= std::min(x + 3, n); ++i)
    {
        int offset = std::abs(x - i);
        int left   = 3 - offset;
        for(int j = std::max(y - left, 1); j <= std::min(y + left, n); ++j)
        {
            if(i != x || j != y)
            {
                res.push_back(map[i][j]);
            }
        }
    }
    std::sort(res.rbegin(), res.rend());
    // res.push_front(curres);
    res.insert(res.begin(), curres);
    for(size_t i = 1; i < res.size(); ++i)
    {
        res[i] += res[i - 1];
    }
    // if(res.size()<8)
    // {
    //     return INF;
    // }
    for(int i = 1; i <= 8; ++i)
    {
        int resGainPerRound = res[std::min(i - 1, static_cast<int>(res.size()) - 1)];
        int nextStepRequire = 8 * i * i;
        int need            = nextStepRequire - ressum;
        // if(!resGainPerRound)
        // {
        //     return INF;
        // }
        int roundNeed = (need - 1) / resGainPerRound + 1;
        ans += roundNeed;
        ressum += roundNeed * resGainPerRound;
    }
    return ans;
}

int main(void)
{
    int t;
    while(std::cin >> t)
    {
        for(int c = 0; c < t; ++c)
        {
            int n, x, y;
            std::cin >> n >> x >> y;
            for(int i = 1; i <= n; ++i)
            {
                for(int j = 1; j <= n; ++j)
                {
                    scanf("%d", &(map[i][j]));
                }
            }

            // for(int i = 1; i <= n; ++i)
            // {
            //     for(int j = 1; j <= n; ++j)
            //     {
            //         // scanf("%d", &(map[i][j]));
            //         printf("%3d ", map[i][j]);
            //     }
            //     printf("\n");
            // }
            int ans = 0x7fffff;
            for(int i = 1; i <= n; ++i)
            {
                for(int j = 1; j <= n; ++j)
                {
                    // scanf("%d", &(map[i][j]));
                    int need = judge(i, j, n);
                    if(i != x || j != y)
                    {
                        need += (std::abs(x - i) + std::abs(y - j) - 1) / 2 + 1;
                    }
                    printf("%3d ", need);
                    ans = std::min(ans, need);
                }
                printf("\n");
            }
            printf("%d\n", ans);
        }
    }
}