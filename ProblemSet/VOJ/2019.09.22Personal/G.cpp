#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
double sq(double i)
{
    return i * i;
}
bool match(double T, double V1, double V2)
{
    double r = V2 / V1;
    if(V2 > (V1 * 3))
    {
        return false;
    }
    else
    {
        if(V2 > (V1 * 1.4142135623730951))
        {
            double x =
              300 * ((sq(r) + 2) - sqrt(-sq(sq(r)) + 10 * sq(r) - 4 + 0.0001)) / (sq(r) - 1);
            double ETAA = (x + 4 * 300) / V1;
            double ETAS = (2 * 300 - x) / V2 + T;
            return ETAA <= ETAS;
        }
        else
        {
            double x = 300 * (sq(r) - 1 - 2 * sqrt(1 - sq(1 - sq(r)) + 0.0001)) / (2 * (1 - sq(r)));
            // double ETAA = (x + 2 * 300) / V1;
            // double ETAS = (2 * 300 - x) / V2 + T;
            return (x + 2 * 300) * V2 <= (2 * 300 - x) * V1 + T * V1 * V2;
        }
    }
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
            std::cout << "Yes";
        }
        else
        {
            std::cout << "No";
        }
        std::cout << std::endl;
    }
}