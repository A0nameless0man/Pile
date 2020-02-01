#include <algorithm>
#include <iostream>
#include <map>

int main(void)
{
    int t;
    while(std::cin >> t)
        for(int i = 0; i < t; ++i)
        {
            int n;
            std::cin >> n;
            std::vector<std::pair<int, int> > vec;
            for(int i = 0; i < n; ++i)
            {
                int x;
                int y;
                std::cin >> x >> y;
                vec.push_back(std::make_pair(x, y));
            }
            std::sort(vec.begin(), vec.end());
            // for(const auto &p: vec)
            // {
            //     std::cout << p.first << ":：" << p.second << std::endl;
            // }
            if([&]() -> bool {
                   int lasty = 0;
                   for(const auto &p: vec)
                   {
                       if(p.second < lasty)
                       {
                           return false;
                       }
                       lasty = p.second;
                   }
                   return true;
               }())
            {
                auto lastp = std::make_pair(0, 0);
                std::cout << "YES" << std::endl;
                for(const auto &p: vec)
                {
                    for(int i = 0; i < p.first - lastp.first; ++i)
                    {
                        std::cout << "R";
                    }
                    for(int i = 0; i < p.second - lastp.second; ++i)
                    {
                        std::cout << "U";
                    }
                    lastp = p;
                }
                std::cout << std::endl;
            }
            else
            {
                std::cout << "NO" << std::endl;
            }
        }
}