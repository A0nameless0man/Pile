#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int MAGIC_ROUND = 10000;

struct event
{
    int bub;
    int tim;
};

bool operator<(const event& lop,const event&rop)
{
    return lop.tim > rop.tim;
}

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        std::string                      buf;
        std::vector<char>                bubs(n, false);
        std::vector<std::pair<int, int>> timing;
        std::priority_queue<event>       que;
        int                              best = 0;
        std::cin >> buf;
        for(int i = 0; i < n; ++i)
        {
            if(buf[i] == '0')
            {
                bubs[i] = false;
            }
            else
            {
                bubs[i] = true;
                ++best;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            int a, b;
            std::cin >> a >> b;
            timing.push_back(std::make_pair(a, b));
            que.push({ i, b });
        }
        for(int i = 0; i < MAGIC_ROUND; ++i)
        {
            while(que.top().tim == i)
            {
                auto cur = que.top();
                que.pop();
                bubs[cur.bub] ^= 1;
                que.push({ cur.bub, i + timing[cur.bub].first });
            }
            int cur = 0;
            for(int j = 0; j < n; ++j)
            {
                if(bubs[j])
                {
                    ++cur;
                }
            }
            if(cur > best)
            {
                best = cur;
            }
        }
        std::cout << best << std::endl;
    }
}