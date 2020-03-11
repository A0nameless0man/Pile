#include <iostream>
#include <utility>
#include <vector>
/*
Time: 2020-03-08 14:37:58
Describe: mul det to get sign,overflowed int
Statue: Accepted
*/
struct P
{
    int x, y;
};
P operator-(const P &lop, const P &rop)
{
    return P { lop.x - rop.x, lop.y - rop.y };
}

bool operator<(const P &lop, const P &rop)
{
    if(lop.x == rop.x)
    {
        return lop.y < rop.y;
    }
    else
    {
        return lop.x < rop.x;
    }
}

const long long c = 1;

int det(const P &lop, const P &rop)
{
    return lop.x * rop.y - lop.y * rop.x;
}

int main(void)
{
    int m, n;
    while(std::cin >> n)
    {
        std::vector<std::pair<P, P>> Lines;
        for(int i = 0; i < n; ++i)
        {
            P bufa, bufb;
            std::cin >> bufa.x >> bufa.y >> bufb.x >> bufb.y;
            Lines.push_back(std::make_pair(bufa, bufb));
        }
        std::cin >> m;
        for(int i = 0; i < m; ++i)
        {
            P   bufa, bufb;
            int cnt = 0;
            std::cin >> bufa.x >> bufa.y >> bufb.x >> bufb.y;
            for(const auto &line: Lines)
            {
                P va = bufa - line.first;
                P vb = bufb - line.first;
                P vl = line.second - line.first;
                // std::cout<<det<<(va,vl)<<":"<<det(vb,vl)
                if(c*det(va, vl) * det(vb, vl) < 0)
                {
                    cnt++;
                }
            }
            if(cnt & 1)
            {
                std::cout << "different\n";
            }
            else
            {
                std::cout << "same\n";
            }
        }
    }
}