#include <iostream>
#include <typeinfo>
using Class = int;
class A
{
public:
    const static int i = 0;
};
int main(void)
{
    std::cout << typeid(A).name() << std::endl;
    std::cout << A::i << std::endl;
}