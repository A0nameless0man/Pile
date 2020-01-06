#include "ChainTable.cpp"
#include <iostream>
#include <stdlib.h>

int main(void)
{
    ChainTable<int> a;
    // a.push(10);
    // std::cout << a.count(9) << a.count(10) << a.Length() << std::endl;
    // a.change(10, 9);
    // std::cout << a.count(9) << a.count(10) << a.Length() << std::endl;
    // a.remove(9);
    // std::cout << a.count(9) << a.count(10) << a.Length() << std::endl;
    for(int i = 0; i < 100000; i++)
    {
        a.push(i);
        std::cout << i << " " << a.count(i - 1) << " " << a.count(i) << " " << a.count(i + 1) << " "
                  << a.Length() << std::endl;
    }
    for(int i = 0; i < 100000; i++)
    {
        a.remove(i);
        std::cout << i << " " << a.count(i - 1) << " " << a.count(i) << " " << a.count(i + 1) << " "
                  << a.Length() << std::endl;
    }
    system("pause");
    return 0;
}