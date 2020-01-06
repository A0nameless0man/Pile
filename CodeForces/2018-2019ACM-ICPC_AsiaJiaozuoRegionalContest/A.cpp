#include <iostream>
#include <string>
#include <vector>
const std::vector<std::string> vec = { "Typically Otaku",
                                       "Eye-opener",
                                       "Young Traveller",
                                       "Excellent Traveller",
                                       "Contemporary Xu Xiake" };

int main(void)
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int ans = 0;
        for(int i = 0; i < 4; i++)
        {
            int buf;
            std::cin >> buf;
            if(buf)
            {
                ans++;
            }
        }
        std::cout << vec[ans] << std::endl;
    }
}