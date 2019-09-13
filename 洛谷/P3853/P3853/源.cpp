#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int l, n, k, _n[120000] = { 0 }, gap[120000] = { 0 };
int down, up;

int check(int a)
{
	int sum = 0;
	for (size_t i = 0; i < n + 1; i++)
	{
		sum += gap[i] / a;
		//if ((gap[i])%a==0)
		//{
		//	sum--;
		//}
	}
	return sum;//读取要求的空旷指数，返回需要的路标数
}
void countgap(void)
{
	gap[0] = _n[0];
		for (size_t i = 1; i < n; i++)
		{
			gap[i] = _n[i] - _n[i - 1];
		}
	gap[n] = l - _n[n - 1];
}
inline int mid()
{
	return (down + up) / 2;
}
int main(void)
{
	scanf("%d%d%d", &l, &n, &k);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", _n + i);
	}
	countgap();
	down = l / (n + k+1);
	up = (l - n) /( k+1);
	while (down != mid())
	{
		if (check(mid())<=k)
		{
			up = mid();
		}
		else
		{
			down = mid();
		}
	}
	if (check(down) <= k+1)
	{
		printf("%d", down);
	}
	else
	{
		printf("%d", up);
	}
	//while (check(up-1)<=k)
	//{
	//	up--;
	//}
	//printf("%d", up);
	return 0;
}