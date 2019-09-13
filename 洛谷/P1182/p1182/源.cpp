#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N[120000] = {0 }, n = 0, m = 0;
int check(int k)
{
	int a = 0, b = 0;
	int sum = 0;
	while (b < n)
	{
		while (sum + N[b] <= k && b < n)
		{
			sum += N[b];
			b++;
		}
		a++;
		sum = 0;
	}
	return a;
}
int main(void)
{
	int down = 0, up = 0;
	int _m;
	//FILE* f = freopen("testdata.in", "r",stdin);
	scanf("%d%d", &n, &m);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", N + i);
		up += N[i];
		if (N[i] > down)
		{
			down = N[i];
		}
	}
	while ((down+up)/2!=down)
	{
		
		if ((_m=check((down+up)/2))>m)
		{
			down = (down + up) / 2;
		}
		else
		{
			up = (down + up) / 2;
		}
	}
	//up += 2;
	//while (check(up-1)<=m)
	//{
	//	up--;
	//}
	//if (check(down) == m)
	//else
	//printf("%d", (down+up)/2);
	if (check(down) <= m)
		printf("%d", down);
	else
		printf("%d", up);
}