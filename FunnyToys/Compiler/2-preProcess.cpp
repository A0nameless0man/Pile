#include <iostream>
#include <string>

int main(void)
{
    std::string s, last;
    while(std::getline(std::cin, s))
    {
        if(s.ends_with('\\'))
        {
            s.pop_back();
            std::cout << s;
        }
        else
        {
            std::cout << s << std::endl;
        }
    }
    return 0;
}