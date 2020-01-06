#include <iostream>
#include <time.h>
//#define CHECK(x) std::cout << #x << " is : " << (x) << std::endl;
#define TIMING(x)                                                                                  \
    {                                                                                              \
        clock_t cstart = clock();                                                                  \
        (x);                                                                                       \
        clock_t cend = clock();                                                                    \
        std::cout << "It takes " << ((cend - cstart) / 1) << " clock to exec " << #x << std::endl; \
    }
constexpr int fib(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}

int main(void)
{
    int       g;
    const int test = 41;
    {
        clock_t       cstart = clock();
        constexpr int x      = fib(test);
        clock_t       cend   = clock();
        std::cout << "It takes " << ((cend - cstart) / 1) << " clock to exec constexpr"
                  << std::endl;
        std::cout << x << std::endl;
    }
    TIMING(g = fib(test))

    // std::cout << "notconstexpr:" << std::endl;
    // TIMING((n = fib(30)));
    return g;
}