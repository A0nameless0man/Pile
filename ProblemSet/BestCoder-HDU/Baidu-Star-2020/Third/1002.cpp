#include <iostream>

int main(void)
{
    int t;
    while(std::cin >> t)
    {
        for(int caseid = 0; caseid < t; ++caseid)
        {
            double x;
            std::cin >> x;
            if(x > (1.0))
            {
                printf("No\n");
            }
            else
            {
                printf("Yes\n");
            }
        }
    }
}