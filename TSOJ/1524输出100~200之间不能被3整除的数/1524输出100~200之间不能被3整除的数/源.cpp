#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int j = 0;
	for (size_t i = 100; i <= 200;i++)
	{
		if (i%3!=0)
		{
			printf("%6d", i);
			j++;
			if (j % 6 == 0)
			{
				printf("\n");
			}
		}

	}
	printf("\n");
	return 0;
}