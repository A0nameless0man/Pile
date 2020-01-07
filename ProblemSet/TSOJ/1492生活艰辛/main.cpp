#include <iostream>
int main(void)
{
    int n, m, k;
    while(std::cin >> n >> k)
    {
        for(m = 0; m <= 20; m++)
        {
            if(200 + m * k <= n * m)
            {
                break;
            }
        }
        if(m <= 20)
        {
            std::cout << m << std::endl;
        }
        else
        {
            std::cout << "Impossible" << std::endl;
        }
    }
    return 0;
}