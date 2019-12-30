#include<iostream>
#include<iomanip>

int foo(int a[][4]);
int foo(int a[][4])
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << a[i] << std::endl;
    }
    return 0;
}

template<size_t N>
int bar(int a[][N])
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << a[i] << std::endl;
    }
    std::cout << N << std::endl;
    return 0;
}

int main(void)
{
    int a[4][4];
    for (int i = 0; i < 4;i++)
    {
        std::cout << a[i] << std::endl;
    }
    foo(a);
    bar(a);
}