#include <iostream>
#include <queue>
#include <vector>

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        if(n != 0)
        {
            std::priority_queue<int,
                                std::vector<int>,
                                std::greater<int> >
              q;
            for(int i = 0; i < n; ++i)
            {
                int k;
                std::cin >> k;
                q.push(k);
            }
            int sum = 0;
            while(q.size() > 1)
            {
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                q.push(a + b);
                sum += a + b;
            }
            std::cout << sum << std::endl;
        }
    }
}