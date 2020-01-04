#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <time.h>
#include <vector>

template <class T>
std::chrono::duration<double> timing(T t)
{
    auto cstart = std::chrono::system_clock::now();
    t();
    auto cend = std::chrono::system_clock::now();

    std::chrono::duration<double> timeConsumption = (cend - cstart);
    return timeConsumption;
}

const size_t MAX_N = 100000000;

template <typename T>
size_t sequenceFind(std::vector<T> &vec, const T &key)
{
    for(size_t i = 0; i < vec.size(); ++i)
    {
        if(vec[i] == key)
        {
            return i;
        }
    }
    return static_cast<size_t>(-1);
}
template <typename T>
size_t guardedSequenceFind(std::vector<T> &vec, const T &key)
{
    size_t i = 0;
    vec.push_back(key);
    while(vec[i] != key)
    {
        ++i;
    }
    vec.pop_back();
    return i == vec.size() ? static_cast<size_t>(-1) : i;
}
template <typename T>
std::pair<size_t, size_t> binarySearch(std::vector<T> &vec, const T &key)
{
    size_t l = 0;
    size_t r = vec.size();
    int count = 0;
    while(l < r)
    {
        size_t mid = (l + r) / 2;
        if(vec[mid] > key)
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
        ++count;
    }
    return { l, count };
}
int main(void)
{
    std::vector<size_t> a;
    a.reserve(MAX_N + 10000);
    for(size_t i = 0; i < MAX_N; ++i)
    {
        a.push_back(i);
    }
    // TIMING(std::shuffle(a.begin(), a.end(), std::random_device()))
    std::chrono::duration<double> s;
    std::chrono::duration<double> g;
    std::chrono::duration<double> b;
    for(int i = 0; i < 1000; ++i)
    {
        s += timing([&]() -> void {
            sequenceFind(a, MAX_N / 2);
        });
    }
    std::cout << "s" << std::fixed << s.count() << std::endl;
    for(int i = 0; i < 1000; ++i)
    {
        b += timing([&]() -> void {
            binarySearch(a, MAX_N / 2);
        });
    }
    std::cout << "b" << std::fixed << b.count() << std::endl;
    sequenceFind(a, MAX_N);
    for(int i = 0; i < 1000; ++i)
    {
        g += timing([&]() -> void {
            guardedSequenceFind(a, MAX_N/2);
        });
    }
    std::cout << "g" << std::fixed << g.count() << std::endl;

}