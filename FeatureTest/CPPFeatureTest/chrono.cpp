#include<iostream>
#include<chrono>

using namespace std::chrono;

template <class C = steady_clock>
class timer
{
    using TimePoint = std::chrono::time_point<C>;
    TimePoint start_;
    TimePoint end_;

public:
    timer &begin(void)
    {
        this->start_ = C::now();
        return *this;
    }
    timer &stop(void)
    {
        this->end_ = C::now();
        return *this;
    }
    int64_t get(void)
    {
        return duration_cast<microseconds>(end_ - start_).count();
    }
};
using GoodClock = timer<steady_clock>;

int main(void)
{
    GoodClock gc;
    gc.begin();
    for(int i = 0; i < 1000000000;++i)
    {
        continue;
    }
    gc.stop();
    std::cout << gc.get();
}