#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
const int MAX_N = 1007;//物品数量
const int MAX_M = 1007;//可用空间
const int MAX_T = 107;//组数
struct item
{
	int Weight;
	int Value;
	int GroupID;
};
int m, n,GroupCount;
int NumOfTeams[MAX_T];
item Teams[MAX_T][MAX_N];
int mem_DP[MAX_T][MAX_M];
inline int max(int a, int b)
{
	return a > b ? a : b;
}
void ResetMEM(void)
{
	for (size_t i = 0; i < MAX_T; i++)
	{
		for (size_t j = 0; j < MAX_M; j++)
		{
			mem_DP[i][j] = -1;
		}
		NumOfTeams[i] = 0;
	}
}
int DP(int i, int j)//TeamID，WeightUseable
{
	if (i<0||j<0)
	{
		return 0;
	}
	else
	{
		if (mem_DP[i][j]!=-1)
		{
			return mem_DP[i][j];
		}
		else
		{
			int Result = DP(i-1,j);
			for (size_t k = 0; k < NumOfTeams[i]; k++)
			{
				if (Teams[i][k].Weight<=j)
				{
					Result = max(Result, DP(i - 1, j - Teams[i][k].Weight) + Teams[i][k].Value);
				}
			}
			return mem_DP[i][j] = Result;
		}
	}
}
int main(void)
{
	while (scanf("%d%d",&m,&n)!=EOF)
	{
		GroupCount = 0;
		ResetMEM();
		for (size_t i = 0; i < n; i++)
		{
			item temp;
			scanf("%d%d%d", &temp.Weight, &temp.Value, &temp.GroupID);
			Teams[temp.GroupID][NumOfTeams[temp.GroupID]++] = temp;
			GroupCount = max(GroupCount, temp.GroupID);
		}
		printf("%d\n", DP(GroupCount, m));
	}
	return 0;
}
