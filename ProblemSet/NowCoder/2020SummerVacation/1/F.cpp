#include <iostream>
#include <string>
/*
Time: 2020-07-13 15:09:22
Describe: Accepted
Statue: AC
*/
int main(void)
{
    std::string a, b;
    while(std::cin >> a >> b)
    {
        char ac, bc;
        for(size_t i = 0; i < a.length() + b.length(); ++i)
        {
            ac = a[i % a.length()];
            bc = b[i % b.length()];
            if(ac != bc)
            {
                break;
            }
        }
        if(ac < bc)
        {
            std::cout << "<\n";
        }
        else if(ac > bc)
        {
            std::cout << ">\n";
        }
        else
        {
            std::cout << "=\n";
        }
    }
}