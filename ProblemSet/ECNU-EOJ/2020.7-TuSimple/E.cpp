#include <algorithm>
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>

void solve(std::vector<std::tuple<long long, long long>> &vec,
           long long                                      curpos,
           long long                                      curvel = 1,
           bool                                           order  = true)
{
    if(curpos == vec.size())
    {
        std::cout << curvel << '\n';
    }
    else if(order)
    {
        for(long long i = 0; i <= std::get<0>(vec[curpos]); ++i)
        {
            solve(vec, curpos + 1, curvel, (i ^ order) & 1);
            curvel *= std::get<1>(vec[curpos]);
        }
    }
    else
    {
        for(long long i = 0; i < std::get<0>(vec[curpos]); ++i)
        {
            curvel *= std::get<1>(vec[curpos]);
        }

        for(long long i = std::get<0>(vec[curpos]); ~i; --i)
        {
            solve(vec, curpos + 1, curvel, (i ^ order) & 1);
            curvel /= std::get<1>(vec[curpos]);
        }
    }
}

int main(void)
{
    int n;
    while(std::cin >> n)
    {
        std::vector<std::tuple<long long, long long>> vec;
        for(int i = 0; i < n; ++i)
        {
            int p, k;
            std::cin >> p >> k;
            vec.push_back(std::make_tuple(k, p));
        }
        // std::sort(vec.rbegin(), vec.rend());
#ifdef DEBUG
        for(auto e: vec)
        {
            std::cout << std::get<1>(e) << "^" << std::get<0>(e) << std::endl;
        }
#endif  // DEBUG
        {
            //             long long count = 1;
            //             for(auto &e: vec)
            //             {
            //                 count *= std::get<0>(e);
            //             }
            // #ifdef DEBUG
            //             std::cout << count << std::endl;
            // #endif  // DEBUG

        } {
            solve(vec, 0);
        }
    }
}