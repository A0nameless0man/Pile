#define _CRT_SECURE_NO_WARNINGS
#define DEBUG
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
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
const int MAX_M = 1007;
int n, m, a, b, j, k;
int mem_DP[MAX_M];
int container[MAX_N];
int main(void)
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // DEBUG

	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &container[i]);
		}
		for (int i = 0; i < MAX_M; i++)
		{
			mem_DP[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = m; j >= 0; j--)
			{
				if (j >= container[i])
				{
					mem_DP[j] = std::max(mem_DP[j], mem_DP[j - container[i]] + container[i]);
				}
			}
		}
		printf("%s\n", (mem_DP[m] == m ? "yes" : "no"));
	}
#ifdef DEBUG
	system("pause");
#endif // DEBUG
	return 0;
}
