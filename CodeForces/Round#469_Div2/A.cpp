#include<iostream>
#include<algorithm>
int main(void)
{
	int l,r,m;
	while(std::cin>>r>>l>>m)
	{
		
		int ans = 0;
		if(l+m<r)
		{
			ans = l+m;
		}
		else if(r+m<l)
		{
				ans = r+m;
		}else
		{
			ans = (l+m+r)/2;
		}
		std::cout<<2*ans<<std::endl;
	}
} 
