#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
/*
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。
但是这种导弹拦截系统有一个缺陷：
虽然它的第一发炮弹能够到达任意的高度，
但是以后每一发炮弹都不能高于前一发的高度。
某天，雷达捕捉到敌国的导弹来袭。
由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
输入导弹依次飞来的高度，
计算
这套系统最多能拦截多少导弹，
如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。
*/
/*
假设f(i)的返回值是对于第i颗导弹，所能达成的最长序列。
那么，f(i)应当在以下值中取最大值后+1：0，任何f(j)满足j<i且R[j]>=R[i];
*/

//以上内容不要提交
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int  MAX_N = 100007;
const int  MAX_H = 50007;
int        Record[MAX_N];
int        Records = 0;
int        DP_mem[MAX_N];  //-1:NOT Caulated
int        systems[MAX_N];
int        MaxHightByLen[MAX_H];
int        SystemNeeded;
int        MaxLen;
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int DP(int i)
{
    if(DP_mem[i] != -1)
    {
        return DP_mem[i];
    }
    else
    {
        int MAX = 0;
        for(size_t j = 0; j < i; j++)
        {
            if(Record[j] >= Record[i])
            {
                MAX = max(MAX, DP(j));
            }
        }
        MAX++;
        return DP_mem[i] = MAX;
    }
}
int main(void)
{
#ifdef LOCAL
l:;
    int n;
    scanf("%d", &n);
#endif  // LOCAL
    Records = 0;
    while(scanf("%d", &Record[Records]) != EOF)
    {
        DP_mem[Records]  = -1;
        systems[Records] = MAX_H;
        Records++;
#ifdef LOCAL
        if(n <= Records)
        {
            break;
        }
#endif  // LOCAL
    }
    SystemNeeded     = 0;
    MaxLen           = 0;
    MaxHightByLen[0] = MAX_H;
    for(size_t i = 0; i < Records; i++)
    {
        int j;
        //		for (j = 0; systems[j] < Record[i]; j++);
        if(systems[0] >= Record[i])
        {
            systems[0] = Record[i];
        }
        else
        {
            int left = 0, right = SystemNeeded + 1;
            while(left < right)
            {
                int mid = (left + right) / 2;
                if(systems[mid] >= Record[i])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            j            = left;
            systems[j]   = Record[i];
            SystemNeeded = max(SystemNeeded, j);
        }
        if(MaxHightByLen[0] < Record[i])
        {
            MaxHightByLen[0] = Record[i];
        }
        else
        {
            int left = 0, right = MaxLen + 1;
            while(left < right)
            {
                int mid = (left + right) / 2;
                if(MaxHightByLen[mid] < Record[i])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            MaxHightByLen[right] = Record[i];
            MaxLen               = max(MaxLen, right);
        }
        //		MaxLen = max(DP(i), MaxLen);
    }
    printf("%d\n%d\n", MaxLen, SystemNeeded + 1);
#ifdef LOCAL
    system("pause");
    goto l;
#endif  // LOCAL

    return 0;
}
