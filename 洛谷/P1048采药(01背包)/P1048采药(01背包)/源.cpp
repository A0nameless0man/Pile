#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
//t秒内采药，药要花费不同时间，有不同价值。
//对于第i株药，剩余j的时间，有d(i,j)=max(d(i-1,j),d(i-1,j-Vi)+Ci)
//记忆化搜索。
int t, m;
const int MAX_M = 107;
const int MAX_T = 1007;
int mem_DP[MAX_M][MAX_T];
int V[MAX_M];//体积
int C[MAX_M];//价值
inline int max(int a, int b)
{
	return a > b ? a : b;
}
int DP(int i, int j)
{
	if (i<0||i>=m||j<=0||j>t)
	{
		return 0;
	}
	else
	{
		if (mem_DP[i][j] != -1)
		{
			return mem_DP[i][j];
		}
		else
		{
			return mem_DP[i][j] = j >= V[i] ? max(DP(i - 1, j), DP(i - 1, j - V[i]) + C[i]) : DP(i - 1, j);
		}
	}
}
int main(void)
{
	while (scanf("%d%d", &t, &m) != EOF)
	{
		for (size_t i = 0; i < m; i++)
		{
			scanf("%d%d", &V[i], &C[i]);
			for (size_t j = 0; j <= t; j++)
			{
				mem_DP[i][j] = -1;
			}
		}
		printf("%d\n", DP(m - 1, t));
	}
	return 0;
}
