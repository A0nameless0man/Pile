#include <algorithm>
#include <iostream>

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        int ans = 1;
        for(int i = 0; i < n; ++i)
        {
            char c;
            int  m;
            std::cin >> c >> m;
            if(c == 'S')
            {
                ans = std::max(m, ans);
            }
            else
            {
                ans = std::max(1 << m - 1, ans);
            }
        }
        std::cout << ans << std::endl;
    }
}