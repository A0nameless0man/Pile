#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
char buf[200007];
std::vector<int > vecs[200000];
int main(void)
{
	while(scanf("%s",buf)!=EOF)
	{
		int len = strlen(buf);
		int cnt=0;
		std::queue<int> end[2];
		bool able = true;
		for(int i = 0;i<len;i++)
		{
			if(buf[i]=='0')
			{
				int v;
				if(end[1].empty())
				{
					vecs[cnt].clear();
					v =cnt;
					cnt++;
				}
				else
				{
					v = end[1].front();
					end[1].pop();
				}
				vecs[v].push_back(i);
				end[0].push(v);
			}
			else
			{
				int v;
				if(end[0].empty())
				{
					able = false;
					break;
				}
				else
				{
					v=end[0].front();
					end[0].pop();
				}
				vecs[v].push_back(i);
				end[1].push(v);
			}
		}
		for(int i =0;i<cnt;i++)
		{
			if(vecs[i].size()%2==0)
			{
				able = false;
				break;
			}
		}
		if(able)
		{
			std::cout<<cnt<<std::endl;
			for(int j = 0;j<cnt;j++)
			{
				std::cout<<vecs[j].size()<<" ";
				for(int i = 0;i<vecs[j].size();i++)
				{
					std::cout<<vecs[j][i]+1;
					if(i!=vecs[j].size()-1)
					{
						std::cout<<" ";
					}
					else
					{
						std::cout<<"\n";
					}
				}
			}
		}
		else
		{
			std::cout<<-1<<std::endl;
		}
	}
}
