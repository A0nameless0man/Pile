#include <iostream>
#include <map>
#include <vector>
using NextX = std::map<unsigned long long, unsigned long long>;
int main(void)
{
    unsigned long long q;
    std::cin >> q;
    while(q--)
    {
        int n;
        std::cin >> n;
        std::vector<unsigned long long> raw;
        std::vector<unsigned long long> next;  // next[l] is the number of r that raw[l:r) is leagel
        std::vector<NextX>              nextX;
        std::vector<unsigned long long> count;
        count.resize(n + 1);
        next.resize(n + 1);
        nextX.resize(n + 1);
        // raw.clear();
        for(unsigned long long i = 0; i < n; i++)
        {
            unsigned long long buf;
            std::cin >> buf;
            raw.push_back(buf);
        }
        unsigned long long sum = 0;
        {
            // unsigned long long i = n;
            // count.clear();
            // next.clear();
            // nextX.clear();

            // while(i--)
            for(int i = n - 1; i >= 0; i--)
            {
                if(i < n - 1 && raw[i] == raw[i + 1])
                {
                    next[i] = i + 2;
                }
                else
                {
                    next[i] = (nextX[i + 1].find(raw[i]) != nextX[i + 1].end())
                                ? ((nextX[i + 1][raw[i]]) + 1)
                                : -1;
                }
                if(next[i] != -1)
                {
                    std::swap(nextX[i], nextX[next[i]]);
                    nextX[i][raw[next[i]]] = next[i];
                    count[i]               = 1 + count[next[i]];
                    sum += count[i];
                }
                else
                {
                    count[i] = 0;
                }
            }
        }
        // if(n==300000&&raw[0]==300000)
        //{
        // for( unsigned long long  i = 0 ;i<n;i++)std::cout<<next[i]<<" ";std::cout<<std::endl;
        // for( unsigned long long  i = 0 ;i<n;i++)std::cout<<count[i]<<" ";std::cout<<std::endl;
        //}
        // for( unsigned long long  i = 0 ;i<n;i++)sum+=count[i];
        std::cout << sum << std::endl;
    }
}