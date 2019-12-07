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
template <class T, template <typename> class X, template <typename> class Y>
class B
{
public:
    B(T tt,X<T> xx,Y<T> yy) : t(tt),x(xx),y(yy)
    {
    }
    B(X<T> xx, Y<T> yy) : t(xx.t), x(xx), y(yy)
    {

    }
    T t;
    X<T> x;
    Y<T> y;
};
int main(void)
{
    A a(1);
    B b(1,a,a);
    B bb(a,a);
    B bbb(a, A(1.0));
    B bbbb(1 ,a, a);
    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(bb).name() << std::endl;
    std::cout << typeid(bbb).name() << std::endl;
    std::cout << typeid(bbbb).name() << std::endl;
}