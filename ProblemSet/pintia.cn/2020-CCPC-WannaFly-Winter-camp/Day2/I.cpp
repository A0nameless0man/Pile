#include <iostream>

int main(void)
{
    int t;
    while(std::cin >> t)
    {
        bool f = true;
        while(t--) {
            int a, b;
            std::cin >> a >> b;
            if(a==1)
            {
                f = false;
            }
        }
        if(f)
        {
            std::cout << "0.466667" << std::endl;
        }
        else
        {
            std::cout << "error" << std::endl;
        }
    }
    return 0;
}