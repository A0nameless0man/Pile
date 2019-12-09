#include "StreamReader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cstdlib>
#define PRINT(x) std::cout << #x << " is : " << (x) << std::endl;

#define CHECK(x)                                                                                                        \
    if ((x))                                                                                                            \
        std::cout << "\033[38;5;2m" << std::flush << "Passed Check : " << #x << std::flush << "\t\033[0m" << std::endl; \
    else                                                                                                                \
        std::cout << "\033[38;5;1m" << std::flush << "Failed Check : " << #x << std::flush << "\t\033[0m" << std::endl;

//The colour code above works when compiled with clang, but have srange behavior using gcc!

//#define TIMING(x)                                                                                  \
//    {                                                                                              \
//        clock_t cstart = clock();                                                                  \
//        (x);                                                                                       \
//        clock_t cend = clock();                                                                    \
//        std::cout << "It takes " << ((cend - cstart) / 1) << " clock to exec " << #x << std::endl; \
//    }
struct S
{
    S(int k) : j(k) {}
    S(void) : j(0) {}
    int j;
    template <typename IS>
    S r(IS &is)
    {
        int i;
        is >> i;
        j = i;
        return S(i);
    }
    S re(Reader::stdIstream &is)
    {
        int i;
        is >> i;
        j = i;
        return S(i);
    }
};
class X : public S
{
public:
    template <class IS>
    X read(IS &is)
    {
        S::r(is);
        return X(*this);
    }
};
template <typename IS>
int f(IS &is)
{
    int i = 0;
    is >> i;
    return i;
}
int main(void)
{

    PRINT(typeid("aa").name())
    Reader::OperatorReader<std::string> s;
    std::stringstream ss("ss aa 456 789 100 102");
    CHECK((s(ss) == "ss"))
    CHECK((s(ss) == "aa"))
    Reader::OperatorReader<int> i;
    //CHECK((i.read(ss)==456))
    Reader::InteractiveStreamReader reader2(i);
    Reader::MemFnReader<X> mr;
    CHECK((reader2.read(ss, ss) == 456))
    CHECK((mr(ss).j==789))
    Reader::FunReader fr(f<decltype(ss)>);
    CHECK((fr(ss)==100))
    auto fu = [](decltype(ss) &is) ->S { S ts; ts.r(is); return ts; };
    Reader::FunReader fr2(fu);
    CHECK(fr2(ss).j==102)
    //CHECK((f(ss)==100))
    //CHECK((reader3.read(ss, ss).j == 102))
}