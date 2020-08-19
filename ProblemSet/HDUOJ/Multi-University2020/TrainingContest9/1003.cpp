#include <cmath>
#include <iostream>

int main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            int n, m, k;
            std::cin >> n >> m >> k;
            double p =
              (1 - k
               + sqrtl(static_cast<double>(k + 1) * (k + 1)
                       + 4))
              / 2;
            if(n > m)
            {
                std::swap(n, m);
            }
#ifdef DEBUG
            // std::cout << "P: " << p << "\n";
            // std::cout << "(m ) " << (m) << "\n";
            // std::cout << "(n) * p " << (n) *p << "\n";
            // std::cout << "n " << n << "\n";
#endif  // DEBUG
            int dif = m - n;
            if(dif % (1 + k) != 0)
            {
                std::cout << "1\n";
            }
            else
            {
                int pos = dif / (1 + k);
                if(n == static_cast<int>(pos * p))
                {
                    std::cout << "0\n";
                }
                else
                {
                    std::cout << "1\n";
                }
            }
        }
    }
}