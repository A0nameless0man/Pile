#include <cstdio>

const int MAX_N = 100007;
char      s[MAX_N], t[MAX_N];
int       pfx_cnt_s[MAX_N];
int       pfx_cnt_t[MAX_N];
int       sfx_dif[MAX_N];
int       main(void)
{
    int T;
    while(scanf("%d", &T) != EOF)
    {
        for(int id = 0; id < T; ++id)
        {
            int n;
            scanf("%d", &n);
            scanf("%s", s);
            scanf("%s", t);
            int pos = 0;
            int sum = 0;
            while(s[pos] != '\0')
            {
                if(s[pos] == '0')
                {
                    ++sum;
                }
                pfx_cnt_s[pos] = sum;
                ++pos;
            }
            pos = 0;
            sum = 0;
            while(t[pos] != '\0')
            {
                if(t[pos] == '0')
                {
                    ++sum;
                }
                pfx_cnt_t[pos] = sum;
                ++pos;
            }
            sum          = 0;
            sfx_dif[pos] = sum;
            while(pos--)
            {
                if(t[pos] != s[pos])
                {
                    ++sum;
                }
                sfx_dif[pos] = sum;
            }
            pos     = 1;
            int ans = sfx_dif[0];
            while(s[pos] != '\0')
            {

                if(s[pos] == '0')
                {
                    int cost[] = { pfx_cnt_s[pos - 1],
                                   1,
                                   pos - pfx_cnt_t[pos - 1],
                                   (('1' != t[pos]) ? 1
                                                    : 0),
                                   sfx_dif[pos + 1] };
                    int sum    = cost[0] + cost[1] + cost[2]
                              + cost[3] + cost[4];
                    if(sum < ans)
                    {
                        ans = sum;
                    }
                }
                else
                {
                    int cost[] = { 1,
                                   pfx_cnt_s[pos - 1],
                                   1,
                                   pos - pfx_cnt_t[pos - 1],
                                   (('1' != t[pos]) ? 1
                                                    : 0),
                                   sfx_dif[pos + 1] };
                    int sum    = cost[0] + cost[1] + cost[2]
                              + cost[3] + cost[4] + cost[5];
                    if(sum < ans)
                    {
                        ans = sum;
                    }
                }
                ++pos;
            }
            {
                int cost[] = { pfx_cnt_s[pos - 1],
                               1,
                               pos - pfx_cnt_t[pos - 1],
                               1 };
                int sum =
                  cost[0] + cost[1] + cost[2] + cost[3];
                if(sum < ans)
                {
                    ans = sum;
                }
            }
            // std::cout << ans << std::endl;
            printf("%d\n", ans);
        }
    }
}