#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
/*
ĳ��Ϊ�˷����й��ĵ���Ϯ������չ��һ�ֵ�������ϵͳ��
�������ֵ�������ϵͳ��һ��ȱ�ݣ�
��Ȼ���ĵ�һ���ڵ��ܹ���������ĸ߶ȣ�
�����Ժ�ÿһ���ڵ������ܸ���ǰһ���ĸ߶ȡ�
ĳ�죬�״ﲶ׽���й��ĵ�����Ϯ��
���ڸ�ϵͳ�������ý׶Σ�����ֻ��һ��ϵͳ������п��ܲ����������еĵ�����
���뵼�����η����ĸ߶ȣ�
����
����ϵͳ��������ض��ٵ�����
���Ҫ�������е�������Ҫ�䱸���������ֵ�������ϵͳ��
*/
/*
����f(i)�ķ���ֵ�Ƕ��ڵ�i�ŵ��������ܴ�ɵ�����С�
��ô��f(i)Ӧ��������ֵ��ȡ���ֵ��+1��0���κ�f(j)����j<i��R[j]>=R[i];
*/

//�������ݲ�Ҫ�ύ
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
