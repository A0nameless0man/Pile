#include <iostream>
#include <map>
#include <queue>
#include <stack>
int main(void)
{
    int n;
    while(std::cin >> n)
    {
        std::map<int, int> input;
        {
            int buf;
            for(int i = 0; i < n; ++i)
            {
                std::cin >> buf;
                input[buf]++;
            }
        }
        int             ans = 0;
        std::stack<int> front;
        std::queue<int> back;
        bool            single = false;
        for(std::map<int, int>::iterator iter = input.begin(); iter != input.end(); iter++)
        {
            if(iter->second >= 2)
            {
                front.push(iter->first);
                back.push(iter->first);
            }
            else
            {
                front.push(iter->first);
            }
        }
        std::vector<int> output;
        while(!back.empty())
        {
            output.push_back(back.front());
            back.pop();
        }
        if(!front.empty() && !output.empty() && front.top() == *(output.rbegin()))
        {
            front.pop();
        }
        while(!front.empty())
        {
            output.push_back(front.top());
            front.pop();
        }
        std::cout << output.size() << std::endl;
        for(int i = 0; i < output.size(); ++i)
        {
            std::cout << output[i];
            if(i != output.size() - 1)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << std::endl;
            }
        }
    }
}
