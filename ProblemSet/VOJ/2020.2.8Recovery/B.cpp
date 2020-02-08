#include <iostream>
#include <map>
int input[57][57];
int ans[57];

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                std::cin >> input[i][j];
            }
            ans[i] = -1;
        }
        if(n == 2)
        {
            std::cout << "1 2" << std::endl;
        }
        else
        {
            for(int i = 1; i <= n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if([&]() -> bool {
                           for(int k = 0; k < n; ++k)
                           {
                               if(k != j && ans[k] == -1 && input[j][k] != i)
                               {
                                   return false;
                               }
                           }
                           return true;
                       }())
                    {
                        ans[j] = i;
                        break;
                    }
                }
            }
            for(int i = 0; i < n; ++i)
            {
                std::cout << ans[i];
                if(i != n - 1)
                {
                    std::cout << " ";
                }
                else
                {
                    std::cout << "\n";
                }
            }
        }
    }
}