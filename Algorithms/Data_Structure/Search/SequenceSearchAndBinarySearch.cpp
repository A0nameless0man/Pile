#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

struct myclock
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    template <typename A = std::chrono::microseconds>
    auto count()
    {
        return std::chrono::duration_cast<A>(std::chrono::steady_clock::now() - start).count();
    }
};
using namespace std;
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
        // std::cout << "mid: " << mid << std::endl;
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
const size_t MAX_N = 100000000;
const size_t TIMES = 1000;

int main(void)
{
     size_t n;
    while(std::cin >> n)
    {
        std::vector<size_t> a;
        a.reserve(n + 10000);
        for(size_t i = 0; i < n; ++i)
        {
            a.push_back(i);
        }
        
        size_t tar;
        std::cin >> tar;

        {
            myclock c;

            for(size_t i = 0; i < TIMES; ++i) {
                // sequenceFind(a, tar);
                auto it = std::find(a.begin(), a.end(), tar);
            }
                
            cout << c.count() << endl;
        }
        {
            myclock c;
 
            for(size_t i = 0; i < TIMES; ++i) {
                // binarySearch(a, tar);
                auto it = std::lower_bound(a.begin(), a.end(), tar);
            }
            cout << c.count() << endl;
        }
        // {
        //     myclock c;

        //     for(size_t i = 0; i < TIMES; ++i)
        //         guardedSequenceFind(a, tar);
        //     cout << c.count() << endl;
        // }
    }
}