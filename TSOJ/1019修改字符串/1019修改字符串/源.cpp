#include<stdio.h>
#include<ctype.h>
#include<string.h>
int strcln(char* input)
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (isalnum(input[i]))
		{
			input[i] = tolower(input[i]);
		}
		else
		{
			input[i] = '\0';
			break;
		}
	}
	return strlen(input);
}
int main(void)
{
	char buffer[501] = { 0 };
	while (scanf("%s",buffer)!=EOF)
	{
		strcln(buffer);
		printf("%s\n", buffer);
	}
	return 0;
}