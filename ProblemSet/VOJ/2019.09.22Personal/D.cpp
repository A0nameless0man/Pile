#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
double sq(double i)
{
    return i * i;
}
int gcd(int a, int b)
{
    if(a < b)
    {
        return gcd(b, a);
    }
    while(a % b)
    {
        int c = a % b;
        a     = b;
        b     = c;
    }
    return b;
}
bool match(int n, int a, int b)
{
    int useAbleCount = n / gcd(a, b);  //(a&1 || b&1)?n:n/2;
    return useAbleCount & 1;
}
int main(void)
{
    int T;
    std::cin >> T;
    int t = 0;
    while(T--)
    {
        double T, V1, V2;
        std::cin >> T >> V1 >> V2;
        bool ans = match(T, V1, V2);

        std::cout << "Case #" << ++t << ": ";
        if(ans)
        {
            std::cout << "Yuwgna";
        }
        else
        {
            std::cout << "Iaka";
        }
        std::cout << std::endl;
    }
}