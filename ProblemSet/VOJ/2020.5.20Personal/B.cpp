#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main(void)
{
    int n, d, e;
    while(std::cin >> n >> d >> e)
    {
        e *= 5;
        int base = std::lcm(d, e);
        base     = std::min(n, n % base + base);
        std::vector<bool> vec(base + 1, false);
        vec[base] = true;
        for(int i = base; i--;)
        {
            if(((i + e <= base) && vec[i + e]) || ((i + d <= base) && vec[i + d]))
            {
                vec[i] = true;
                // std::cerr << "good" << i << std::endl;
            }
            // else
                // std::cerr << "bad" << i << std::endl;
        }
        std::cout << std::distance(vec.begin(), std::find(vec.begin(), vec.end(), true))
                  << std::endl;
    }
}