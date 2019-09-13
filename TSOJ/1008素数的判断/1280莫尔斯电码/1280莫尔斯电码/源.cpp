#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
char alpha[36][5] = { ".-",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--.."
};
char num[10][10] = { ".----",
"..---",
"...--",
"....-",
".....",
"-....",
"--...",
"---..",
"----.",
"-----",
};
char buffer[107];
template <typename T> void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}
const int MAX_N = 10007;
int n, m, a, b, j, k;
//int main(void)
//{
//#ifdef DEBUG
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//#endif // DEBUG
//	
//	while (scanf("%*s%s",buffer)!=EOF)
//	{
//		printf("\"%s\",\n", bufffer);
//	}
//	return 0;
//}
int main(void)
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // 
	while (scanf("%s",buffer)!=EOF)
	{
		int len = strlen(buffer);
		for (int i = 0; i < len; i++)
		{
			if (isalpha(buffer[i]))
			{
				printf("%s", alpha[tolower(buffer[i]) - 'a']);
			}
			else
			{
				printf("%s", num[buffer[i] - '0']);
			}
			if (i<len-1)
			{
				printf("===");
			}
			else
			{
				printf("\n");
			}
		}
	}
}
