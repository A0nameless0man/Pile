#include<iostream>
#include<deque>
int main(void)
{
	int n;
	while(std::cin>>n)
	{
		std::deque<int> que;
		for(int i = 0;i<n;++i)
		{
			int buf;
			std::cin>>buf;
			que.push_back(buf);
		}
		int even = 0;
		int sum[2] = {0};
		while(!que.empty())
		{
			if(que.front()>que.back())
			{
				sum[even]+=que.front();
				que.pop_front();
			}
			else
			{
				sum[even]+=que.back();
				que.pop_back();
			}
			++even;
			even%=2;
		}
		std::cout<<sum[0]<<" "<<sum[1]<<std::endl;
	}
}
