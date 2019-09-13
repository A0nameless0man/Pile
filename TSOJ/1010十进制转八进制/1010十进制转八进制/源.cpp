#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
//#include<ctype.h>
#include<math.h>
//#define _CRT_SECURE_NO_WARNINGS
const char ctoi[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int BUFFERSIZE = 512;
int strturn(char* input)
{
	int	inputlen = strlen(input);

	char temp[BUFFERSIZE];
	for (int i = 1; i <= inputlen; i++)
	{
		temp[i - 1] = input[inputlen - i];
	}
	temp[inputlen] = '\0';
	strcpy(input, temp);
	return inputlen;
}
void inttostr(int input, int decimal, char* output)
{
	char temp[BUFFERSIZE] = { 0 };
	for (size_t i = 0; pow(decimal, i) <= input; i++)
	{

		int a = (int)(input % (int)(pow(decimal, i + 1)) / pow(decimal, i));
		temp[i] = ctoi[a];
	}
	strturn(temp);
	strcpy(output, temp);
}
int	main(void)
{
	int a = 0;
	char output[BUFFERSIZE] = { 0 };
	scanf("%d", &a);
	while (scanf("%d",&a)!=EOF)
	{
		inttostr(a, 8, output);
		printf("%s\n", output);
	}
}