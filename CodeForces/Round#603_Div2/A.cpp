#include <iostream>
#include <algorithm>
int input[3];
int main(void)
{
    int n;
    while (std::cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                std::cin >> input[j];
            }
            std::sort(input, input + 3);
#ifdef DEBUG
            for (int i = 0; i < 3; ++i)
            {
                std::cout << input[i] << " ";
            }
#endif//DEBUG
            if(input[0]+input[1]<input[2])
            {
                std::cout << input[1] + input[0] << std::endl;
            }
            else
            {
                std::cout << (input[0] + input[1] + input[2]) / 2 << std::endl;
            }
            //std::cout << std::min(input[2], input[1] + input[0]) << std::endl;
            //a b c
            //([0]+[1]+[2])/2
            //[0]+[1]<[2]
        }
    }
}