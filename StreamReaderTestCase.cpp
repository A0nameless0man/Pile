#include "StreamReader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include"colourStream.h"
using namespace kerbal::utility::costream;
#define PRINT(x) std::cout << #x << " is : " << (x) << std::endl;

#define CHECK(x)                                                                        \
    if ((x))                                                                            \
        costream<std::cout>(LIGHT_GREEN) << "Check : " << #x << " Passed" << std::endl; \
    else                                                                                \
        costream<std::cout>(LIGHT_RED) << "Check : " << #x << " Failed" << std::endl;
//#define TIMING(x)                                                                                  \
//    {                                                                                              \
//        clock_t cstart = clock();                                                                  \
//        (x);                                                                                       \
//        clock_t cend = clock();                                                                    \
//        std::cout << "It takes " << ((cend - cstart) / 1) << " clock to exec " << #x << std::endl; \
//    }
int main(void)
{
    CHECK((std::is_base_of<Reader::stdIstream, std::stringstream>::value))
    CHECK((std::is_convertible<const char[3], std::stringstream>::value))
    Reader::OperatorReader<std::stringstream, std::string> r;
    std::stringstream ss("ss aa");
    CHECK((r.read(ss) == "ss"));
    CHECK((r.read(ss) == "aa"));
}