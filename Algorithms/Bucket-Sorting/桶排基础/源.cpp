#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int MAX_NUM = 100 + 7;//数字最大为100，加7以防止一些错误；
int barrel[MAX_NUM];//这就是桶，每个桶有编号，存储对应数字出现的次数
int buffer;//临时存放输入数据
int n;//数据的个数
int max_time;//出现最多的数的次数
int max_n;//出现最多的数
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < MAX_NUM; i++)
	{
		barrel[i] = 0;//清空桶
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &buffer);
		barrel[buffer]++;//读一个数，扔到对应的桶里面
	}
	max_time = 0;
	for (int i = 0; i < MAX_NUM; i++)
	{
		if (barrel[i]>max_time)
		{
			max_time = barrel[i];
			max_n = i;//找到最满的桶
		}
	}
	printf("%d %d", max_n, max_time);
	return 0;
}