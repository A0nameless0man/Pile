#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
题目描述:
给定一串数，寻找其中最大的两个数

输入描述：
输入的第一行为 n (0 < n < 1000)，接下来的 n 行每行一个正整数 a (0 < n < 1000)

输出描述：
输出第一个为该组数最大的数，第二个为第二大的数。
*/
int* findmax(int* input, size_t inputcount)
{
	int *max = input;
	for (size_t i = 0; i < inputcount; i++)
	{
		max = *input > *max ? input : max;
		input++;
	}
	return max;
}
int main(void)
{
	int inputcount = 0;
	int *input = NULL;
while(EOF!=scanf("%d", &inputcount))
	{
	input = (int*)malloc(inputcount * sizeof(int));
	for (size_t i = 0; i < inputcount; i++)
	{
		scanf("%d", input + i);
	}
	int pre = 0;
	for (size_t i = 0; i < 2; i++)
	{
		if (0 == *(findmax(input, inputcount)))continue;
		if (pre == *(findmax(input, inputcount)))
		{
			i--;
			*(findmax(input, inputcount)) = 0;
			continue;
		}

		printf("%d", pre = *(findmax(input, inputcount)));
		*(findmax(input, inputcount)) = 0;
		if (i<1)
		{
			printf(" ");
		}
	}

	printf("\n");
	free(input);
}
	return 0;
}