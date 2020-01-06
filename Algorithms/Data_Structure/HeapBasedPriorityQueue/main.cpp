#include "PriorityQueue.h"
#include <iostream>
int main(void)
{
    while(true)
    {
        int                   n;
        P_Queue::P_Queue<int> queue;
        while(std::cin >> n)
        {
            queue.insert(n);
        }
        while(!queue.empty())
        {
            std::cout << queue.top() << std::endl;
            queue.pop();
        }
    }
}