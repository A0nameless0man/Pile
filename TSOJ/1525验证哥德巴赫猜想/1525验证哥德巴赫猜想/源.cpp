#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
bool IsPrime(int n)
{
	int sqr = sqrt(n);
	if (n==2)
	{
		return true;
	}
	for (size_t i = 2; i < sqr+1; i++)
	{
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main(void)
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (size_t i = 2; i < n/2+1; i++)
		{
			if (IsPrime(i)&&IsPrime(n-i))
			{
				printf("%d=%d+%d\n", n, i, n - i);
				break;
			}
		}
	}
	return 0;
}