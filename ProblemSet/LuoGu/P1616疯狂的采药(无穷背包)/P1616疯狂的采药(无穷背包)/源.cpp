#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
//״̬��ʣ��ռ�
//ת�Ʒ��̣�f(i)=max(0;j=m){f(i-V[j])+C[j]}or 0
//�Ż������仯����
const int  MAX_T = 100007;
int        V[MAX_T];
int        C[MAX_T];
int        t, m;
int        mem_DP[MAX_T];
inline int imax(int a, int b)
{
    return a > b ? a : b;
}
inline int imin(int a, int b)
{
    return a > b ? b : a;
}
int DP(int i)
{
    if(mem_DP[i] != -1)
    {
        return mem_DP[i];
    }
    else
    {
        int max = 0;
        for(size_t j = 0; j < m; j++)
        {
            if(i >= V[j])
            {
                max = imax(max, DP(i - V[j]) + C[j]);
            }
        }
        return mem_DP[i] = max;
    }
}
int main(void)
{
    while(scanf("%d%d", &t, &m) != EOF)
    {
        int min = t;
        for(size_t i = 0; i < m; i++)
        {
            scanf("%d%d", &V[i], &C[i]);
            min = imin(min, V[i]);
        }
        for(size_t i = min; i <= t; i++)
        {
            mem_DP[i] = -1;
        }
        for(size_t i = 0; i < min; i++)
        {
            mem_DP[i] = 0;  //����������õĿռ�
        }
        printf("%d\n", DP(t));
    }
    return 0;
}
