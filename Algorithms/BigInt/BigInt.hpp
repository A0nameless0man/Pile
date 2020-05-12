// #pragma once
#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

/*
Time: 2020-04-30 20:58:29
Describe: 
Store Big int with low end forward to avoid align
Statue: DONE
*/

namespace BigInt
{
using SizeType = unsigned long;
template <typename Digt, SizeType _Power, SizeType Base>
class Pow
{
public:
    static const Digt res = Base * Pow<Digt, _Power - 1, Base>::res;
};
template <typename Digt, SizeType Base>
class Pow<Digt, static_cast<size_t>(0), Base>
{
public:
    static const Digt res = 1;
};

template <SizeType Power, typename Digt, SizeType Base>
class Base_BigInt
{
public:
    static const Digt BASE = Pow<Digt, Power, Base>::res;

    using DigContiner  = std::vector<Digt>;
    using DigIter      = typename DigContiner::iterator;
    using DigConstIter = typename DigContiner::const_iterator;
    using DigRang      = std::pair<DigIter, DigIter>;
    using DigConstRang = std::pair<DigConstIter, DigConstIter>;

    Base_BigInt(): _sign(true), _reverse_digts(1, 0) {}
    Base_BigInt(const DigContiner &d_c): _sign(true), _reverse_digts(d_c) {}
    Base_BigInt(DigContiner &&d_c): _sign(true), _reverse_digts(std::forward<DigContiner>(d_c)) {}
    Base_BigInt(const long long &ll)
    {
        /*
        Time: 2020-04-30 18:11:31
        Describe: Implient it
        Statue: TODO
        */
    }

    Base_BigInt<Power, Digt, Base> &setSign(bool sign)
    {
        _sign = sign;
        return *this;
    }

    Base_BigInt<Power, Digt, Base> &move(SizeType sign)
    {
        std::reverse(_reverse_digts.begin(), _reverse_digts.end());
        while(sign--)
        {
            _reverse_digts.push_back(0);
        }
        std::reverse(_reverse_digts.begin(), _reverse_digts.end());
        return *this;
    }

    bool getSign(void)
    {
        return _sign;
    }

    DigRang slice(SizeType from, SizeType to)
    {
        return std::make_pair(_reverse_digts.begin() + from, _reverse_digts.begin() + to);
    }
    DigRang slice(void)
    {
        return std::make_pair(_reverse_digts.begin(), _reverse_digts.end());
    }
    DigConstRang slice(SizeType from, SizeType to) const
    {
        return std::make_pair(_reverse_digts.begin() + from, _reverse_digts.begin() + to);
    }
    DigConstRang slice(void) const
    {
        return std::make_pair(_reverse_digts.begin(), _reverse_digts.end());
    }

    const Base_BigInt<Power, Digt, Base> &test(void) const
    {
        std::clog << _sign << std::endl;
        for(const auto &i: _reverse_digts)
        {
            std::clog << i << std::endl;
        }
        return *this;
    }

    Base_BigInt<Power, Digt, Base> operator+(const Base_BigInt<Power, Digt, Base> &rop) const
    {
        const auto &lop = *this;
        if(lop._sign ^ rop._sign)
        {
            auto tmp_ans = DigConstRangSub<Power, Digt, Base>(lop.slice(), rop.slice());
            if(!lop._sign)
            {
                tmp_ans._sign ^= 1;  // flip it;
            }
            return tmp_ans;
        }
        else
        {
            return DigConstRangAdd<Power, Digt, Base>(lop.slice(), rop.slice());
        }
    }
    Base_BigInt<Power, Digt, Base> operator-(const Base_BigInt<Power, Digt, Base> &rop) const
    {
        const auto &lop = *this;
        if(lop._sign ^ rop._sign)
        {
            auto tmp_ans  = DigConstRangAdd<Power, Digt, Base>(lop.slice(), rop.slice());
            tmp_ans._sign = lop._sign;  // flip it;
            return tmp_ans;
        }
        else
        {
            return DigConstRangSub<Power, Digt, Base>(lop.slice(), rop.slice());
        }
    }
    Base_BigInt<Power, Digt, Base> operator*(const Base_BigInt<Power, Digt, Base> &rop) const
    {
        const auto &lop = *this;

        return DigConstRangMul<Power, Digt, Base>(lop.slice(), rop.slice())
          .setSign(!(lop._sign ^ rop._sign));
    }

