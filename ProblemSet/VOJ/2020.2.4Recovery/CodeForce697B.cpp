#include <iostream>
#include <string>

int main(void)
{
    std::string a, b, d;
    std::string buf;
    while(std::cin >> buf)
    {
        auto pos1     = buf.find_first_of('.');
        auto pos2     = buf.find_first_of('e');
        a             = buf.substr(0, pos1);
        b             = buf.substr(pos1 + 1, pos2 - pos1 - 1);
        b             = b.substr(0, b.find_last_not_of('0') + 1);
        d             = buf.substr(pos2 + 1);
        long long dll = stoll(d);
        for(auto &c: a)
        {
            std::cout << c;
        }
        for(size_t i = 0; i < b.size(); ++i)
        {
            if(i == dll)
            {
                {
                    std::cout << '.';
                }
            }
            std::cout << b[i];
        }
        for(auto i = b.size(); i < dll; ++i)
        {
            std::cout << '0';
        }
        std::cout << std::endl;
    }
    return 0;
}