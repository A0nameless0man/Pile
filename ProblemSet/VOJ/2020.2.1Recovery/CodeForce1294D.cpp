#include <cstdio>
#include <iostream>
#include <queue>

const int MAX_X = 4e5 + 7;
int       rec[MAX_X];
struct R
{
    int pos;
    int cnt;
};

bool operator<(const R &a, const R &b)
{
    if(a.cnt != b.cnt)
    {
        return a.cnt < b.cnt;
    }
    else
    {
        return a.pos < b.pos;
    }
}
bool operator>(const R &a, const R &b)
{
    return b < a;
}

  int main(void)
{
    int q, x;
    while(std::cin >> q >> x)
    {
        std::priority_queue<R, std::vector<R>, std::greater<R>> que;
        for(int i = 0; i <= x; ++i)
        {
            rec[i] = 0;
        }
        for(int i = 0; i < x; ++i)
        {
            que.push(R { i, 0 });
        }
        for(int i = 0; i < q; ++i)
        {
            int y;
            // std::cin >> y;
            scanf("%d", &y);
            ++rec[y % x];
            while(rec[que.top().pos]!=que.top().cnt)
            {
                int pos = que.top().pos;
                que.pop();
                que.push(R { pos, rec[pos] });
            }
            int ans = x * que.top().cnt + que.top().pos;
            printf("%d\n", ans);
            // std::cout << x * que.top().cnt + que.top().pos << std::endl;
        }
    }
}