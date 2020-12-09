#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::string a, b;
    while(std::cin >> b >> a)
    {
        int i = 0;
        int j = 0;
        for(; j < b.length() && i < a.length(); ++j, ++i)
        {
            while(i < a.length() && a[i] != b[j])
            {
                ++i;
            }
        }
        if(j == b.length())
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
}