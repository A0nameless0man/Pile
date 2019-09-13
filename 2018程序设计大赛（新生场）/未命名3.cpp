#include<stdio.h>
#include<string.h>
int main(void)
{
	int t;
 long long int a,b,round;
 bool no_loser;
	scanf("%d",&t);
	for(int i = 0;i<t;i++)
	{
		scanf(" %lld%lld",&a,&b);
		no_loser = true;
		round = 1;
		while(no_loser)
		{
			if(round%2==1)
			{
				a -= round;
		//		printf("a:%d\n",a);
				if(a<0)
				{
					printf("A\n");
					break;
				}
			}
			else
			{
				b -= round;
		//		printf("b:%d\n",b);
				if(b<0)
				{
					printf("B\n");
					break;
				}
			}
			round++;
			
		}
	}
}
