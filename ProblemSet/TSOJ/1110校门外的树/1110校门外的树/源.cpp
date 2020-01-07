#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
const int MAX_N = 100007;
bool      trees[MAX_N];
int       l, m, left, right;
int       main(void)
{
    while(scanf("%d%d", &l, &m) != EOF)
    {
        for(size_t i = 0; i <= l; i++)
        {
            trees[i] = true;
        }
        for(size_t i = 0; i < m; i++)
        {
            scanf("%d%d", &left, &right);
            for(; left <= right; left++)
            {
                trees[left] = false;
            }
        }
        int sum = 0;
        for(size_t i = 0; i <= l; i++)
        {
            sum += trees[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}
