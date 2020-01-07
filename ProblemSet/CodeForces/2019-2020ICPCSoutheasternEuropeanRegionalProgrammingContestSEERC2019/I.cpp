#include <algorithm>
#include <iostream>
#include <set>
//#include<vector>
const int MAX_N = 1007;
const int INF   = 0x3fffffff;
// int a[MAX_N], delA[MAX_N], b[MAX_N], delB[MAX_N];
std::multiset<int> a, b;
int                main(void)
{
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int buffer;
        std::cin >> buffer;
        a.insert(buffer);
        // std::cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        int buffer;
        std::cin >> buffer;
        b.insert(buffer);
        // std::cin >> b[i];
        // delA[i] = 0;
        // delB[i] = 0;
    }
    for(int i = 1; i < n; i++)
    {
        {
            int bestP     = -1;
            int minMinABS = INF;
            for(auto p: a)
            {
                int low    = *b.lower_bound(p);
                int upper  = *b.upper_bound(p);
                int minAbs = std::min(std::abs(low - p), std::abs(upper - p));
                if(minAbs < minMinABS)
                {
                    minMinABS = minAbs;
                    bestP     = p;
                }
            }
            // std::cout<<"Alice:"<<bestP<<std::endl;
            a.erase(a.find(bestP));
            // std::cout << "AfterAlice:\nminMinABS:"<<minMinABS<<"\n";
        }  // Alice
        // for (int i = 0; i < n; i++)
        // {
        //     std::cout << a[i] << "\t" << delA[i] << "\t" << b[i] << "\t" << delB[i] << std::endl;
        // }
        {
            int bestP     = -1;
            int maxMinAbs = -INF;
            for(auto p: b)
            {
                int lower  = *a.lower_bound(p);
                int upper  = *a.upper_bound(p);
                int minAbs = std::min(std::abs(p - upper), std::abs(p - lower));
                if(minAbs > maxMinAbs)
                {
                    maxMinAbs = minAbs;
                    bestP     = p;
                }
                // std::cout<<p<<"\t"<<lower<<"\t"<<upper<<"\t"<<maxMaxAbs<<"\t"<<maxAbs<<std::endl;
            }
            // std::cout<<"Bob:"<<bestP<<std::endl;
            b.erase(b.find(bestP));
            // delB[bestPos] = 1;
            // std::cout << "AfterBob:\nmaxMaxAbs:"<<maxMaxAbs<<"\n";
        }  // Bob
        // for (int i = 0; i < n; i++)
        // {
        //     std::cout << a[i] << "\t" << delA[i] << "\t" << b[i] << "\t" << delB[i] << std::endl;
        // }
    }
    std::cout << std::abs(*a.begin() - *b.begin()) << std::endl;
    return 0;
}