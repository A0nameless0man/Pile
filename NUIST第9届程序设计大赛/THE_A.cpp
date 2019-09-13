#include<stdio.h>
/*
A :竹鼠的命运
时间限制:  1000MS   空间限制:  32MB   提交数:  0   通过数:  0  
题目内容

题目描述

农华兄弟最近开始做直播，竹鼠们开始瑟瑟发抖，但它们除了吃和睡，其它什么都做不了。农华兄弟突发奇想，如果某只竹鼠最多一次连续吃东西的时间超过最多一次连续睡觉的时间，那么它就会被做成宽油竹鼠（宽油：使用很大量的油的烹饪方法）；如果次数相等则会被做成叫花竹鼠（叫花：用粘土把食材包裹起来，加以烧烤的烹饪方法）；如果其最多一次连续吃东西的时间少于最多一次连续睡觉的时间，它就会被做成烧烤竹鼠。现在请你帮农华兄弟决定竹鼠们的命运。
输入描述

题目包含多组测试数据。第一行包括一个正整数T，代表测试数据的组数（竹鼠的数量）。

接下来的T行，每行包含一个数字序列，代表一只竹鼠的行为。第一个数字n表示竹鼠吃和睡的总时间（1 <= n <= 100）。数字序列由1和2组成。1代表竹鼠吃了一段时间的东西，2代表竹鼠睡了一段时间的觉。每个数字表示的吃或睡的时间长度相等。
输出描述

对于每一组测试数据，输出一行字符序列。"kuanyou"表示竹鼠被做成了宽油竹鼠；"jiaohua"表示做成了叫花竹鼠；"bbq"表示做成了烧烤竹鼠。
样例输入

1

8 2 2 1 1 2 1 1 1
样例输出

kuanyou
样例解析

由于竹鼠最多一次连续吃东西的时间为3("1 1 1")，最多一次连续睡觉的时间为2("2 2")，所以它会被做成宽油竹鼠。
*/
int main(void)
{
	int behv[105]={0};
	int max_eat,max_sleep,current_stu,current_l,i,n;
	scanf("%*d");
	while(scanf("%d", &n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",behv+i);
		}
		behv[n]=0;
		max_eat=max_sleep=current_l=i=0;
		current_stu=behv[0];
		
		while(behv[i]!=0)
		{
			if(behv[i]==current_stu)
			{
				current_l++;
			}
			else
			{
				if(current_stu==1)
				{
					if(current_l>max_eat)
					{
						max_eat=current_l;
					}
				}
				else
				{
					if(current_l>max_sleep)
					{
						max_sleep=current_l;
					}
				}
				current_l=1;
				current_stu = behv[i];
			}
			i++;
		}
		if(current_stu==1)
		{
			if(current_l>max_eat)
			{
				max_eat=current_l;
			}
		}
		else
		{
			if(current_l>max_sleep)
			{
				max_sleep=current_l;
			}
		}
		if(max_sleep==max_eat)
		{
			printf("jiaohua\n");
		}
		else
		{
			if(max_sleep>max_eat)
			{
				printf("bbq\n");
			}
			else
			{
				printf("kuanyou\n");
			}
		}
	}
	return 0;
}
