#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
template <typename T> void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}
char* strev(char* input)
{
	int	inputlen = strlen(input);

	char temp[30000];
	for (int i = 1; i <= inputlen; i++)
	{
		temp[i - 1] = input[inputlen - i];
	}
	temp[inputlen] = '\0';
	strcpy(input, temp);
	return input;
}
void output(char in[])
{
	bool miners = (in[0] == '-');
	strev(in + miners);
	if (miners)
	{
		putchar('-');
		in++;
	}
	while (*in == '0'&&*(in + 1) != '\0')
		in++;
	while (*in != '\0')
		putchar(*in);
	putchar('\n');
}
const int MAX_N = 10007;
int n, m, a, b, j, k;
char buffer[MAX_N];
int main(void)
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // DEBUG
	
	while (scanf("%s",buffer)!=EOF)
	{
		output(buffer);
	}
#ifdef DEBUG
	system("pause");
	system("pause");
#endif // DEBUG

	return 0;
}
