#include<stdio.h>
#include<string.h>
int input[100000];
int record[100000];
int t,m,n,count,l,r;
bool exist(int check)
{
	for(int i = 0;i<count;i++)
	{
		if(check==record[i])
		{
			return true;
		}
	}
	return false;	
}
int main(void)
{

	scanf("%d",&t);
	for(int i = 0;i<t;i++)
	{
		scanf("%d%d",&n,&m);
		for(int i = 0;i<n;i++)
		{//input
			//scanf("%d",&input[i]);
			input[i]=i;
		}
		for(int i = 0;i<m;i++)
		{
			//reffer
			scanf("%d%d",&l,&r);
			count = 0;
			for(int i =0;i<l;i++)
			{
				if(!exist(input[i]))
				{
					record[count]=input[i];
					count++;
				}
			}
			for(int i =r-1;i<n;i++)
			{
				if(!exist(input[i]))
				{
					record[count]=input[i];
					count++;
				}
			}
			printf("%d\n",count);
		}	
	}
}
