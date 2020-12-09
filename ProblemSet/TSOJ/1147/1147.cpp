#include <iostream>
#include <string>

int main(void)
{
    std::string s;
    while(std::cin >> s)
    {
        if(s=="0")
        {
            break;
        }
        long long sum = 0;
        for(size_t i = 0; i < s.length(); ++i)
        {
            sum += (s[i] - '0')
                   * ((1ll << (s.length() - i)) - 1);
        }
        std::cout << sum << std::endl;
    }
}

