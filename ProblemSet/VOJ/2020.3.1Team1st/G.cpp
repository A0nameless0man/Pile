#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Rec
{
    char chr;
    int  cnt
}

const int MAX_N = 300007;
const int MAX_M = 1 << 20;
int       map[MAX_M];

int main(void)
{
    int N;
    while(scanf("%d", &N) != EOF)
    {
        char    buf[MAX_N];
        int32_t cur[MAX_N];
        int32_t prefix[MAX_N];
        int     ans = 0;
        for(int i = 0; i < MAX_M; ++i)
        {
            map[i] = -1;
        }
        scanf("%s", buf);
        for(int i = 0; i < N; ++i)
        {
            buf[i] -= 'a';
            cur[i]    = 1 << buf[i];
            prefix[i] = cur[i];
            if(i > 0)
            {
                prefix[i] ^= prefix[i - 1];
            }
            if(map[prefix[i]]==-1)
            {
                map[prefix[i]] == i;
            }
        }
        {

        }
    }
}