    template <class CharT, class Traits>
    friend std::basic_istream<CharT, Traits> &operator>>(std::basic_istream<CharT, Traits> &is,
                                                         Base_BigInt<Power, Digt, Base> &   op_bi)
    {
        op_bi._reverse_digts.clear();
        op_bi._sign = true;
        while(isblank(is.peek()) || isspace(is.peek()))
        {
            is.get();
        }
        if(is.peek() == '-')
        {
            is.get();
            op_bi._sign = false;
        }
        std::vector<CharT> buf;
        while(isdigit(is.peek()))
        {
            buf.push_back(is.get());
        }
        for(SizeType i = 0; i * Power < buf.size(); ++i)
        {
            Digt tmp_digt = 0;
            for(SizeType j = 0; j < Power; ++j)
            {
                SizeType cur = (i + 1) * Power - j - 1;
                if(cur < buf.size())
                {
                    tmp_digt *= Base;
                    tmp_digt += buf.rbegin()[cur] - '0';
                }
            }
            op_bi._reverse_digts.push_back(tmp_digt);
        }
        return is;
    }
    template <class CharT, class Traits>
    friend std::basic_ostream<CharT, Traits> &
    operator<<(std::basic_ostream<CharT, Traits> &os, const Base_BigInt<Power, Digt, Base> &op_bi)
    {
        auto it = op_bi._reverse_digts.rbegin();
        if(it != op_bi._reverse_digts.rend())
        {
            if(!op_bi._sign)
            {
                os << '-';
            }
            os << *(it);
        }
        while(++it != op_bi._reverse_digts.rend())
        {
            auto s = std::to_string(*it);
            for(SizeType i = 0; i < Power - s.length(); ++i)
            {
                os << '0';
            }
            os << s;
        }
        return os;
    }

private:
    bool              _sign;
    std::vector<Digt> _reverse_digts;
};

template <SizeType Power, typename Digt, SizeType Base>
bool DigConstRangCmp(const typename Base_BigInt<Power, Digt, Base>::DigConstRang &lop,
                     const typename Base_BigInt<Power, Digt, Base>::DigConstRang &rop)
{
    SizeType i = 0, j = 0;
    size_t   disl = std::distance(lop.first, lop.second);
    size_t   disr = std::distance(rop.first, rop.second);
    while((i < disl && j < disr) && lop.first[disl - i - 1] == rop.first[disr - j - 1])
    {
        ++i;
        ++j;
    }
    if(!(i < disl)
       || lop.first[disl - i - 1]
            < rop.first[disr - j - 1])  // if lop is shorter or has smaller first different digt
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <SizeType Power, typename Digt, SizeType Base>
Base_BigInt<Power, Digt, Base>
DigConstRangAdd(const typename Base_BigInt<Power, Digt, Base>::DigConstRang &lop,
                const typename Base_BigInt<Power, Digt, Base>::DigConstRang &rop)
{
    typename Base_BigInt<Power, Digt, Base>::DigContiner _tmp_ans;
    Digt                                                 _carry = 0;
    SizeType                                             i = 0, j = 0;
    size_t disl = std::distance(lop.first, lop.second);
    size_t disr = std::distance(rop.first, rop.second);
    for(; (i < disl || j < disr) || _carry != 0; ++i, ++j)
    {
        if(i < disl)
        {
            _carry += lop.first[i];
        }
        if(j < disr)
        {
            _carry += rop.first[j];
        }
        Digt _next_bit =
          (_carry + Base_BigInt<Power, Digt, Base>::BASE) % Base_BigInt<Power, Digt, Base>::BASE;
        _tmp_ans.push_back(_next_bit);
        if(_carry > 0)
        {
            _carry /= Base_BigInt<Power, Digt, Base>::BASE;
        }
        else
        {
            _carry = (_carry - Base_BigInt<Power, Digt, Base>::BASE + 1)
                     / Base_BigInt<Power, Digt, Base>::BASE;
        }
    }
    return Base_BigInt<Power, Digt, Base>(std::move(_tmp_ans));
}

template <SizeType Power, typename Digt, SizeType Base>
Base_BigInt<Power, Digt, Base>
DigConstRangSub(const typename Base_BigInt<Power, Digt, Base>::DigConstRang &lop,
                const typename Base_BigInt<Power, Digt, Base>::DigConstRang &rop)
{
    if(DigConstRangCmp<Power, Digt, Base>(rop, lop))
    {
        typename Base_BigInt<Power, Digt, Base>::DigContiner _tmp_ans;
        Digt                                                 _carry = 0;
        SizeType                                             i = 0, j = 0;
        size_t disl = std::distance(lop.first, lop.second);
        size_t disr = std::distance(rop.first, rop.second);
        for(; (i < disl || j < disr) || _carry != 0; ++i, ++j)
        {
            if(i < disl)
            {
                _carry += lop.first[i];
            }
            if(j < disr)
            {
                _carry -= rop.first[j];
            }
            Digt _next_bit = (_carry + Base_BigInt<Power, Digt, Base>::BASE)
                             % Base_BigInt<Power, Digt, Base>::BASE;
            _tmp_ans.push_back(_next_bit);
            if(_carry > 0)
            {
                _carry /= Base_BigInt<Power, Digt, Base>::BASE;
            }
            else
            {
                _carry = (_carry - Base_BigInt<Power, Digt, Base>::BASE + 1)
                         / Base_BigInt<Power, Digt, Base>::BASE;
            }
        }
        while(_tmp_ans.size() > 1 && *(_tmp_ans.rbegin()) == 0)
        {
            _tmp_ans.pop_back();
        }
        return Base_BigInt<Power, Digt, Base>(std::move(_tmp_ans));
    }
    else
    {
        Base_BigInt<Power, Digt, Base> ans = DigConstRangSub<Power, Digt, Base>(rop, lop);
        ans.setSign(false);
        return ans;
    }
}
template <SizeType Power, typename Digt, SizeType Base>
Base_BigInt<Power, Digt, Base>
DigConstRangMul(const typename Base_BigInt<Power, Digt, Base>::DigConstRang &lop,
                const typename Base_BigInt<Power, Digt, Base>::DigConstRang &rop)
{
    size_t disl = std::distance(lop.first, lop.second);
    size_t disr = std::distance(rop.first, rop.second);
    if(disl == 1 || disr == 1)
    {
        if(disl == 1)
        {
            if(*lop.first != 0)
            {
                Digt                                                 carry = 0;
                typename Base_BigInt<Power, Digt, Base>::DigContiner buffer;
                SizeType                                             i = 0;
                while(i < disr || carry != 0)
                {
                    if(i < disr)
                    {
                        carry += (rop.first[i] * lop.first[0]);
                    }
                    buffer.push_back(carry % Base_BigInt<Power, Digt, Base>::BASE);
                    carry /= Base_BigInt<Power, Digt, Base>::BASE;
                    ++i;
                }
                return Base_BigInt<Power, Digt, Base>(std::move(buffer));
            }
            else
            {
                typename Base_BigInt<Power, Digt, Base>::DigContiner buffer(1, 0);
                return Base_BigInt<Power, Digt, Base>(std::move(buffer));
            }
        }
        else
        {
            return DigConstRangMul<Power, Digt, Base>(rop, lop);
        }
    }
    else
    {
        /*
        Time: 2020-04-30 19:40:15
        Describe: let lop = A*BASE^n+B and rop = C*BASE^n +D
        lop*rop = A*C*BASE^(2*n)+(A*D+B*C)*BASE^n + BD
                = A*C*BASE^(2*n)+((A-B)*(C-D)+AC+BD)*BASE^n+BD
        
        NOTICE Smalle end first

        Statue: TOTEST
        */
        size_t                                                      dis = std::min(disl, disr);
        size_t                                                      n   = dis / 2;
        const typename Base_BigInt<Power, Digt, Base>::DigConstRang A   = { lop.first,
                                                                          lop.first + n };
        const typename Base_BigInt<Power, Digt, Base>::DigConstRang B   = { lop.first + n,
                                                                          lop.second };
        const typename Base_BigInt<Power, Digt, Base>::DigConstRang C   = { rop.first,
                                                                          rop.first + n };
        const typename Base_BigInt<Power, Digt, Base>::DigConstRang D   = { rop.first + n,
                                                                          rop.second };
        auto       X  = DigConstRangMul<Power, Digt, Base>(A, C);
        auto       Y  = DigConstRangMul<Power, Digt, Base>(B, D);
        const auto AB = DigConstRangSub<Power, Digt, Base>(A, B);
        const auto DC = DigConstRangSub<Power, Digt, Base>(D, C);
        auto       Z  = AB * DC;
        // std::clog << X << " " << Y << " " << Z << std::endl;
        Z = Z + X + Y;
        // std::clog << X << " " << Y << " " << Z << std::endl;
        Y.move(2 * n);
        Z.move(n);
        // std::clog << X << " " << Y << " " << Z << std::endl;
        return X + Y + Z;
    }
}
using BigInt = Base_BigInt<8, long long, 10>;

}  // namespace BigInt

#endif