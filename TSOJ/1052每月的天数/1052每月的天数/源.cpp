#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct tm
{
	int year;
	int mounth;
	int day;
	const int MOUNTHinYEAR = 12;
	bool isleap(void)
	{
		return year % 4 == 0 && year%100!=0|| (year % 400 == 0);
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
};
int main(void)
{
	tm a;
	while (scanf("%d%d",&a.year,&a.mounth)!=EOF)
	{
		printf("%d\n", a.dayinmounth());
	}
}