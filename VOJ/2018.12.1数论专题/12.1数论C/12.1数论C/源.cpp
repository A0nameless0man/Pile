#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//要求，找出所有小于n的数中最大因数为d的数的个数，o（n)算法
//这种数一定是d的倍数，结果必然小于n/d,这样子需要查找n/d个数
//检查一个数k，需要检查d+1到sqrt（k）之间的值，
//这个算法在d比较大时有效
//假设d的最小因数为m，k=l*d，l应当小于等于m，或者为素数；
//需要找到10^9以内的素数表。
//结论：先写个会打素数表的程序
int main(void)
{
	int T, n, d;
	for (int i = 0; i < T; i++)
	{
		scanf("%d%d", n, d);
	}
}