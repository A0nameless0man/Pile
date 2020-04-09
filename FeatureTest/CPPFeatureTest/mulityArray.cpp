#include <iomanip>
#include <iostream>
#include <string>
template <typename T>
struct ArrayType
{
    using Result = T;
};
template <typename T, size_t N>
struct ArrayType<T[N]>
{
    using Result = typename ArrayType<T>::Result;
};
template <size_t N, typename T>
typename ArrayType<T>::Result sum(T (&a)[N])
{
    using sumType = typename ArrayType<T>::Result;
    sumType s {};
    for(size_t i = 0; i < N; i++)
    {
        s += sum(a[i]);
    }
    return s;
}

template <typename T>
const T& sum(const T &a)
{
    return a;
}
int main(void)
{
    long long   a[4][4][5] = { { { 1, 2, 3, 4, 5 }, { 2, 4, 6, 8, 10 } } };
    int         b[4]       = { 1, 2, 3, 4 };
    std::string s[][2]     = { { "a", "A" }, { "b", "B" } };
    // bar(a);
    std::cout << sum(a) << std::endl;
    std::cout << sum(b) << std::endl;
    std::cout << sum(s) << std::endl;
    std::cout << sum(1) << std::endl;
}