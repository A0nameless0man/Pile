#include<iostream>
#include<algorithm>
#include<string>
int main(void)
{
    std::string s;
    std::cin>>s;
    std::sort(s.begin(),s.end());
    if(*s.begin()==*s.rbegin())
    {
        std::cout<<"NO"<<std::endl;
    }
    else
    {
        std::cout<<"YES"<<std::endl;
        std::cout<<s<<std::endl;
    }
    return 0;
}