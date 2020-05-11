#include <iostream>

int main(void)
{
    bool f = true;
    std::ios::sync_with_stdio(false);
    while(true)
    {
        char buf = std::cin.get();
        if(std::cin)
        {
            if(buf == '"')
            {
                if(f)
                {
                    std::cout << "``";
                }
                else
                {
                    std::cout << "''";
                }
                f ^= 1;
            }
            else
            {
                std::cout << buf;
            }
        }
        else
        {
            break;
        }
    }
}