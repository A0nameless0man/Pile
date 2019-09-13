#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
void move(int from, int to)
{
	printf("%d,%d-->%d,%d\n", from, from + 1, to, to + 1);
}
void solve(int n)
{
	if (n==4)
	{
		move(4, 9);
		move(8, 4);
		move(2, 8);
		move(7, 2);
		move(1, 7);
	}
	else
	{
		move(n, 2 * n + 1);
		move(2 * n - 1, n);
		solve(n - 1);
	}
}
int main(void)
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		solve(n);
	}
	return 0;
}
