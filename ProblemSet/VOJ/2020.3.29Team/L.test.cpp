#include <algorithm>
#include <iostream>
#include <string>

std::string mul(const std::string &lop, const std::string &rop)
{
    auto        len = std::max(lop.length(), rop.length());
    std::string ans;
    for(size_t i = 0; i < len * 2; ++i)
    {
        int sum = 0;
        for(size_t j = 0; j <= i; ++j)
        {
            sum += (j < lop.length() ? lop.at(j) - '0' : 0)
                   * (i - j < rop.length() ? rop.at(i - j) - '0' : 0);
            sum %= 10;
        }
        ans.push_back(sum + '0');
    }
    // std::reverse(ans.begin(), ans.end());
    return ans;
}

int main(void)
{
    for(int i = 0; i < 1000; ++i)
    {
        std::cout << "i:" << i << "=>" << mul(std::to_string(i), std::to_string(i)) << std::endl;
    }
}