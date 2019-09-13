#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
//1\2 的斐波那契数列
const long long int MAX_N = 5e6 + 7;
const long long int MOD = 10000000007;
long long int mem[MAX_N];
long long int feb(long long int n)
{
	if (mem[n]!=-1)
	{
		return mem[n];
	}
	else
	{
		return mem[n] = (feb(n - 1) + feb(n - 2))%MOD;
	}
}
int main(void)
{
	long long int n;
	while (scanf("%lld",&n)!=EOF)
	{
		for (long long int i = 0; i < MAX_N; i++)
		{
			mem[i] = -1;
		}
		mem[1] = 1;
		mem[2] = 2;
		long long int sum = 0;
		for (long long int i = 1; i <= n; i++)
		{
			sum += feb(i);
			sum %= MOD;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
