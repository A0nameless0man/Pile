#include<iostream>
#include<queue>
int main(void)
{
	int m,n;
	while(std::cin>>n>>m)
	{
		std::queue<int> que[2];
		for(int i = 0;i<n;i++)
		{
			int buf;
			std::cin>>buf;
			que[0].push(buf);
		} 
		for(int i = 0;i<m;i++)
		{
			int buf;
			std::cin>>buf;
			que[1].push(buf);
		} 
		int sum[2]={0,0};
		int ans = 0;
		while(!que[0].empty()||!que[1].empty())
		{
			if(sum[0]<sum[1])
			{
				sum[0]+=que[0].front();
				que[0].pop();
			}
			else
			{
				sum[1]+=que[1].front();
				que[1].pop();
			}
//			std::cout<<sum[0]<<" "<<sum[1]<<"@"<<std::endl;
			if(sum[0]==sum[1])
			{
				sum[0]=sum[1]=0;
				ans++;
			}
		}
		std::cout<<ans<<std::endl;
	}
}
