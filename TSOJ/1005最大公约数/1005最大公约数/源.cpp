#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main(void)
//{
//	int d = 0, a = 0, b = 0;
//	scanf("%d", &d);
//	for (size_t i = 0; i < d; i++)
//	{
//		scanf("%d%d", &a, &b);
//		while (a!=0&&b!=0)
//		{
//			a %= b;
//			if (a==0)
//			{
//				break;
//			}
//			b %= a;
//
//		}
//
//		printf("%d\n", a == 0 ? b:a);
//
//	}
//}
//修改以适应三个数字的情况
int main(void)
{
	int d = 0, a = 0, b = 0,c = 0;
	scanf("%d", &d);
	for (size_t i = 0; i < d; i++)
	{
		scanf("%d%d%d", &a, &b,&c);
		while (a != 0 && b != 0)
		{
			a %= b;
			if (a == 0)
			{
				break;
			}
			b %= a;

		}
		b = (a == 0 ? b : a);
		while (c != 0 && b != 0)
		{
			c %= b;
			if (c == 0)
			{
				break;
			}
			b %= c;

		}

		printf("%d\n", c == 0 ? b : c);

	}
}