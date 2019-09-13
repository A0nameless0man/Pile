#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void gengrate(int* output, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			*(output + i * n + j) = 0;
		}
	}
	//初始化
	int i = 0 , j = 0, heading = 0,element = 0;
	//0=right
	//1=down
	//2=left
	//3=up
	for (size_t a = 0; a < n*n; a++)
	{
		switch (heading)
		{
		case 0:
			if (i + j == n - 1)
			{
				heading = 1;
			}
			break;
		case 1:
			if (i == j)
			{
				heading = 2;
			}
			break;
		case 2:
			if (i + j == n - 1)
			{
				heading = 3;
			}
			break;
		case 3:
			if (i - j == 1)
			{
				heading = 0;

			}
			break;
		default:
			break;
		}
		if (*(output+i*n+j)==0)
		{
			*(output + i * n + j) = ++element;
		}
		else
		{
			return;
		}
		switch (heading)
		{
		case 0:j++; break;
		case 1:i++; break;
		case 2:j--; break;
		case 3:i--; break;
		default:
			break;
		}
	}
}
int main(void)
{
	int   k = 0;
	int *buffer = NULL;
	while (scanf("%d", &k) != EOF)
	{
		buffer = (int*)malloc(k*k * sizeof(int));
		gengrate(buffer, k);
		for (size_t i = 0; i < k; i++)
		{
			for (size_t j = 0; j < k; j++)
			{
				printf("%d", *(buffer + i * k + j));
				if (j<k-1)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		free(buffer);
	}
}