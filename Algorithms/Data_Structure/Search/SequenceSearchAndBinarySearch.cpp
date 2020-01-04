#include <iostream>
#include <time.h>

#define TIMING(x)                                                                                  \
    {                                                                                              \
        clock_t cstart = clock ( );                                                                \
        (x);                                                                                       \
        clock_t cend = clock ( );                                                                  \
        std::cout << "It takes " << ((cend - cstart) / 1) << " clock to exec " << #x << std::endl; \
    }
