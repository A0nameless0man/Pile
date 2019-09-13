#define _CRT_SECCURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int x, y;
	while (scanf("%d%d",&x,&y)!=EOF)
	{
		if (x==y)
		{
			printf("x==y");
		}
		else
		{
			if (x>y)
			{
				printf("x>y");
			}
			else
			{
				printf("x<y");
			}
		}
		printf("\n");
	}
	return 0;
}