#include <iostream>

int main(void)
{
    char a = 1, e = 2;
    int  b = 3, c = 4, d = 5;
    auto lam1 = [=]() {
        a + b + c + d + e;
    };
    auto lam2 = [=]() {
        a + e + b + c + d;
    };
    std::cout << sizeof(lam1) << " " << sizeof(lam2) << std::endl;
    for(int i = 0; i < sizeof(lam1); ++i)
    {
        std::cout << static_cast<short>(*(static_cast<char *>(static_cast<void *>(&lam1)) + i))
                  << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < sizeof(lam2); ++i)
    {
        std::cout << static_cast<short>(*(static_cast<char *>(static_cast<void *>(&lam2)) + i))
                  << " ";
    }
    std::cout << std::endl;
}