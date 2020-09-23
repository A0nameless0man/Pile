#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>  // abs
#include <ctime>
#include <iostream>
// #include"../Miller-Rabin/Miller-Rabin-Test"
#define asc(i, s, e) for((i) = (s); (i) <= (e); ++(i))

namespace MRT
{
using LL             = long long;
LL intMagicNumbers[] = { 2, 7, 61 };
// LL intMagicNumbers[] = { 2, 3, 5, 7, 11 };
LL LLMagicNumbers[] = { 2,      325,     9375,      28178,
                        450775, 9780504, 1795265022 };

LL qpow(LL a, LL b, LL mod)
{
    LL result = 1;
    while(b)
    {
        if(b & 1)
        {
            result = result * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return result;
}

bool singleMRT(LL n, int s, LL d, LL a)
// 对于 a , n是否满足2次探测。
{
    a = qpow(a, d, n);
    if(a == 1 || a == n - 1)
    {
        return true;
    }
    for(int i = 1; i < s; ++i)
    {  // cura = rawa^(2^i-1*d)
        LL next = a * a % n;
        if(next == n - 1)
        {
            return true;
        }
        else if(next == 1 && a != n - 1)
        {
            return false;
        }
        a = next;
    }
    if(a == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int countr_zero(LL n)
{
    for(int i = 0; i < 64; ++i)
    {
        if(n & 1)
        {
            return i;
        }
        n >>= 1;
    }
    return 64;
}

// template<LL MagicNumber[LEN]>
template <LL LEN>
bool MRT(LL n, LL (&magicNumbers)[LEN])
{
    if(n == 1 || n == 0)
    {
        return false;
    }
    else if(n == 2)
    {
        return true;
    }
    else
    {
        LL  n1 = n - 1;
        int s  = countr_zero(n1);
        // LL  d  = n1 / (1ll << s);
        LL d = n1 >> s;
        for(LL i = 0; i < LEN; ++i)
        {
            if(n == magicNumbers[i])
            {
                // return true;
                continue;
            }
            else if(n % magicNumbers[i] == 0)
            {
                return false;
            }
            else if(magicNumbers[i] % n == 0)
            {
                continue;
            }
            else if(!singleMRT(n, s, d, magicNumbers[i]))
            {
#ifdef DEBUG
                std::cerr << "Failed for " << n << " on "
                          << magicNumbers[i] << std::endl;
                std::cerr << "s : " << s << std::endl;
                std::cerr << "d : " << d << std::endl;
                std::cerr << "n1 : " << n1 << std::endl;
#endif  // DEBUG
                return false;
            }
        }
        return true;
    }
}

bool intMRT(LL n)
{
    return MRT(n, intMagicNumbers);
}
// bool LLMRT(LL n)
// {
//     return MRT(n, LLMagicNumbers);
// }
}  // namespace MRT

namespace PR
{
using LL = long long;

// LL quickMultiply(LL a, LL b, LL mod)
// {
//     LL ans = 0;
//     while(b)
//     {
//         if(b & 1)
//         {
//             ans = (ans + a) % mod;
//         }
//         a <<= 1;
//         b >>= 1;
//     }
//     return ans;
// }

LL gcd(LL a, LL b)
{
    // LL result;
    while(b)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

LL next(LL a, LL c, LL n)
{
    return (a * a + c) % n;
    // return (quickMultiply(a, a, n) + c) % n;
}

LL PR(LL n)
{
#ifdef DEBUG
    std::cerr << "[PR::PR] Solving : " << n << std::endl;
#endif  // DEBUG
    if(!(n & 1))
    {
        return 2;
    }
    else if(MRT::intMRT(n))
    {
#ifdef DEBUG
        std::cerr << "[PR::PR] Is Prime : " << n
                  << std::endl;
#endif  // DEBUG
        return n;
    }
    else
    {
#ifdef DEBUG
        std::cerr << "[PR::PR] Not Prime : " << n
                  << std::endl;
#endif  // DEBUG
        LL c = 1;
        LL tg;  // temp gcd
        while(++c)
        {
            LL x = 2;
            LL y = 2;
            LL s = 0;  // LL step = 0;
            LL m = 1;  // LL multiplier = 1;
            while(++s)
            {
                x = next(x, c, n);
                y = next(next(y, c, n), c, n);
                if(x == y || 0)
                {
                    break;
                }
                tg = gcd(std::abs(x - y), n);
                if(tg > 1)
                {
#ifdef DEBUG
                    std::cerr << "[PR::PR] Find " << tg
                              << " : " << n << std::endl;
#endif  // DEBUG
                    return PR(tg);
                    // return tg;
                }
                if(s >= m)
                {
                    y = x;
                    m <<= 1;
                }
            }
        }
#ifdef DEBUG
        std::cerr << "[PR::PR] fail for " << n << std::endl;
#endif  // DEBUG

        return n;
    }
}

}  // namespace PR

using LL = long long;

LL calc_xi(LL n)
{
    LL xi      = 0;
    LL zerocnt = MRT::countr_zero(n);
    if(zerocnt)
    {
        ++xi;
        n >>= zerocnt;
    }
    while(n != 1)
    {
        LL f = PR::PR(n);
        while(n % f == 0)
        {
            n /= f;
            ++xi;
        }
    }
    return xi;
}

int main()
{
    int T;
    while(std::cin >> T)
    {
        for(int t = 0; t < T; ++t)
        {
            int n;
            std::cin >> n;
            LL x = 0;
            for(int i = 0; i < n; ++i)
            {
                LL k;
                std::cin >> k;
                x ^= calc_xi(k);
            }
#ifdef DEBUG
            std::cout << x << std::endl;
#endif  // DEBUG
            if(x == 0)
            {
                std::cout << "L" << std::endl;
            }
            else
            {
                std::cout << "W" << std::endl;
            }
        }
    }
}