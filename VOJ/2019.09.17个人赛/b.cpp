#include <algorithm>
#include <cstring>
#include <iostream>
int vec[200007];
int main(void)
{
    int s;
    while(std::cin >> s)
    {
        memset(vec, 0, (5 + s) * sizeof(vec[0]));
        for(int i = 0; i < s; i++)
        {
            std::cin >> vec[i];
        }
        try
        {
            for(int i = 0; i < s; i++)
            {

                int discount = (vec[i]) / 2;
                int coupon   = vec[i] - discount * 2;
                if(vec[i + 1] < coupon)
                {
                    throw false;
                }
                else
                {
                    vec[i + 1] -= coupon;
                }
            }
            throw true;
        }
        catch(bool ans)
        {
            if(ans)
            {
                std::cout << "YES" << std::endl;
            }
            else
            {
                std::cout << "NO" << std::endl;
            }
        }
    }
}