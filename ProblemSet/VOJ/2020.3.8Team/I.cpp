#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using LB    = long double;
const LB PI = acos(-1);

const LB D = 60;
const LB R = D / 2;

const LB ANGLE = 2 * PI / 28;

const LB V  = 15;
const LB PAUSE = 1;

int ctoi(char &c)
{
    if(isalpha(c))
    {
        return c - 'A';
    }
    else if(c == ' ')
    {
        return 26;
    }
    else if(c == '\'')
    {
        return 27;
    }
    else
    {
        throw c;
        return -1;
    }
}

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        while(!isalpha(std::cin.peek()))
        {
            std::cin.get();
        }
        std::string buf;
        for(int i = 0; i < n; ++i)
        {
            std::getline(std::cin, buf);
            LB ans = 0;
            int dis = 0;
            for(size_t i = 1; i < buf.length(); ++i)
            {
                dis += std::abs(ctoi(buf[i]) - ctoi(buf[i - 1]));
                // ans += R * ANGLE / V * std::abs(ctoi(buf[i]) - ctoi(buf[i - 1]));
            }
            ans += R * ANGLE / V * dis;
            ans += buf.length() * PAUSE;
            std::cout << std::setprecision(std::numeric_limits<LB>::digits10 + 1) << ans
                      << std::endl;
        }
    }
}