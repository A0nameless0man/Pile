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
const int MAX_N = 10007;
int n, m, a, b, j, k;
int main(void)
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // DEBUG
	
	while (scanf("%d",&n)!=EOF)//重点并不在于某个数有几个因数，而在于一个数成为了几个数的因数也就是n/i
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += n / i;
		}
		printf("%d\n", sum);
	}
#ifdef DEBUG
	system("pause");
	system("pause");
#endif // DEBUG

	return 0;
}
