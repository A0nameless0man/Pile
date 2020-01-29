#include <cstdio>
#include <iostream>
using namespace std;
template <typename... Args>
struct Count
{
};

template <typename T, typename... Args>
struct Count<T, Args...>
{
    const static int res = 1 + Count<Args...>::res;
};

template <typename T>
struct Count<T>
{
    const static int res = 1;
};
template <typename... Args>
struct trio
{
};
template <typename T1, typename T2, typename T3>
class trio<T1, T2, T3>
{
public:
    void show(void)
    {
        printf("1\n");
    }
};
template <typename T1, typename T2>
class trio<T1, T2, T2>
{
public:
    void show(void)
    {
        printf("2\n");
    }
};
template <typename T1>
class trio<T1, T1 *, T1 *>
{
public:
    void show(void)
    {
        printf("3\n");
    }
};
template <typename T1>
class trio<T1>
{
public:
    void show(void)
    {
        printf("4\n");
    }
};
int main(void)
{
    trio<int, short, char *>().show();
    trio<int, short, short>().show();
    trio<char, char *, char *>().show();
    trio<char>().show();
    std::cout << Count<int, char, int>::res << std::endl;
    return 0;
}