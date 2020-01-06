#include <cstdio>
#include <vector>
const int        MAX_N = 100007;
int              prime[MAX_N][2];
std::vector<int> sets[MAX_N / 10];
void             init(void)
{
    for(int i = 0; i < MAX_N; i++)
    {
        prime[i][0] = -1;
        prime[i][1] = 0;
    }
    int cnt = 0;
    for(int i = 2; i < MAX_N; i++)
    {
        if(prime[i][0] == -1)
        {
            for(int j = 1; i * j < MAX_N; j++)
            {
                prime[i * j][0] = cnt;
                prime[i * j][1] = j;
            }
            cnt++;
        }
    }
}
int main(void)
{
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF)
    {
        int cnt1 = 0;
        for(int i = 0; i < MAX_N / 10; i++)
        {
            sets[i].clear();
        }
        for(int i = 0; i < n; i++)
        {
            int buf;
            scanf("%d", buf);
            if(buf == 1)
            {
                cnt1++;
            }
            else if(prime[buf][0] != -1)
            {
                sets[i].push_back(prime[buf][1]);
            }
        }
        for(int i = 0; i < MAX_N / 10; i++)
        {
            for(int j = 0; j < sets[i].size(); j++) {}
        }
    }
}