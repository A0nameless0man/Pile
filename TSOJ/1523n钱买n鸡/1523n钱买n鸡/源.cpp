#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
const int cock = 6;
const int hen = 10;
const int chick = 1;//全部乘以2以避免浮点误差
int main(void)
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		n *= 2;
		for (size_t i = 1; i*hen < n; i++)
		{
			for (size_t j = 1; j*cock < n-i*hen; j++)
			{
				if (n - i * hen - j * cock!=0&&i+j+ n - i * hen - j * cock==n/2)
				{
					printf("%d %d %d\n", i, j, n - i * hen - j * cock);
				}
			}
		}
	}
	return 0;
}
