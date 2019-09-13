#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int n;
	int *a, *b;
	while (scanf("%d",&n)!=EOF)
	{
		a = (int*)malloc(n * sizeof(int));
		b = (int*)malloc(n * sizeof(int));
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", a + i);
		}
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", b + i);
		}
		for (size_t i = 0; i < n; i++)
		{
			printf("%d", a[i] + b[i]);
			if (i<n-1)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
		free(a);
		free(b);
	}
}