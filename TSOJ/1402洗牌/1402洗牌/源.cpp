#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
int cards[60];
void cut_cards()
{
	int card[2][30];
	for (size_t i = 1; i < 54/2+1; i++)
	{
		card[1][i-1] = cards[i];
	}
	for (size_t i = 28; i < 55; i++)
	{
		card[0][i-27] = cards[i];
	}
	for (size_t i = 1; i < 55; i++)
	{
		cards[i] = card[i % 2][i / 2];
	}
}
int main(void)
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i = 1; i < 55; i++)
		{
			cards[i] = i;
		}
		for (int i = 0; i < n; i++)
		{
			cut_cards();
		}
		for (int i = 1; i < 55; i++)
		{
			printf("%d", cards[i]);
			if (i<54)
			{
				putchar(' ');
			}
			else
			{
				putchar('\n');
			}
		}
	}
	return 0;
}
