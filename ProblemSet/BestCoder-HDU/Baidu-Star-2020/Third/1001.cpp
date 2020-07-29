#include <cstdio>
#include <iostream>
int main(void)
{
    int t;
    while(std::cin >> t)
    {
        int n;
        for(int i = 0; i < t; ++i)
        {
            std::cin >> n;
            double best = 0.0;
            int    b;
            double c;
            for(int i = 0; i < n; i++)
            {
                std::cin >> b >> c;
                double cur = (1.0 - c) / (1.0 + b - c);
                if(cur > best)
                {
                    best = cur;
                }
            }
            printf("%.5lf\n", best);
        }
    }
}