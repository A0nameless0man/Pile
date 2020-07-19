#include <iostream>

const int PA[] = { 0, 10, 17, 20, 23, 27, 30, 33, 37, 40, 43 };
const int PO[] = { 0, 60, 62, 65, 67, 70, 75, 80, 85, 90, 95 };

const int CNT = 11;

int main(void)
{
    int t;
    while(std::cin >> t)
    {
        for(int i = 0; i < t; ++i)
        {
            int x;
            int ans = 0;
            std::cin >> x;
            for(int i = 0; i < 11; ++i)
            {
                for(int j = 0; j < 11; ++j)
                {
                    for(int k = 0; k < 11; ++k)
                    {
                        for(int l = 0; l < 11; ++l)
                        {
                            if(PO[i] + PO[j] + PO[k] + PO[l] <= x
                               && PA[i] + PA[j] + PA[k] + PA[l] > ans)
                            {
                                ans = PA[i] + PA[j] + PA[k] + PA[l];
                            }
                        }
                    }
                }
            }
            std::cout << ans / 10 << "." << ans % 10 << std::endl;
        }
    }
}