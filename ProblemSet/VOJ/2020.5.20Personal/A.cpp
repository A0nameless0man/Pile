#include <algorithm>
#include <iostream>
#include <string>

int main(void)
{
    int    n;
    std::string s;
    while(std::cin >> n >> s)
    {
        int min = 10;
        int sum = 0;
        for(const auto &c: s)
        {
            if(c == '(')
            {
                ++sum;
            }
            else if(c == ')')
            {
                --sum;
            }
            min = std::min(min, sum);
        }
        if(sum!=0||min<-1)
        {
            std::cout << "No\n";
        }else
        {
            std::cout << "Yes\n";
        }
    }
}