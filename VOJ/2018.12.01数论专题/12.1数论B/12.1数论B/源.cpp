#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long long int n,x;
int main(void)
{
	while (scanf("%d",&n)!=EOF)
	{
		if (n%2==0)
		{
			printf("2^? mod %d = 1\n", n);
			continue;
		}
		for ( x = 0; x < 64; x++)
		{
			if ((2<<x)%n==1)
			{
				printf("2^%d mod %d = 1\n", x, n);
				break;
			}
		}
		if (x==64)
		{
			printf("2^? mod %d = 1\n", n);
		}
	}
}