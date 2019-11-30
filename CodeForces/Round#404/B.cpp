#include<iostream>
#include<algorithm>
const int MAX_N = 200007;
int M[2][MAX_N],N[2][MAX_N];
int m,n;
int main(void)
{
	while(std::cin>>n)
	{
		for(int i = 0;i<n;i++)
		{
			std::cin>>N[0][i]>>N[1][i];	
		}
		std::cin>> m;
		for(int i = 0;i<m;i++)
		{
			std::cin>>M[0][i]>>M[1][i];
		}
		std::sort(N[0],N[0]+n);
		std::sort(N[1],N[1]+n);
		std::sort(M[0],M[0]+m);
		std::sort(M[1],M[1]+m);
		std::cout<<std::max(0,std::max(N[0][n-1]-M[1][0],M[0][m-1]-N[1][0]))<<std::endl;
	} 
}
