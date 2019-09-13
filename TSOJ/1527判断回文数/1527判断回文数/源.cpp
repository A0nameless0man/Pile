#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n, _n,n_;
	while (scanf("%d", &n) != EOF)
	{
		n_ = n;
		_n = 0;
		while (n != 0)
		{
			_n = n % 10 + _n * 10;
			n /= 10;
		}
		if (n_==_n&&n_%10!=0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}