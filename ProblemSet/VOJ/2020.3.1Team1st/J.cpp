#include <cstdio>
#include <map>
#include <set>
#include <vector>

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

int main(void)
{
    int N;
    while(scanf("%d", &N) != EOF)
    {
        std::vector<P>             vec;
        std::map<P, std::set<int>> map;
        int                        ans       = 0;
        // const int                  threshold = (N + 1) / 2;
        for(int i = 0; i < N; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            vec.push_back(P { x, y });
        }
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                auto &set = map[vec[i] - vec[j]];
                set.insert(i);
                set.insert(j);
            }
        }
        for(const auto &it: map)
        {
            if(it.second.size()==N)
            {
                ans += 2;
                // printf("Good:");
            }
            // printf("(%d,%d):%d\n", it.first.x, it.first.y, it.second);
        }
        printf("%d\n", ans);
    }
}