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
int main(void)
{
    PRINT(typeid("aa").name())
    Reader::OperatorReader<std::string> s;
    std::stringstream ss("ss aa 123 456");
    CHECK((s.read(ss) == "ss"))
    CHECK((s.read(ss) == "aa"))
    Reader::OperatorReader<int> i;
    //CHECK((i.read(ss)==456))
    Reader::InteractiveStreamReader<int,Reader::OperatorReader> reader;

    Reader::InteractiveStreamReader reader2(i);
    CHECK((reader.read(ss,ss)==123))
    CHECK((reader2.read(ss,ss)==456))
}