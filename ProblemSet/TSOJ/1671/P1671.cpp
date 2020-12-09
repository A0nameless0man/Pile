#include <iostream>

long long qpow(long long b, long long n)
{
    long long a = 1;
    while(n)
    {
        if(n % 2 == 1)
        {
            a *= b;
        }
        b *= b;
        n /= 2;
    }
    return a;
}

long long getDis(long long k, long long x, long long y)
{
     static int table[3][3] = { { 0, 1, 2 },
                                     { 5, 4, 3 },
                                     { 6, 7, 8 } };
    if(k == 1)
    {
        return table[x][y];
    }
    long long pow3   = qpow(3, k - 1);
    long long xd     = x / pow3;
    long long yd     = y / pow3;
    long long xm     = x % pow3;
    long long ym     = y % pow3;
    long long offset = table[xd][yd] * pow3 * pow3;
    if(xd == 1)
    {
        ym = pow3 - ym - 1;
    }
    if(yd == 1)
    {
        xm = pow3 - xm - 1;
    }
    return getDis(k - 1, xm, ym) + offset;
}

int main(void)
{
    long long k;
    while(std::cin >> k)
    {
        // long long pow3 = qpow(3, k);
        // for(long long i = 0; i < pow3; ++i)
        // {
        //     for(long long j = 0; j < pow3; ++j)
        //     {
        //         std::cout << getDis(k, j, pow3 - i - 1)
        //                   << "\t";
        //     }
        //     std::cout << std::endl;
        // }
        long long x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << std::abs(getDis(k, x1, y1)
                              - getDis(k, x2, y2))
                  << std::endl;
    }
}