#include <algorithm>
#include <iostream>
#include <string>

int main(void)
{
    int t;
    while(std::cin >> t)
    {
        while(t--)
        {
            int n;
            std::cin >> n;
            int count[4][10];
            for(int x = 0; x < 10; ++x)
                for(int y = 0; y < 4; ++y)
                    count[y][x] = 0;
            std::string input[10];
            for(int i = 0; i < n; ++i)
            {
                std::cin >> input[i];
                for(int j = 0; j < 4; ++j)
                {
                    ++count[j][input[i][j] - '0'];
                }
            }
            // std::sort(input, input + n);
            int ans = 0;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < i; ++j)
                {
                    if(input[j] == input[i])
                    {
                        int x = 0, y = 0;
                        while(count[x][y])
                        {
                            y++;
                            x += y / 10;
                            y %= 10;
                        }
                        --count[x][input[i][x] - '0'];
                        input[i][x] = y + '0';
                        ++count[x][y];
                        ++ans;
                    }
                }
            std::cout << ans << std::endl;
            for(int i = 0; i < n; ++i)
            {
                std::cout << input[i] << std::endl;
            }
        }
    }
    return 0;
}
/*
1
10
1111
1111
1111
1111
1111
1111
1111
1111
1111
1111
1
5
3492
7166
5022
4806
3492
*/