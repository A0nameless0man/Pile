#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int MAX_N = 100007;
const int MAX_T = 1001;
int n, TeH, TeM, TsH, TsM, T;
int mem_dp[MAX_T];
int ynT[MAX_N];
int ynP[MAX_N];
int ynC[MAX_N];
inline int max(int a, int b)
{
	return a > b ? a : b;
}
inline int min(int a, int b)
{
	return b > a ? a : b;
}
inline void ResetMem(void)
{
	for (size_t i = 0; i <= T; i++)
	{
			mem_dp[i] = 0;
	}
}
int ynDP(int i, int j)
{
	if (i < 0 || j <= 0)
	{
		return 0;
	}
	else
	{
			if (j>=ynT[i])
			{
				return mem_dp[j] = max(mem_dp[j], mem_dp[ j - ynT[i]] + ynC[i]);
			}
			else
			{
				return mem_dp[j] = mem_dp[j];
			}
	}
}
int main(void)
{
	//freopen("testdata.in", "r", stdin);
	while (scanf("%d:%d%d:%d%d", &TsH, &TsM, &TeH, &TeM, &n) != EOF)
	{
		T = (TeH - TsH) * 60 + TeM - TsM;
		for (size_t i = 0; i < n;)
		{
			scanf("%d%d%d", &ynT[i], &ynC[i], &ynP[i]);
			int p = ynP[i];
			int t = ynT[i];
			int c = ynC[i];
			int k = 1;
			if (p==0)
			{
				p = T / t;
			}
			int RestP = p;
			while (k<p/2)
			{
					ynC[i] = c * k;
					ynP[i] = k;
					ynT[i] = t * k;
					RestP -= k;
					k <<= 1;
					n++;
					i++;
			}
			ynC[i] = c * RestP;
			ynP[i] = RestP;
			ynT[i] = t * RestP;
			i++;
		}
		ResetMem();
		for (size_t i = 0; i < n; i++)
		{
			for (int j = T; j >=0 ; j--)
			{
				ynDP(i, j);
			}
		}
		printf("%d\n", mem_dp[T]);
	}
	return 0;
}