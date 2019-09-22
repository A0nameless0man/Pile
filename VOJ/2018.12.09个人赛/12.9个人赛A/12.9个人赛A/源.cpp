#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int MAX_N = 107;
int m, k, n;
int houses[MAX_N];
int min(int a, int b)
{
	return a > b ? b : a;
}
int abs(int x)
{
 	return x > 0 ? x : -x;
}
int main(void)
{
	while (scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		int minDis = n;
		m--;
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &houses[i]);
			if (houses[i]<=k&&houses[i]!=0)
			{
				minDis = min(minDis, abs(m - i));
			}
		}
		printf("%d\n", minDis*10);
	}
	return 0;
}