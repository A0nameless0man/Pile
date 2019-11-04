#include <iostream>
#include <time.h>
#define START(x)                                \
    std::cout << "\tStart:" << #x << std::endl; \
    {                                           \
        using namespace x;
#define END(x)                                 \
    }                                          \
    std::cout << "\tEnd:" << (#x) << std::endl \
              << std::endl;
#define CHECK(x) std::cout << #x << " is : " << (x) << std::endl;
#define TIMING(x)                                                                                                       \
    {                                                                                                                   \
        clock_t start = clock();                                                                                        \
        (x);                                                                                                            \
        clock_t end = clock();                                                                                          \
        std::cout << "It takes " << (((double)end - start) / 1) << " clock to exec " << #x << std::endl; \
    }
constexpr int fib(int n)
{
    for (size_t i = 0; i < 10; i++)
    {
        int j = i;
    }
    return n;
}
int fiib(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}
template <int n>
struct constN
{
    int n;
};

int main(void)
{
    int n;
    std::cout << "constexpr:" << std::endl;
    {
        clock_t start = clock();
        constN<fib(30)> n;
        clock_t end = clock();
        std::cout << "It takes " << (((double)end - start) / 1) << " clock to exec " << "constexpr" << std::endl;
    }

    std::cout << "notconstexpr:" << std::endl;
    TIMING((n = fib(30)));
    return 0;
}