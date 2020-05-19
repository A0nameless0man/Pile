#include <iostream>
#include <set>
#include <unordered_map>

int main(void)
{
    int                                    n;
    std::unordered_map<int, int>           map;
    std::unordered_map<int, std::set<int>> setmap;
    while(std::cin >> n)
    {
        ++map[n];
    }
    for(int i = 0; i < 256; ++i)
    {
        if(map[i])
        {
            setmap[map[i]].insert(i);
        }
    }

    for(int i = 0; i < 256; ++i)
    {
        if(map[i])
        {
            std::cout << i << " appear " << map[i] << " times same as ";
            for(auto j: setmap[map[i]])
            {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}