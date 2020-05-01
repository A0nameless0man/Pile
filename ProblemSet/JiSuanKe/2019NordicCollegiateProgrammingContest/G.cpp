#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        std::vector<int> vec;
        for(int i = 0; i < n; ++i)
        {
            int buf;
            std::cin >> buf;
            vec.push_back(buf);
        }
        int best = 10000, cur = 0;
        for(int i = 0; i + 2 < n; ++i)
        {
            int now = std::max(vec[i], vec[i + 2]);
            if(now < best)
            {
                best = now;
                cur  = i;
            }
        }
        std::cout << cur + 1 << " " << best << std::endl;
    }
}