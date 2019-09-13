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
bool map[MAX_N][MAX_N];
char out[MAX_N][MAX_N];
bool isBomb(int x, int y)
{
	if (x < 0 || y < 0 || x >= m || y >= n || !map[y][x])
	{
		return false;
	}
	else
	{
		return true;
	}
}
int direction[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
int main(void)
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // DEBUG
	
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char buffer;
				if ((buffer=getchar()) == '?')
				{
					map[i][j] = false;
				}
				else
				{
					map[i][j] = true;
				}
			}
			getchar();
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j])
				{
					out[i][j] = '*';
				}
				else
				{
					int n = 0;
					for (int k = 0; k < 8; k++)
					{
						//int n = 0;
						n += isBomb(j + direction[k][0], i + direction[k][1]);
					}
					out[i][j] = n + '0';
				}
				putchar(out[i][j]);
			}
			putchar('\n');
		}
	}
#ifdef DEBUG
	system("pause");
	system("pause");
#endif // DEBUG

	return 0;
}
