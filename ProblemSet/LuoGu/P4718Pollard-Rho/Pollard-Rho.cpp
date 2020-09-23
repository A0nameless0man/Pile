#include <cstdlib>  // abs
#include <iostream>
// #include"../Miller-Rabin/Miller-Rabin-Test"

namespace MRT
{
using LL             = long long;
LL intMagicNumbers[] = { 2, 7, 61 };
LL LLMagicNumbers[]  = { 2,      325,     9375,      28178,
                        450775, 9780504, 1795265022 };

LL quickMultiply(LL a, LL b, LL mod)
{
    LL ans = 0;
    while(b)
    {
        if(b & 1)
        {
            ans = (ans + a) % mod;
        }
        a <<= 1;
        b >>= 1;
    }
    return ans;
    // return (a * b
    //         - static_cast<LL>(static_cast<long double>(a)
    //                           * b / mod)
    //             * mod
    //         + mod)
    //        % mod;
}

LL qpow(LL a, LL b, LL mod)
{
    if(mod > 1e9)
    {
        LL result = 1;
        while(b)
        {
            if(b & 1)
            {
                // result = result * a % mod;
                result = quickMultiply(result, a, mod);
            }
            b >>= 1;
            // a = a * a % mod;
            a = quickMultiply(a, a, mod);
        }
        return result;
    }
    else
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
}

bool singleMRT(LL n, int s, LL d, LL a)
// 对于 a , n是否满足2次探测。
{
    a = qpow(a, d, n);
    if(a == 1 || a == n - 1)
    {
        return true;
    }
    if(n > 1e9)
    {
        for(int i = 1; i < s; ++i)
        {  // cura = rawa^(2^i-1*d)
            // a = a * a % n;
            LL next = quickMultiply(a, a, n);
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
    }
    else
    {
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
        LL  d  = n1 / (1ll << s);
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
                std::cout << "Failed for " << n << " on "
                          << magicNumbers[i] << std::endl;
                std::cout << "s : " << s << std::endl;
                std::cout << "d : " << d << std::endl;
                std::cout << "n1 : " << n1 << std::endl;
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

LL quickMultiply(LL a, LL b, LL mod)
{
    // LL ans = 0;
    // while(b)
    // {
    //     if(b & 1)
    //     {
    //         ans = (ans + a) % mod;
    //     }
    //     a <<= 1;
    //     b >>= 1;
    // }
    // return ans;
    return (a * b
            - static_cast<LL>(static_cast<long double>(a)
                              * b / mod)
                * mod
            + mod)
           % mod;
}

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
    if(a < 1e9)
    {
        return (a * a + c) % n;
    }
    else
    {
        return (quickMultiply(a, a, n) + c) % n;
    }
}

LL PR(LL n, LL ans)
{
    // #ifdef DEBUG
    //     std::cerr << "[PR::PR] Solving : " << n <<
    //     std::endl;
    // #endif  // DEBUG
    if(!(n & 1))
    {
        return 2;
    }
    else if(MRT::intMRT(n))
    {
        return n;
    }
    else
    {
        // #ifdef DEBUG
        //         std::cerr << "[PR::PR] Not Prime : " << n
        //                   << std::endl;
        // #endif  // DEBUG
        LL c = 1;
        LL tg;  // temp gcd
        while(++c < 10)
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
                    // #ifdef DEBUG
                    //                     std::cerr <<
                    //                     "[PR::PR] Find "
                    //                     << tg
                    //                               << " :
                    //                               " << n
                    //                               <<
                    //                               std::endl;
                    // #endif  // DEBUG
                    if(tg > ans)
                    {
                        return PR(tg, ans);
                    }
                    else
                    {
                        return tg;
                    }
                    // return tg;
                }
                if(s >= m)
                {
                    y = x;
                    m <<= 1;
                }
            }
        }
        // std::cerr << "[PR::PR] fail for " << n <<
        // std::endl;
        return n;
    }
}

}  // namespace PR

// int main(void)
// {
//     PR::LL a;
//     while(std::cin >> a)
//     {
//         // std::cout << PR::gcd(a, b) << std::endl;
//         while(a != 1)
//         {
//             PR::LL f   = PR::PR(a);
//             PR::LL cnt = 0;
//             while(a % f == 0)
//             {
//                 a /= f;
//                 ++cnt;
//             }
//             std::cout << " " << f << "^" << cnt << " ";
//         }
//         std::cout << "\n";
//     }
// }

int main(void)
{
    int T;
    while(std::cin >> T)
    {
        for(int i = 0; i < T; ++i)
        {
            PR::LL n, f, ans;
            std::cin >> n;
            // ans = f = PR::PR(n);
            if(MRT::intMRT(n))
            {
                std::cout << "Prime\n";
            }
            else
            {
                ans = 0;
                while(n != 1)
                {
                    f = PR::PR(n, ans);
                    // #ifdef DEBUG
                    //                     std::cout <<
                    //                     "[main] Find " <<
                    //                     f
                    //                               << "
                    //                               for "
                    //                               << n <<
                    //                               "\n";
                    // #endif  // DEBUG
                    if(f > ans)
                    {
                        ans = f;
                    }
                    while(n % f == 0)
                    {
                        n /= f;
                    }
                }
                std::cout << ans << "\n";
            }
        }
    }
}
/*
Time: 2020-09-23 13:45:30
Describe: 
Statue: TLE
*/