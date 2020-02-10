#include<iostream>

int main(void)
{
    int n,k;
    while(std::cin>>n>>k)
    {
        int sum = 0;
        for(int i = 0; i < n;++i)
        {
            int buf;
            std::cin >> buf;
            if(buf+k<=5)
            {
                sum++;
            }
        }
        std::cout << sum / 3 << std::endl;
    }
}