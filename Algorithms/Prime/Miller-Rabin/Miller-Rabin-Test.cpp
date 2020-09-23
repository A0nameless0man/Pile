// #include <bit>
#include <iostream>

namespace MRT
{
using LL             = long long;
LL intMagicNumbers[] = { 2, 7, 61 };
LL LLMagicNumbers[]  = { 2,      325,     9375,      28178,
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

bool intMRT(int n)
{
    return MRT(static_cast<LL>(n), intMagicNumbers);
}
// bool LLMRT(LL n)
// {
//     return MRT(n, LLMagicNumbers);
// }
}  // namespace MRT

int main(void)
{
    MRT::LL n;
    int     count = 0;
    while(std::cin >> n)
    {
        for(MRT::LL i = 1; i < n; ++i)
        {
            int ans = MRT::intMRT(i);
            //   + 2 * MRT::LLMRT(static_cast<MRT::LL>(i));
            if(ans == 1)
            {
                std::cout << i << std::endl;
                ++count;
            }
            // else if(ans != 0)
            // {
            //     std::cout << "ERROR :\nn =>" << i
            //               << "\nans=>" << ans <<
            //               std::endl;
            // }
            // std::cout << i << " " << MRT::intMRT(i) << "
            // "
            //           <<
            //           MRT::LLMRT(static_cast<MRT::LL>(i))
            //           << std::endl;
        }
    }
    std::cout << count << std::endl;
}

/*
Time: 2020-09-21 21:48:12
Describe: checked all number in 0 ~ 1e7 in 2.03 sec
Statue: DONE
*/