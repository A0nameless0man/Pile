#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
const int MAX_P = 150007;
const int INF   = 1e10;
int       potions[MAX_P];
int       p;
int       mem_DP[MAX_P][2];
void      Resetmem(void);
int       oddDP(int, bool);
int       evenDP(int);
int       max(int, int);
int       main(void)
{
    while(scanf("%d", &p) != EOF)
    {
        for(size_t i = 0; i < p; i++)
        {
            scanf("%d", &potions[i]);
        }
        Resetmem();
        // start
        // int result = 0;
        // for (size_t i = 0; i < p; i++)
        //{
        //	result = max(result, oddDP(i,true));
        //}//end这是基于递归的方法，改进成不用递归
        // start
        // for (size_t i = 0; i < p; i++)
        //{
        //	for (size_t odd = 0; odd < 2; odd++)
        //	{
        //		mem_DP[i][odd] = max(mem_DP[i - 1][odd], mem_DP[i - 1][!odd] + (odd ?
        //potions[i] : -potions[i]));
        //	}
        //}//end loop
        // printf("%d\n", result);
        printf("%d\n", oddDP(p - 1, true));
    }
    return 0;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
void Resetmem(void)
{
    for(size_t i = 0; i < MAX_P; i++)
    {
        mem_DP[i][1] = mem_DP[i][0] = -1;
    }
}
int oddDP(int n, bool isodd)
{
    int odd = isodd ? 0 : 1;
    if(n == 0)
    {
        return isodd ? potions[n] : 0;
    }
    else
    {
        if(mem_DP[n][odd] != -1)
        {
            return mem_DP[n][odd];
        }
        else
        {
            // int result = 0;
            // for (size_t i = 0; i < n; i++)
            //{
            //	result = max(result, oddDP(i,!isodd));
            //}
            // return mem_DP[n][odd] =( result + (isodd ? potions[n] :
            // -potions[n]));//是我沙雕，转移方程写复杂了。
            mem_DP[n][odd] =
              max(oddDP(n - 1, isodd), oddDP(n - 1, !isodd) + (isodd ? potions[n] : -potions[n]));
            // if (isodd)
            //{
            //	mem_DP[n][odd] = max(mem_DP[n][odd], potions[n]);
            //}
            return mem_DP[n][odd];
        }
    }
}