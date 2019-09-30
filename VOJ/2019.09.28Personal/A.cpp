#include<iostream>
#include<string>
#include<algorithm>
int main(void)
{
	int t;
	std::cin>>t;
	while(t--)
	{
		int rec[2][26]={0};
		std::string str;
		std::cin>>str;
		int ans = str.length();
		for(int i =0;i<str.length();i++)
		{
			(rec[i&1][str[i]-'a'])++;
		}
		int best[2]={0};
		for(int i =0;i<26;i++)
		{
			for(int j=0;j<2;j++)
				best[j]=std::max(best[j],rec[j][i]);
		}
		ans -=best[0]+best[1];
		std::cout<<ans<<std::endl;
	}
	return 0;
}