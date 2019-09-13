#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int pow[11];
void PrePow(int n)
{
	pow[0] = 0;
	pow[1] = 1;
	for (int i = 2; i < 11; i++)
	{
		int mul = 1;
		for (int j = 0; j < n; j++)
		{
			mul *= i;
		}
		pow[i] = mul;
	}
}
int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		PrePow(n);
		register int i = pow[10] / 10 - 1, _i = i;
		register int lim = pow[10];
		register int sum = 0;
		while (i < lim)
		{
			sum = 0;
			_i = i;
			while (_i > 0)
			{
				sum += pow[_i % 10];
				_i /= 10;
			}
			if (i == sum)
			{
				printf("%d\n", i);
			}
			i++;
		}
	}
	return 0;
}
