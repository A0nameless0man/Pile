#include <array>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
std::string ali     = "Alibaba";
std::string tencent = "Tencent";
std::string Baidu   = "Baidu";
std::string NUIST   = "NUIST";
int         main(void)
{
    int table[3];
    while(std::cin>>table[0]>>table[1]>>table[2])
    {
        if(table[0] > table[1] && table[0] > table[2])
        {
            std::cout << ali << std::endl;
        }
        else if(table[1] > table[2] && table[1] > table[0])
        {
            std::cout << tencent << std::endl;
        }
        else if(table[2] > table[0] && table[2] > table[1])
        {
            std::cout << Baidu << std::endl;
        }
        else
        {
            std::cout << NUIST << std::endl;
        }
    }
}