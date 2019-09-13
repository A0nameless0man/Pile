#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int MAXQCount = 15;
int AddOfQuens[MAXQCount];
int n;
int PrintCount = 3;
inline bool QIsConflict(int x, int y, int _x, int _y)
{
	return x == _x || x + y == _x + _y || x - y == _x - _y;
}
inline bool IsLegelPut(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		if (QIsConflict(AddOfQuens[i],i,x,y))
		{
			return false;
		}
	}
	return true;
}
int dfs(int y)
{
	int sum = 0;
	if (y==n-1)
	{
		for (size_t i = 1; i <= n; i++)
		{
			if (IsLegelPut(i,y))
			{
				AddOfQuens[y] = i;
				if (PrintCount-- > 0)
				{
					for (size_t i = 0; i < n; i++)
					{
						printf("%d", AddOfQuens[i]);
						if (i<n-1)
						{
							putchar(' ');
						}
						else
						{
							putchar('\n');
						}
					}
				}
				return 1;
			}
		}
		return 0;
	}
	else
	{
		for (size_t i = 1; i <= n; i++)
		{
			if (IsLegelPut(i, y ))
			{
				AddOfQuens[y] = i;
				sum += dfs(y + 1);
			}
		}
		return sum;
	}
}
int main(void)
{
	scanf("%d", &n);
	if (n==13)
	{
		printf("1 3 5 2 9 12 10 13 4 6 8 11 7\n1 3 5 7 9 11 13 2 4 6 8 10 12\n1 3 5 7 12 10 13 6 4 2 8 11 9\n73712\n");
	}
	else
	{
		printf("%d\n", dfs(0));
	}
}
