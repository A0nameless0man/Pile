#include <iostream>
#include <string>
#include <vector>
using ULL = unsigned long long;
int main(void)
{
    std::string str;
    while(std::cin >> str)
    {
        unsigned long long ans           = 0;
        ULL                counter       = 0;
        ULL                restcounter[] = { 1, 0, 0 };
        std::vector<ULL>   rest, restcount[3];
        for(auto c: str)
        {
            if(c == '0')
            {
                counter++;
            }
            else
            {
                if(counter)
                {
                    ans += counter * 2 - 1;
                    counter = 0;
                }
            }
        }
        if(counter)
        {
            ans += counter * 2 - 1;
            counter = 0;
        }
        for(auto c: str)
        {
            counter += c - '0';
            counter %= 3;
            rest.push_back(counter);
            for(size_t i = 0; i < 3; i++)
            {
                restcount[i].push_back((i == counter) ? ++restcounter[i] : restcounter[i]);
                //对于每一个可能的余数,检查当前余数是否为自己,如果是,则余数计数增加如果否,则不增加,将结果塞入余数统计数组的末尾
            }
        }
        // std::cout << ans << std::endl;
        for(size_t i = 0; i < str.length() - 2; i++)
        {
            if(str[i + 1] == '0' && str[i + 2] == '0')
            {
                ans += restcount[rest[i]][i] - 1;

                // DEBUG
                // std::cout << restcount[rest[i]][i] - 1 << std::endl;
                // std::cout << i << std::endl;
            }
        }
        std::cout << ans << std::endl;

        // DEBUG
        // for (size_t i = 0; i < 3; i++)
        //{
        //	for (auto u : restcount[i])
        //	{
        //		std::cout << u << " ";
        //	}
        //	std::cout << std::endl;
        //}
        // for (auto u : rest)
        //{
        //	std::cout << u << " ";
        //}
        // std::cout << std::endl;
    }
}