#include "StreamReader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

//#define PRINT(x) std::cout << #x << " is : " << (x) << std::endl;

#define CHECK(x)                                                                                                        \
    if ((x))                                                                                                            \
        std::cout << "\033[38;5;2m" << std::flush << "Passed Check : " << #x << std::flush << "\t\033[0m" << std::endl; \
    else                                                                                                                \
        std::cout << "\033[38;5;1m" << std::flush << "Failed Check : " << #x << std::flush << "\t\033[0m" << std::endl;
//#define TIMING(x)                                                                                  \
//    {                                                                                              \
//        clock_t cstart = clock();                                                                  \
//        (x);                                                                                       \
//        clock_t cend = clock();                                                                    \
//        std::cout << "It takes " << ((cend - cstart) / 1) << " clock to exec " << #x << std::endl; \
//    }
int main(void)
{
    
    Reader::OperatorReader<std::stringstream, std::string> r;
    std::stringstream ss("ss aa");
    CHECK((r.read(ss) == "ss"))
    CHECK((r.read(ss) == "aa"))
    system("pause");
}