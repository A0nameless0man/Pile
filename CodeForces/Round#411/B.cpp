#include<iostream>
int main(void)
{
    int n;
    while(std::cin>>n)
    {
        while(n--)
        {
            if(n%4<2)
            {
                std::cout << 'a';
            }
            else
            {
                std::cout << 'b';
            }
        }
        std::cout << std::endl;
    }
}