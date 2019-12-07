#include<iostream>
template <class T>
class A
{
public:
    A(T tt) : t(tt)
    {
    }
    T t;
};
template <class T,template <typename>class X>
class B
{
public:
    B(T tt,X<T> xx) : t(tt),x(xx)
    {
    }
    B(X<T> xx):t(xx.t),x(xx)
    {

    }
    T t;
    X<T> x;
};
int main(void)
{
    A a(1);
    B b(1,a);
    B bb(a);
    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(bb).name() << std::endl;
}