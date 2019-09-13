#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	double mul;
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		mul = 0.0;
		for (int i = 1; i <= n; i++)
		{
			mul += log10(i);
		}
		printf("%d\n", (int)(mul + 0.99));
	}
	return 0;
}
