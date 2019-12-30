#include <iostream>
#include <iomanip>

template <size_t N,typename T>
int bar(T (&a)[N])
{
    for (size_t i = 0; i < N; i++)
    {
        bar(a[i]);
    }
    std::cout << N << std::endl
              << std::endl;
    
    return 0;
}
template<typename T>
int bar(T &a)
{

        std::cout << a << std::endl;

    return 0;
}

int main(void)
{
    long long a[4][4][5];
    int b[4] = {0};

    bar(a);
    bar(b);
}