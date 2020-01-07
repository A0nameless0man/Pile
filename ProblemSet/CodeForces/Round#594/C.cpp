#include <iostream>
#include <queue>
#include <set>
#include <vector>
struct P
{
    size_t data;
    size_t id;
};
bool operator<(const P &a, const P &b)
{
    return a.data < b.data;
}
int main(void)
{
    std::vector<size_t> time;
    std::vector<size_t> end;
    size_t              n, p;
    std::cin >> n >> p;
    time.resize(n);
    end.resize(n);
    for(size_t i = 0; i < n; i++)
    {
        std::cin >> time[i];
    }
    std::priority_queue<P, std::vector<P>, std::greater<P>> next, waiting;  // que;
    // std::queue<size_t> que;
    std::queue<P>    que;  // que infront tank
    std::set<size_t> emptySeat;
    size_t           curTime = 0;
    size_t           queTime = 0;  // when the gay at front of que start to take water
    for(size_t i = 0; i < n; i++)
    {
        next.push({ time[i], i });
    }
    while(!next.empty() || !waiting.empty() || !que.empty())
    {
        if(!next.empty() && next.top().data < queTime + p)
        // curTime// what is next event?
        {
            // next event is next.top()stands;
            P n     = next.top();
            curTime = n.data;
            if(que.empty() || n.id < *emptySeat.begin())
            {
                // he joined que
                if(que.empty())
                    queTime = curTime;
                que.push(n);
                emptySeat.insert(n.id);
            }
            else
            {
                // he waiting;
                waiting.push({ n.id, n.id });
            }
            next.pop();
        }
        else
        {
            // next is some one return to seat;
            curTime = queTime + p;
            P n     = que.front();
            que.pop();
            emptySeat.erase(n.id);
            if(!waiting.empty() && (emptySeat.empty() || (waiting.top().data < *emptySeat.begin())))
            {
                // some one stand up now;
            }
            end[n.id] = queTime + p;
            queTime += p;
        }
    }
}