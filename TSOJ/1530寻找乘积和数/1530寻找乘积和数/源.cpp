#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n, bitmul, bitsum;
	while (scanf("%d", &n) != EOF)
	{
		for (size_t i = 0; i <= n; i++)
		{
			int _i = i;
			bitmul = 1;
			bitsum = 0;
			while (_i!=0)
			{
				bitmul *= _i % 10;
				bitsum += _i % 10;
				_i /= 10;
			}
			if (bitmul==bitsum)
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}