#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
/*
��һ��M*N��ħ�������У�
ÿ�������о���һ��������
�������߽���������У�
��������ϵ����ᱻ���Դ˸����е�����
һ�����Ӵ����Ͻ��ߵ����½ǣ�
ֻ�����һ������ж���
���ʴ������ߵ����½Ǻ�
ģ��mod��K����Ϊ����
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
