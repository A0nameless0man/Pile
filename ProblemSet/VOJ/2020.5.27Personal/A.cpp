#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        std::set<int> set_;
        for(int i = 0; i < n; ++i)
        {
            int buf;
            std::cin >> buf;
            set_.insert(buf);
        }
        std::vector<int> vec(set_.begin(), set_.end());
        std::vector<int> cnt(vec.size(), 0);
        for(int i = 0; i < vec.size(); ++i)
        {
            for(int j = i + 1; j < vec.size(); ++j)
            {
                if(vec[j] % vec[i] == 0)
                {
                    ++cnt[j];
                }
            }
        }
        int ans = 0;
        for(auto i: cnt)
        {
            // std::cout << i << " ";
            if(i == 0)
            {
                ++ans;
            }
        }
        std::cout << ans << std::endl;
    }
}