// #include<iostream>

#include"BigInt.hpp"

int main(void)
{
    BigInt::BigInt a, b;
    while(std::cin>>a>>b)
    {
        // std::cout << a + b << std::endl;
        // std::cout << a - b << std::endl;
        std::cout << a * b << std::endl;
    }

}