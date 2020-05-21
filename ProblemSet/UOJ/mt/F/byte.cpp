#include <iostream>
#include <vector>

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        std::vector<int> vec;
        for(int i = 0; i < n; ++i)
        {
            int buf;
            std::cin >> buf;
            vec.push_back(buf);
            while(buf)
            {
                std::cout << (buf & 1);
                buf >>= 1;
            }
            std::cout << std::endl;
        }
        for(long long i = 0; i < (1ll << n);++i)
        {
            int k = 0;
            for(int j = 0; j < n;++j)
            {
                if((i>>j)&1)
                {
                    k ^= vec[j];
                }
            }
            if((k&(k-1))==0)
            {
                std::cout << i << " " << k << std::endl;

            }else if(i%(1024*1024)==0)
            {
                std::cout << "F" << i << "\r";
            }
        }
        std::cout << std::endl;
    }
}