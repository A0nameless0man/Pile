#include <iostream>
template <class T>
class A
{
public:
    A(T tt) : t(tt)
    {
    }
    T t;
    using Type = T;
};
template <class T, template <typename> class X, template <typename> class Y>
class B
{
public:
    B(T tt, X<T> xx, Y<T> yy) : t(tt), x(xx), y(yy)
    {
    }
    B(X<T> xx, Y<T> yy) : t(xx.t), x(xx), y(yy)
    {
    }
    T t;
    X<T> x;
    Y<T> y;
};

template <class T>
class C
{
public:
    template <class X>
    C(X xx) : t(xx.t)
    {
    }
    T t;
    void foo(void){}
};

template <class X>
explicit C(X)->C<typename X::Type>;

int main(void)
{
    A a(1);
    B b(1, a, a);
    B bb(a, a);
    B bbb(a, A(1));
    B bbbb(1, a, a);
    C c(a);
    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(bb).name() << std::endl;
    std::cout << typeid(bbb).name() << std::endl;
    std::cout << typeid(bbbb).name() << std::endl;
    std::cout << typeid(c).name() << std::endl;
    std::cout << typeid(A<int>::Type).name() << std::endl;
    std::cout << typeid(& C<int>::foo).name() << std::endl;
}