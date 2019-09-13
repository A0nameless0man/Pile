#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
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

int main(void)
{
	char buffer[20000] = { 0 }, bufer[20000] = { 0 };
	while (gets_s(buffer)!=NULL)
	{
		strcpy(bufer, buffer);
		strev(bufer);
		//if (strcmp(bufer,buffer)==0&&strlen(buffer)!=1)
		//{
		//	printf("YES\n");
		//}
		//else
		//{
		//	printf("NO\n");
		//}
		printf("%s", bufer);
	}
}
//#include<string.h>
//int main()
//{
//	int m, n, t, l = 1, i, j;
//	char a[100005], r;
//	while (scanf("%s", a) != EOF)
//	{
//		m = 0;
//		l = strlen(a);//获取数组长度 
//		t = l / 2;//标记中间位置 
//		for (i = 0; i <= t - 1; i++)
//		{
//			if (a[i] == a[l - 1 - i])//比较，i从左边开始，l-1-i是数组右边和i相对应的位置 
//				m++;//每有一个相同的的，m+1； 
//		}
//		if (m == t)//如果m和中间数大小相同，说明是回文字符串 
//			printf("YES\n");
//		else
//			printf("NO\n");
//
//	}
//}//陈家鹏的代码