#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
/*
写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以走到左下方的点也可以到达右下方的点。
输入格式：
第一个行包含 R(1<= R<=1000) ,表示行的数目。

后面每行为这个数字金字塔特定行包含的整数。

所有的被供应的整数是非负的且不大于100。

输出格式：
单独的一行,包含那个可能得到的最大的和。
*/
const int MAX_N = 1007;
int map[MAX_N][MAX_N];
int CurrentMax[MAX_N][MAX_N];
int r;
int main(void)
{
	while (scanf("%d",&r)!=EOF)
	{
		for (size_t i = 0; i < r; i++)
		{
			for (size_t j = 0; j <= i; j++)
			{
				scanf("%d", &map[i][j]);
				CurrentMax[i][j] = 0;
				if (i!=0)
				{
					CurrentMax[i][j] = CurrentMax[i - 1][j];
				}
				if (j!=0)
				{
					if (CurrentMax[i-1][j-1]>CurrentMax[i][j])
					{
						CurrentMax[i][j] = CurrentMax[i-1][j - 1];
					}
				}
				CurrentMax[i][j] += map[i][j];
			}
		}
		int max = 0;
		for (size_t i = 0; i < r; i++)
		{
			if (CurrentMax[r-1][i]>max)
			{
				max = CurrentMax[r - 1][i];
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
