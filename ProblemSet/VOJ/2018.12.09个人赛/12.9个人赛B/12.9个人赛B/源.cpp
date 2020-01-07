#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
const int MAX_N = 1000007;
int       m, n, k, ah, vi, vj, bone;
bool      IsWhole[MAX_N], OnTheGround;
int       main(void)
{
    while(scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        bone        = 1;
        OnTheGround = false;
        for(size_t i = 0; i < n; i++)
        {
            IsWhole[i] = false;
        }
        for(size_t i = 0; i < m; i++)
        {
            scanf("%d", &ah);
            IsWhole[ah] = true;
        }
        for(size_t i = 0; i < k; i++)
        {
            if(IsWhole[bone])
            {
                OnTheGround = true;
            }
            scanf("%d%d", &vi, &vj);
            if(bone == vi && !OnTheGround)
            {
                bone = vj;
            }
            else
            {
                if(bone == vj && !OnTheGround)
                {
                    bone = vi;
                }
            }
        }
        printf("%d\n", bone);
    }
    return 0;
}