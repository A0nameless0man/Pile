#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
题目描述:
给定两个数的分子和分母，求两个分数的和。

输入描述：
多组输入，每组输入包含 4 个正整数 a, b, c, d (0 < a, b, c, d < 1000)，依次代表第一个数的分子，第一个数的分母，第二个数的分子，第二个数的分母

输出描述：
对于每组数据，输出的两个分数的和的小数形式，结果保留小数点后 4 位。
*/
/*
1017
题目描述:
给定两个数的分子和分母，求两个分数的和。

输入描述：
多组输入，每组输入包含 4 个正整数 a, b, c, d (0 < a, b, c, d < 1000)，依次代表第一个数的分子，第一个数的分母，第二个数的分子，第二个数的分母

输出描述：
对于每组数据，输出的两个分数的和的最简分数形式。（如果分子是分母的倍数，则输出形式为 n/1 ）
样例输入:
1 2 1 2

1 4 1 2

样例输出:
1/1

3/4
*/
//int min_common_multiple(int a,int b)

int max_common_divisor(int a, int b)
{
	while (a != 0 && b != 0)
	{
		a %= b;
		if (a == 0)
		{
			break;
		}
		b %= a;

	}
	return (a == 0 ? b : a);
}
int main(void)
{
	int a[2] = { 0,0 }, b[2] = { 0,0 }, c[2] = { 0,0 }, temp = 0;
	while (scanf("%d%d%d%d", a, a + 1, b, b + 1) != EOF)
	{
		c[0] = a[0] * b[1] + a[1] * b[0];
		c[1] = a[1] * b[1];
		temp = max_common_divisor(c[1], c[0]);
		c[0] /= temp;
		c[1] /= temp;
		//printf("%.4f\n", (float)c[0] / (float)c[1]);
		printf("%d/%d\n", c[0], c[1]);
	}
	return 0;
}