//i*m-i*(i+1)/2=i*(m-(i+1)/2)
//m^2-(m^2+m)/2 = (m*m-m)/2

//i ==m  stor =n
//n-1

#include<iostream>
typedef __int128 LL;
int main(void)
{
	long long nn,mm;
	while(std::cin>>nn>>mm)
	{
		LL n= nn,m=mm;
		{
			LL ans,stor;
			if(m>=n)
			{
				ans = n;
			}
			else
			{
				ans = m;
				stor = n-m;
				LL l = 1,r = n;
				while(l<r)
				{
					LL mid = (l+r)/2;
					//std::cout<<"mid:"<<mid<<std::endl;
					if(stor*2>(mid+1)*mid)
					{
						l = mid+1;
					}
					else
					{
						r = mid;
					}
				}
				ans += l;
			}	
			long long a = ans; 
			std::cout<<a<<std::endl;
		}
	}
	return 0;
}
