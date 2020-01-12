#include<array>
static std::array<std::array<int, 2> ,2> a = { { { 1, 1 }, { 1, 1 } } };
int main(void)
{
    int sum = 0;
    for(auto &i:a)
    {
        for(auto & j:i)
        {
            sum += j;
        }
    }
    return sum;
}
