#include <iostream>
#include <vector>

struct S
{
    long long a, b;
};
/*
Time: 2020-01-23 11:32:05
Describe: any profit from k cnt be splited arbitrarily
Statue: ACCEPTED
*/
bool possible(long long k, const S &s, const S &b)
{
    // after k day
    // at least a1*k+a2*k;
    // extra : 0+1+...+(k-1)
    S cur = S { s.a * k, s.b * k };
    k     = (k) * (k + 1) / 2;
    if((cur.a + cur.b + k) >= (b.a + b.b) && (b.b - cur.b) <= k && (b.a - cur.a) <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool judge(long long k, const std::vector<S> &vec, const S s)
{
    for(const auto &b: vec)
    {
        if(possible(k, s, b))
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    S              a;
    int            n;
    std::vector<S> vec;
    while(std::cin >> a.a >> a.b >> n)
    {
        vec.clear();
        S b;
        for(int i = 0; i < n; ++i)
        {
            std::cin >> b.a >> b.b;
            vec.push_back(b);
        }
        long long l = 0;
        long long r = 2e5 + 7;
        while(l < r)
        {
            long long mid = (l + r) / 2;  //(]
            if(judge(mid, vec, a))
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        std::cout << l << std::endl;
    }
}
/*
5
1 2 3 4 5
10
1 : 1 2 3 4 4+0 0 0 0 1
2 : 1 2 3 3 4+0 0 0 1 1
3
4
5
1 5
2 5
3 5
4 5
1 4 5
2 4 5
3 4 5
1 3 4 5
2 3 4 5
1 2 3 4 5

1 2 3 3 3 = 12
0 0 0 1 2 = 3
*/