#define	_CRT_SECURE_NO_WARNINGS
/*
题目内容
题目描述:
已知 2007 年 10 月 10 日，请求出 n 天后是几月几号

输入描述：
多组输入，每组输入为 1 行，为一个正整数 n (1 <= n <= 2000)

输出描述：
对于每组输入，输出格式为 yyyy-mm-dd，输出的值为 n 天后的日期

样例输入:
1

2

样例输出:
2007-10-11

2007-10-12
*/
#include<stdio.h>
int main(void)
{
	struct tm
	{
		int year;
		int mounth;
		int day;
		const int MOUNTHinYEAR = 12;
		bool isleap(void)
		{
			return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
		}
		int dayinmounth(void)
		{
			int def[] = { 0,31,-1,31,30,31,30,31,31,30,31,30,31 };
			int feb[] = { 28,29 };
			return mounth != 2 ? def[mounth] : feb[isleap() ? 1 : 0];
		}
		tm timeaddbymounth(unsigned int n)
		{
			if (n + mounth <= MOUNTHinYEAR)
			{
				mounth += n;
			}
			else
			{
				year++;
				timeaddbymounth(n - MOUNTHinYEAR);
			}
			return *this;
		}
		tm timeaddbyday(unsigned int n)
		{
			if (n + day <= dayinmounth())
			{
				day += n;
			}
			else
			{
				n -= dayinmounth();
				timeaddbymounth(1);
				timeaddbyday(n);
			}
			return *this;
		}
	}from;
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		from.year = 2007;
		from.mounth = 10;
		from.day = 10;
		from.timeaddbyday(n);
		printf("%d-", from.year);
		if (from.mounth < 10)
		{
			printf("0");
		}
		printf("%d-", from.mounth);
		if (from.day < 10)
		{
			printf("0");
		}
		printf("%d\n", from.day);
	}
	return 0;
}