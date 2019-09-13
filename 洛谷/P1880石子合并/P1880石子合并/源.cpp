#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int MAX_N = 107;
struct ChainTable
{
	int Stone;
	int Child;
};
ChainTable ForMax[MAX_N], ForMin[MAX_N];
int n, MaxCost, MinCost;
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a > b ? b : a;
}
int AddWithChild(int n, bool IsMax)
{
	ChainTable *T;
	if (IsMax)
	{
		T = ForMax;
	}
	else
	{
		T = ForMin;
	}
	T[n].Stone += T[T[n].Child].Stone;
	T[n].Child = T[T[n].Child].Child;
	return T[n].Stone;
}
int mem_DP[MAX_N][MAX_N];
int sum[MAX_N][MAX_N];
void ResetSum(void)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			sum[i][j] = -1;
		}
	}
}
void ResetMem(void)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			mem_DP[i][j] = -1;
		}
	}
}
int GETsum(int i, int j)
{
	if (sum[i][j] != -1)
	{
		return sum[i][j];
	}
	else
	{
		int r = 0;
		if (j > i)
		{
			for (size_t k = i; k <= j; k++)
			{
				r += ForMax[k].Stone;
			}
		}
		else
		{
			for (size_t k = 0; k <= j; k++)
			{
				r += ForMax[k].Stone;
			}
			for (size_t k = i; k < n; k++)
			{
				r += ForMax[k].Stone;
			}
		}
		return sum[i][j] = r;
	}
}
int MaxDp(int i, int j)
{
	if (i < 0 || j < 0 || i == j)
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
			int r = 0;
			for (size_t k = i; k != j; k = ForMax[k].Child)
			{
				r = max(r, MaxDp(i, k) + MaxDp(ForMax[k].Child, j) + GETsum(i, j));
			}
			return mem_DP[i][j] = r;
		}
	}
}
int MinDp(int i, int j)
{
	if (i < 0 || j < 0 || i == j)
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
			int r = 1e10;
			for (size_t k = i; k != j; k = ForMax[k].Child)
			{
				r = min(r, MinDp(i, k) + MinDp(ForMax[k].Child, j) + GETsum(i, j));
			}
			return mem_DP[i][j] = r;
		}
	}
}
int main(void)
{
	//freopen("testdata.in", "r", stdin);
	while (scanf("%d", &n) != EOF)
	{
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &ForMax[i].Stone);
			ForMin[i].Stone = ForMax[i].Stone;
			ForMax[i].Child = ForMin[i].Child = i + 1;
		}
		ForMax[n - 1].Child = ForMin[n - 1].Child = 0;//使用数组来维护链表，避免动态分配的开销
		MaxCost = 0;
		MinCost = 1e10;
		//while (ForMax[ForMaxRoot].Child != ForMaxRoot)
		//{
		//	Max = 0;
		//	for (size_t i = 0; i < ForMaxCount; i++)
		//	{
		//		if (ForMax[ForMaxRoot].Stone + ForMax[ForMax[ForMaxRoot].Child].Stone > Max)
		//		{
		//			Max = ForMax[ForMaxRoot].Stone + ForMax[ForMax[ForMaxRoot].Child].Stone;
		//			MaxAt = ForMaxRoot;
		//		}
		//		ForMaxRoot = ForMax[ForMaxRoot].Child;
		//	}
		//	MaxCost += AddWithChild(MaxAt, true);
		//	ForMaxRoot = MaxAt;
		//	ForMaxCount--;
		//}
		//while (ForMinRoot != ForMin[ForMinRoot].Child)
		//{
		//	Min = 1e10;
		//	for (size_t i = 0; i < ForMinCount; i++)
		//	{
		//		if (ForMin[ForMinRoot].Stone + ForMin[ForMin[ForMinRoot].Child].Stone < Min)
		//		{
		//			Min = ForMin[ForMinRoot].Stone + ForMin[ForMin[ForMinRoot].Child].Stone;
		//			MinAt = ForMinRoot;
		//		}
		//		ForMinRoot = ForMin[ForMinRoot].Child;
		//	}
		//	MinCost += AddWithChild(MinAt, false);
		//	ForMinRoot = MinAt;
		//	ForMinCount--;
		//}
		ResetMem();
		ResetSum();
		for (size_t i = 0; i < n; i++)
		{
			MaxCost = max(MaxCost, MaxDp(i, (i - 1 + n) % n));
		}
		ResetMem();
		for (size_t i = 0; i < n; i++)
		{
			MinCost = min(MinCost, MinDp(i, (i - 1 + n) % n));
		}
		printf("%d\n%d\n", MinCost, MaxCost);
	}
	return 0;
}