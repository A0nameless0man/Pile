#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
template <typename T> void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}
long long po(int n)
{
	long long r = 1;
	for (int i = 0; i < n; i++)
	{
		r *= 2;
		r %= 10000;
	}
	return r;
}
long long hano(int n)
{
	long long  sum = 0;
	long long _2 = 1;
	for (int i = 1; i <= n; i++)
	{
		sum += po((int)(sqrt(8*i-7)-1)/2);
		sum %= 10000;
	}
	return sum;
}
const int MAX_N = 10007;
int n, m, a, b, j, k;
int main(void)
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // DEBUG
	
	while (scanf("%d",&n)!=EOF)
	{
		printf("%lld\n", hano(n));
	}
#ifdef DEBUG
	system("pause");
	system("pause");
#endif // DEBUG

	return 0;
}
