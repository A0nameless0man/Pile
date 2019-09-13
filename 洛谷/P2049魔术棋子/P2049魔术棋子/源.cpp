#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
/*
在一个M*N的魔术棋盘中，
每个格子中均有一个整数，
当棋子走进这个格子中，
则此棋子上的数会被乘以此格子中的数。
一个棋子从左上角走到右下角，
只能向右或向下行动，
请问此棋子走到右下角后，
模（mod）K可以为几？
*/
const int MAX_N = 107;
bool ModCanBe[MAX_N][MAX_N][MAX_N];
int map[MAX_N][MAX_N] = { 0 };
int m, n, k;
int main(void)
{
	while (scanf("%d%d%d", &m, &n, &k) != EOF)
	{
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
				map[i][j] %= k;
				for (size_t mod = 0; mod < k; mod++)
				{
					ModCanBe[i][j][mod] = false;
				}
				if (i != 0)
				{
					for (size_t Chess = 0; Chess < k; Chess++)
					{
						if (ModCanBe[i - 1][j][Chess])
						{
							ModCanBe[i][j][Chess*map[i][j] % k] = true;
						}
					}
				}
				if (j != 0)
				{
					for (size_t Chess = 0; Chess < k; Chess++)
					{
						if (ModCanBe[i][j - 1][Chess])
						{
							ModCanBe[i][j][Chess*map[i][j] % k] = true;
						}
					}
				}
				if (i==0&&j==0)
				{
					ModCanBe[i][j][map[i][j] % k] = true;
				}
			}
		}
		int AnsCont = 0;
		for (size_t i = 0; i < k; i++)
		{
			if (ModCanBe[m-1][n-1][i])
			{
				AnsCont++;
			}
		}
		printf("%d\n", AnsCont);
		for (size_t i = 0; i < k; i++)
		{
			if (ModCanBe[m-1][n-1][i])
			{
				printf("%d", i);
				if (i < k - 1)
				{
					putchar(' ');
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
