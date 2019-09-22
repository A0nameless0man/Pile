#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int MAX_T = 1007;
const int MAX_W = 37;
int T, W;
int apples[MAX_T][2];
int mem_DP[MAX_T][MAX_W];
inline int max(int a, int b)
{
	return a > b ? a : b;
}
void ResetMEM(void)
{
	for (size_t i = 0; i < MAX_T; i++)
	{
		for (size_t j = 0; j < MAX_W; j++)
		{
			mem_DP[i][j] = -1;
		}
	}
}
int DP(int t, int w)//t是阶段，w是已经用了的转换
{
	if (t < 0)
	{
		return 0;
	}
	else
	{
		if (w<=0)
		{
			int r = 0;
			for (size_t i = 0; i <= t; i++)
			{
				r += apples[i][0];
			}
			return r;
		}
		//if (w >= W)
		//{
		//	return sumapples[t][W % 2 + 1];
		//}
		//else
		//{
		if (mem_DP[t][w] != -1)
		{
			return mem_DP[t][w];
		}
		else
		{
			return mem_DP[t][w] = max(DP(t - 1, w), DP(t - 1, w - 1)) + apples[t][w % 2];
		}
		//int result = sumapples[t][(W - w) % 2 + 1];
		//for (size_t i = 0; i < t; i++)
		//{
		//	result = max(result, DP(i, w + 1) + (sumapples[t][(W - w) % 2 + 1] - sumapples[i][(W - w) % 2 + 1]));
		//}
		//return mem_DP[t][w] = result;
	//}
	}
}
int main(void)
{
	while (scanf("%d%d", &T, &W) != EOF)
	{
		ResetMEM();
		int IsUnedrTree;
		for (size_t i = 0; i < T; i++)
		{
			scanf("%d", &IsUnedrTree);
			apples[i][IsUnedrTree/2] = 1;
			apples[i][IsUnedrTree % 2] = 0;
		}
		int result = 0;
		for (size_t i = 0; i <= W; i++)
		{
			result = max(result, DP(T - 1, i));
		}
		printf("%d\n", result);
		//return 0;
	}
	return 0;
}