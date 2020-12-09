#include <iostream>
#include <string>

int main(void)
{
    std::string s;
    int         k;
    while(std::cin >> s >> k)
    {
        for(size_t i = 0; i < s.length(); ++i)
        {
            size_t maxPos = i;
            char   maxVal = 0;
            size_t j      = i;
            for(; j < s.length() && j - i < k + 1; ++j)
            {
                if(s[j] > maxVal)
                {
                    maxVal = s[j];
                    maxPos = j;
                }
            }
            k -= (maxPos - i);
            i = maxPos;
            std::cout << maxVal;
        }
        std::cout << std::endl;
    }
}