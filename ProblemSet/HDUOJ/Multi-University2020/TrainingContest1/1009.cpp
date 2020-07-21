#include <algorithm>
#include <cstdio>
// #include <stack>
#include <deque>
#include <tuple>

#ifdef DEBUG
#    include <iostream>
#endif  // DEBUG
using LL = long long;

int main(void)
{
    int T;
    while(scanf("%d", &T) != EOF)
    {
        for(int t = 0; t < T; ++t)
        {
            int                                  n;
            std::vector<std::tuple<LL, LL>>      rawvec;
            std::vector<std::tuple<LL, LL, int>> vec;
            if(scanf("%d", &n) == EOF)
            {
                return 1;
            }
            for(int i = 0; i < n; ++i)
            {
                LL p, a;
                if(scanf("%lld%lld", &p, &a) == EOF)
                {
                    return 2;
                }
                rawvec.push_back(std::make_tuple(a, p));
            }
            std::sort(rawvec.begin(), rawvec.end());
            {
                auto last = rawvec[0];
                int  cnt  = 0;
                for(size_t i = 0; i < rawvec.size(); ++i)
                {
                    if(last == rawvec[i])
                    {
                        ++cnt;
                    }
                    else
                    {
                        vec.push_back(std::make_tuple(std::get<0>(last), std::get<1>(last), cnt));
                        last = rawvec[i];
                        cnt  = 1;
                    }
                }
                vec.push_back(std::make_tuple(std::get<0>(last), std::get<1>(last), cnt));
            }
            {
                // std::stack<int> stc;
                std::deque<int> que;
                // LL              lastxp = -1, lastxa = 0;
                for(int i = 0; static_cast<size_t>(i) < vec.size(); ++i)
                {
                    while(que.size() > 1)
                    {
                        int last   = que[que.size() - 1];
                        int llast  = que[que.size() - 2];
                        LL  curxp  = std::get<1>(vec[i]) - std::get<1>(vec[last]);
                        LL  curxa  = std::get<0>(vec[last]) - std::get<0>(vec[i]);
                        LL  lastxp = std::get<1>(vec[last]) - std::get<1>(vec[llast]);
                        LL  lastxa = std::get<0>(vec[llast]) - std::get<0>(vec[last]);
                        if(curxa == 0 || curxp * lastxa <= curxa * lastxp)
                        {
                            que.pop_back();
                        }
                        else
                        {
                            break;
                        }
                    }
                    que.push_back(i);
                }
#ifdef DEBUG
                for(size_t i = 0; i < que.size(); ++i)
                {
                    std::cout << std::get<0>(vec[que[i]]) << "," << std::get<1>(vec[que[i]]) << " ";
                }
                std::cout << std::endl;
#endif  // DEBUG
                {
                    int    ans = 0;
                    size_t i   = 0;
                    while(i < que.size() - 1)
                    {
                        int last   = que[i];
                        int llast  = que[i + 1];
                        LL  lastxp = std::get<1>(vec[last]) - std::get<1>(vec[llast]);
                        LL  lastxa = std::get<0>(vec[llast]) - std::get<0>(vec[last]);
                        if(lastxa == 0 || lastxp * lastxa <= 0)
                        {
                            ++i;
                        }
                        else
                        {
                            break;
                        }
                    }
                    for(; i < que.size(); ++i)
                    {
                        if(std::get<2>(vec[que[i]]) == 1)
                        {

#ifdef DEBUG
                            // for(size_t i = 0; i < que.size(); ++i)
                            {
                                std::cout << std::get<0>(vec[que[i]]) << ","
                                          << std::get<1>(vec[que[i]]) << " ";
                            }
                            std::cout << std::endl;
#endif  // DEBUG
                            ans += std::get<2>(vec[que[i]]);
                        }
                    }
                    // std::cout << std::endl;
                    printf("%d\n", ans);
                }
            }
        }
    }
}
/*
6
3
1 3
2 2
3 1
3
1 1
2 3
3 2
3
1 2
1 3
1 4
3
2 1
3 1
4 1
4
2 1
3 1
4 1
1 5
4
10 1
5 2
6 2
1 3
3
3
1 2
1 3
1 4
3
2 1
3 1
4 1
4
2 1
3 1
4 1
1 5

*/