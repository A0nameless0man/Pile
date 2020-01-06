#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/*
        A +z
        |
    Lshade |   Rshade
        |     +y
        +---------->
       /
      /
     /
    |/_ +x
*/
struct Pos
{
    int z, x, y;
};
int main(void)
{
    int z, x, y;
    std::cin >> z >> x >> y;
    std::vector<std::string> l, r;
    for(int i = 0; i < z; i++)
    {
        std::string buf;
        std::cin >> buf;
        l.push_back(buf);
    }
    for(int i = 0; i < z; i++)
    {
        std::string buf;
        std::cin >> buf;
        r.push_back(buf);
    }
    {
        int              maxCount = 0;
        std::vector<Pos> maxPos;
        for(int i = 0; i < z; i++)
        {
            std::vector<int> lShade, rShade;
            for(int j = 0; j < l[i].size(); j++)
            {
                if(l[i][j] == '1')
                {
                    lShade.push_back(j);
                }
            }
            for(int j = 0; j < r[i].size(); j++)
            {
                if(r[i][j] == '1')
                {
                    rShade.push_back(j);
                }
            }
            if((lShade.size() == 0) ^ (rShade.size() == 0))
            {
                std::cout << -1 << std::endl;
                return 0;
            }
            maxCount += lShade.size() * rShade.size();  // std::max(lShade.size(), rShade.size());
            for(auto x: lShade)
            {
                for(auto y: rShade)
                {
                    maxPos.push_back({ i, x, y });
                }
            }
        }
        std::cout << maxCount << "\n";
        for(auto p: maxPos)
        {
            std::cout << p.z << " " << p.x << " " << p.y << "\n";
        }
        std::cout << std::flush;
    }
    {
        int              minCount = 0;
        std::vector<Pos> minPos;
        for(int i = 0; i < z; i++)
        {
            std::vector<int> lShade, rShade;
            for(int j = 0; j < l[i].size(); j++)
            {
                if(l[i][j] == '1')
                {
                    lShade.push_back(j);
                }
            }
            for(int j = 0; j < r[i].size(); j++)
            {
                if(r[i][j] == '1')
                {
                    rShade.push_back(j);
                }
            }
            minCount += std::max(lShade.size(), rShade.size());
            if(rShade.size() == lShade.size())
            {
                for(int j = 0; j < lShade.size(); j++)
                {
                    minPos.push_back({ i, lShade[j], rShade[j] });
                }
            }
            else if((lShade.size() < rShade.size()))
            {
                int dif = rShade.size() - lShade.size();
                for(int j = 0; j < dif; j++)
                {
                    minPos.push_back({ i, lShade[0], rShade[j] });
                }
                for(int j = dif; j < rShade.size(); j++)
                {
                    minPos.push_back({ i, lShade[j - dif], rShade[j] });
                }
            }
            else if(lShade.size() > rShade.size())
            {
                int dif = lShade.size() - rShade.size();
                for(int j = 0; j < dif; j++)
                {
                    minPos.push_back({ i, lShade[j], rShade[0] });
                }
                for(int j = dif; j < lShade.size(); j++)
                {
                    minPos.push_back({ i, lShade[j], rShade[j - dif] });
                }
            }
        }
        std::cout << minCount << "\n";
        for(auto p: minPos)
        {
            std::cout << p.z << " " << p.x << " " << p.y << "\n";
        }
        std::cout << std::flush;
    }
    return 0;
}