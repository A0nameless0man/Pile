#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool search(std::vector<int> &ans, const std::vector<int> &input)
{
    if(input.empty() || input.size() % 2 == 0)
    {
        return false;
    }
    if(ans.empty())
    {
        for(int i = 0; i < 10; ++i)
        {
            if(i * i % 10 == input.at(0))
            {
                ans.push_back(i);
                if(search(ans, input))
                {
                    return true;
                }
                else
                {
                    ans.pop_back();
                }
            }
        }
        return false;
    }
    else
    {
        if(ans.size() * 2 - 1 == input.size())
        {
            for(size_t i = ans.size(); i < input.size(); ++i)
            {
                int sum = 0;
                for(size_t j = i - ans.size() + 1; j < ans.size(); ++j)
                {
                    sum += ans[j] * ans[i - j];
                }
                sum %= 10;
                if(input.at(i) != sum)
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            size_t pos  = ans.size();
            int    next = input.at(pos);
            int    sum  = 0;
            for(size_t i = 1; i < pos; ++i)
            {
                sum += ans[i] * ans[pos - i];
            }
            sum %= 10;
            int diff = (next - sum + 10) % 10;
            for(int i = 0; i < 10; ++i)
            {
                if(i * ans[0] * 2 % 10 == diff)
                {
                    ans.push_back(i);
                    if(search(ans, input))
                    {
                        return true;
                    }
                    else
                    {
                        ans.pop_back();
                    }
                }
            }
            return false;
        }
    }
}

int main(void)
{
    std::string input;
    while(std::cin >> input)
    {
        std::vector<int> ans, in;
        for(auto c: input)
        {
            in.push_back(c - '0');
        }
        if(search(ans, in))
        {
            for(auto i: ans)
            {
                std::cout << i;
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << "-1\n";
        }
    }
    return 0;
}