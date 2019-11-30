#include<iostream>
#include<map>
#include<string>

int main(void)
{
	int n;
	while(std::cin>>n)
	{
		int ans = 0;
		for(int i = 0 ;i<n;i++)
		{
			std::string buf;
			std::cin>>buf;
			switch(buf[0])
			{
				case 'T':
				ans+=4;
				break;
				case 'C':
				ans+=6;
				break;
				case 'O':
				ans+=8;
				break;
				case 'D':
				ans+=12;
				break;
				case 'I':
				ans+=20;
				break; 
			}
		}
		std::cout<<ans<<std::endl;
	}
}
