#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<long long>> d, c, g1, g2;
long long                           n;
long long                           mainDiagonal;
std::vector<long long>              subDiagonals;
const long long                     MOD = 998244353;
static void                         ini(std::vector<std::vector<long long>> &vec)
{
    vec.clear();
    vec.resize(n);
    for(auto &r: vec)
    {
        r.resize(n);
    }
}

long long contributionOfEdge(long long i, long long j)
{
    long long parta, partb, partc;
    if(c[i][i] == 0 || c[j][j] == 0)
    {
        return 0;
    }
    else
    {
        parta = mainDiagonal / (c[i][i] * (j != n - 1 ? c[j][j] : 1));
    }
    if(j != n - 1)
    {
        partc = subDiagonals[j] / c[j][j];
    }
    else
    {
        partc = 0;
    }
    if(i != n - 1)
    {
        partb = subDiagonals[i] / c[i][i];
    }
    else
    {
        partb = 0;
    }
    return -parta + partb + partc;
}

int main(void)
{
    while(std::cin >> n)
    {
        // ini(a);
        ini(d);
        ini(c);
        ini(g1);
        ini(g2);
        for(long long i = 0; i < n; ++i)
        {
            std::string buf;
            std::cin >> buf;
            for(long long j = 0; j < n; ++j)
            {
                g1[i][j] = buf[j] - '0';
            }
        }
        for(long long i = 0; i < n; ++i)
        {
            std::string buf;
            std::cin >> buf;
            for(long long j = 0; j < n; ++j)
            {
                g2[i][j] = buf[j] - '0';
            }
        }
        for(long long i = 0; i < n; ++i)
        {
            // long long degree = 0;
            for(long long j = 0; j < n; ++j)
            {
                d[i][i] += g1[i][j];
                //+g2[j][i];
            }
        }
        for(long long i = 0; i < n; ++i)
        {
            // long long degree = 0;
            for(long long j = 0; j < n; ++j)
            {
                c[i][j] = d[i][j] - g1[i][j];
            }
        }
        mainDiagonal = 1;
        for(long long i = 0; i < n - 1; ++i)
        {
            mainDiagonal *= c[i][i];
        }
        for(long long i = 0; i < n - 1; ++i)
        {
            subDiagonals.push_back(1);
            for(long long j = 0; j < n - 1; ++j)
            {
                subDiagonals[i] *= c[j][(2 * i - j + n - 1) % (n - 1)];
            }
        }
        long long sum = 0;
        for(long long i = 0; i < n; ++i)
        {
            for(long long j = 0; j < n; ++j)
            {
                sum += contributionOfEdge(i, j);
                sum %= MOD;
            }
        }
        std::cout << sum << std::endl;
    }
}
