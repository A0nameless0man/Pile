#include<iostream>

using A = struct 
{
    int x;
};

struct 
{
    int y;
}b;

using C = decltype(b);

int main(void)
{
    A a;
    C c;
    //a2.x = 0;
    a.x = 0;
    b.y = 0;
    std::cout << typeid(a).name() << std::endl;
    //std::cout << typeid(a2).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(c).name() << std::endl;
}
