#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Task
{
    int lim;
    int profit;
};
bool operator<(const Task &lop, const Task &rop)
{
    return lop.lim < rop.lim;
}

int main(void)
{
    int n, m;
    while(std::cin >> m >> n)
    {
        std::vector<int>  lim;
        std::vector<int>  profit;
        std::vector<Task> tasks;
        for(int i = 0; i < n; ++i)
        {
            int t;
            std::cin >> t;
            lim.push_back(t);
        }
        for(int i = 0; i < n; ++i)
        {
            int t;
            std::cin >> t;
            profit.push_back(t);
        }
        for(int i = 0; i < n; ++i)
        {
            tasks.push_back({ lim[i], profit[i] });
        }
        std::sort(tasks.begin(), tasks.end());
        std::priority_queue<int,
                            std::vector<int>,
                            std::greater<int>>
            Q;
        int j = 0;
        for(size_t i = 1; i <= 500; ++i)
        {
            while(j < tasks.size() && tasks[j].lim <= i)
            {
                Q.push(tasks[j].profit);
                ++j;
            }
            while(Q.size() > i)
            {
                m -= Q.top();
                Q.pop();
            }
        }
        std::cout << m << std::endl;
    }
}