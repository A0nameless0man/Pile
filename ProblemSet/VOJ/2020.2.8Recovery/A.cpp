#include <iostream>

const int MAX_N = 1e7 + 7;

long long buf[MAX_N];

int main(void)
{
    long long n;
    while(std::cin >> n)
    {
        int cnt = 0;
        for(long long i = 0; i < n; ++i)
        {
            buf[i] = 0;
        }
        for(long long i = 0; i < n; ++i)
        {
            buf[cnt] = 1;
            // for(int i = 0; i <= cnt; ++i)
            // {
            //     std::cout << buf[cnt];
            //     if(i == cnt)
            //     {
            //         std::cout << std::endl;
            //     }
            //     else
            //     {
            //         std::cout << "*";
            //     }
            // }
            while(cnt >= 1&&buf[cnt]==buf[cnt-1])
            {
                --cnt;
                ++buf[cnt];
                // for(int i = 0; i <= cnt; ++i)
                // {
                //     std::cout << buf[cnt];
                //     if(i == cnt)
                //     {
                //         std::cout << std::endl;
                //     }
                //     else
                //     {
                //         std::cout << "+";
                //     }
                // }
            }
            ++cnt;
        }
        for(int i = 0; i < cnt;++i)
        {
            std::cout << buf[i];
            if(i==cnt-1)
            {
                std::cout << std::endl;
            }
            else
            {
                std::cout << " ";
            }
            
        }
    }
    return 0;
}