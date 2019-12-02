//Ç°×ººÍ+ST±í
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAX_N = 1000007;
int ST[MAX_N][32];
int sum[MAX_N];
char input[MAX_N];
int main(void)
{
	while(scanf("%s",input)!=EOF)
	{
		int len = strlen(input);
		int n = len+1;
		int prefix = 0;
		sum[0]=0;
		for(int i =0;i<len;++i)
		{
			if(input[i]=='(')
			{
				prefix+=1;
			}
			else
			{
				prefix-=1;
			}
			sum[i+1]=prefix;
		}
		for(int  = 0;i<n;i++)
		{
			ST[i][0]=sum[i];
		}
		for(int j=1,k = 1;k<n;++j,k<<=1)
		{
			int i;
			for(i = 0;i+k<n;++i)
			{
				ST[i][j]=std::min(ST[i][j-1],ST[i+k][j-1]);
			}
			for(;i<n;i++)
			{
				ST[i][j]=ST[i][j-1];
			}
		}
	}
}
