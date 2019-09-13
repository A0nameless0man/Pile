#include<iostream>
using ULL = unsigned long long;
ULL x,y,a,b;
int main(void)
{
    while(std::cin>>x>>a>>y>>b)
    {
        if(x/a==y/b&&x%a*b==y%b*a)
        {
            std::cout<<'='<<std::endl;
        }
        else
        {
            if(x/a<y/b||x/a==y/b&&x%a*b<y%b*a)
            {
                std::cout<<'<'<<std::endl;
            }
            else
            {
                std::cout<<'>'<<std::endl;
            }
        }
    }
    return 0;
}