#include <iostream>
#include <stack>
#include <vector>
int main(void)
{
    int n;
    while (std::cin >> n)
    {
        std::vector<int> input[2];
        for (size_t i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int buffer;
                std::cin >> buffer;
                input[i].push_back(buffer);
            }
        }
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2+1;
            //if(mid>=n)mid = n-1;
            std::stack<int> stack[2];
            std::vector<int> ans[2];
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < mid; j++)
                {
                    while (!stack[i].empty() && input[i][j] < input[i][stack[i].top()])
                    {
                        ans[i].push_back(stack[i].top());
                        stack[i].pop();
                    }
                    stack[i].push(j);
                }
                while (!stack[i].empty())
                {
                    ans[i].push_back(stack[i].top());
                    stack[i].pop();
                }
            }
            bool check = true;
            for (size_t i = 0; i < ans[0].size(); i++)
            {
                if (ans[0][i] != ans[1][i])
                {
                    check = false;
                }
            }
            if (check)
            {
                l = mid;
            }
            else
            {
                r = mid-1;
            }
            // if (1)
            // {
            //     std::cout << "r" << r  << std::endl<< "l" << l  << std::endl<< "check" << check << std::endl<<"mid"<<mid<<std::endl;;
            //     for (size_t i = 0; i < ans[0].size(); i++)
            //     {
            //         std::cout << ans[0][i] << " ";
            //     }
            //     std::cout << std::endl;
            //     for (size_t i = 0; i < ans[0].size(); i++)
            //     {
            //         std::cout << ans[1][i] << " ";
            //     }
            //     std::cout << std::endl;
            // }
        }
        std::cout << l << std::endl;
    }
}