#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int MAX_N = 200007;
bool sa[MAX_N][2];
int a[2];
int n, p, k, qGet, q;//Ì°ÐÄ²»ÐÐ
void look(int who, int from)
{
	int r = 0;
	for (size_t i = 0; i < k; i++)
	{
		if (sa[i + from][who])
		{
			sa[i + from][0] = sa[i + from][1] = false;;
			r++;
		}
	}
	qGet += r;
}
int think(int who, int from)
{
	int r = 0;
	for (size_t i = 0; i < k; i++)
	{
		if (sa[i + from][who])
		{
			r++;
		}
	}
	return r;
}
int main(void)
{
	while (scanf("%d%d%d", &n, &p, &k) != EOF)
	{
		int pleft = p;
		qGet = 0;
		for (size_t i = 0; i < MAX_N; i++)
		{
			sa[i][0] = sa[i][1] = false;
		}
		for (size_t i = 0; i < 2; i++)
		{
			scanf("%d", &a[i]);
			for (size_t j = 0; j < a[i]; j++)
			{
				scanf("%d", &q);
				sa[q][i] = true;
			}
		}
		int max = 0, max_who, max_from, _m;
		do
		{
			max = 0;
			for (size_t i = 0; i < 2; i++)
			{
				for (size_t j = 1; j <= n - k + 1; j++)
				{
					if ((_m = think(i, j)) > max)
					{
						max_who = i;
						max_from = j;
						max = _m;
					}
				}
			}
			pleft--;
			look(max_who, max_from);
		} while (max != 0 && ((pleft) > 0));
		printf("%d\n", qGet);
		return 0;
	}
	return 0;
}