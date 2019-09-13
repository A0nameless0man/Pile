#include<stdio.h>
/*
G :更厉害的数列（2）
时间限制:  1000MS   空间限制:  32MB   提交数:  21   通过数:  14  
题目内容

题目描述

请参照更厉害的数列（1）中介绍的方法，设数列f(n) = f(n-1) + f(n-2) + 1，f(1)=f(2)=1，根据给定的n，求f(n)。
输入描述

题目包含多组测试数据。第一行包括一个正整数T，代表测试数据的组数。

接下来的输入，每组输入包含一行，每一行有一个正整数n（0 < n <= 1,000,000,000）。
输出描述

对于每组测试数据，输出f(n)的最后四位数。如果f(n)的最后四位数都是0，输出0；否则，忽略所有先导0。（即：输出f(n)对10000取模）
样例输入

3

9

999999999

1000000000
样例输出

67

1251

3749
*/
class M
{
	
	public:
		M(void)
		{
			for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			d[i][j]=0;
		}
		int d[3][3];
		M operator*(M b)
		{
			M r;
			for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			r.d[i][j]=(this->d[i][0]*b.d[0][j]+this->d[i][1]*b.d[1][j]+this->d[i][2]*b.d[2][j])%10000;
			return r;
		}
};
int main(void)
{
	long n;
	scanf("%*d");
	while(scanf("%ld",&n)!=EOF)
	{
		switch (n)
		{
			case 1:
				printf("1\n");
				break;
			case 2:
				printf("1\n");
				break;
			default:
				n-=2;
				M x;
				x.d[0][0]=1;
				x.d[0][1]=1;
				x.d[0][2]=1;
				x.d[1][0]=1;
				x.d[2][2]=1;
				M res;
				res.d[0][0]=1;
				res.d[1][1]=1;
				res.d[2][2]=1;
				res.d[1][0]=0;
				while(n)
				{
    				if (n & 1) 
					{		 	
						res = res*x;
				    }
   				 	x = x*x;
    				n >>= 1;
				}
				printf("%d\n",(res.d[0][0]+res.d[0][1]+res.d[0][2])%10000);	
		}
	
	}

	return 0;
}
