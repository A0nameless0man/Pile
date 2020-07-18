#include <iostream>
#include <string>

int main(void)
{
    std::string s;
    int         n;
    // std::cin >> n;
    while(std::cin >> n)
    {
        for(int i = 0; i < n; ++i)
        {
            std::cin >> s;
            
            int sta = 0;
            int sum = 0;
            for(auto c: s)
            {
                if(c == 'a')
                {
                    ++sum;
                }
                else
                {
                    --sum;
                    if(sum < 0)
                    {
                        sta = 2;
                        break;
                    }
                    else if(sum > 0)
                    {
                        sta = 1;
                    }
                    else
                    {
                        sta = 0;
                    }
                }
            }
            switch(sta)
            {
                case 0:
                    std::cout << "Happy Fang" << std::endl;
                    break;
                case 1:
                    std::cout << "Sad Fang" << std::endl;
                    break;
                case 2:
                    std::cout << "Dead Fang" << std::endl;
                    break;
                default:
                    break;
            }
        }
    }
}