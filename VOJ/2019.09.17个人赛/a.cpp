#include<iostream>
#include<string>
#include<algorithm>
int main(void)
{
    std::string input;
    while(std::cin>>input)
    {
        char last = 'a';
        long long ans = 0;
        for(auto c: input)
        {
            if (c>last)
            {
                ans+=std::min(c-last,last+26-c);
            }else
            {
                ans+=std::min(last-c,c+26-last);
            }
            last =c;
        }
        std::cout<<ans<<std::endl;
    }
}