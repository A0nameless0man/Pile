#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char buffer[11000] = { 0 };
	while (scanf("%s",buffer)!=EOF)
	{
		int i = 0;
		while (buffer[i]=='*')
		{
			printf("*");
			i++;
		}
		while (buffer[i]!='\0')
		{
			if (buffer[i]!='*')
			{
				printf("%c", buffer[i]);

			}
			i++;
		}
		printf("\n");
	}
}