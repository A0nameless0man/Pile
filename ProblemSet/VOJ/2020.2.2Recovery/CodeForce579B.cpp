#include <iostream>
#include <queue>
#include <tuple>

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        n *= 2;
        std::priority_queue<std::tuple<int, int, int>> que;
        std::vector<int>                               vec;
        vec.resize(n + 7);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                int val;
                // std::cin >> val;
                scanf("%d",&val);
                que.push(std::make_tuple(val, i, j));
            }
        }
        while(!que.empty())
        {
            auto t = que.top();
            que.pop();
            if(vec[std::get<2>(t)] == 0 && vec[std::get<1>(t)] == 0)
            {
                vec[std::get<2>(t)] = std::get<1>(t);
                vec[std::get<1>(t)] = std::get<2>(t);
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            std::cout << vec[i];
            if(i == n)
            {
                std::cout << std::endl;
            }
            else
            {
                std::cout << " ";
            }
        }
    }
}