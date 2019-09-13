#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int MAX_N = 10+1;
bool Used_N[MAX_N] = { false };
int OutputBuffer[MAX_N];
void dfs(int deepth,int n)
{
	int Useable[MAX_N];
	int UseableCount = 0;
	for (size_t i = 1; i <= n; i++)
	{
		if (!Used_N[i])
		{
			Useable[UseableCount++] = i;
		}
	}
	for (size_t i = 0; i < UseableCount; i++)
	{
		OutputBuffer[deepth] = Useable[i];
		Used_N[Useable[i]] = true;
		dfs(deepth + 1, n);
		Used_N[Useable[i]] = false;
	}
	if (UseableCount==0)
	{
		for (size_t i = 0; i < n; i++)
		{
			printf("%5d", OutputBuffer[i]);
		}
		printf("\n");
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	dfs(0, n);
}