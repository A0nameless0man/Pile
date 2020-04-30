#include <iostream>
#include <utility>
#include <vector>

namespace BigInt
{
using SizeType = unsigned long;
template <SizeType Power, typename Digt>
class Base_BigInt
{
public:
    template <size_t _Power>
    class Pow
    {
    public:
        static const Digt res = 10 * Pow<_Power - 1>::res;
    };
    template <>
    class Pow<0>
    {
    public:
        static const Digt res = 1;
    };
    static const Digt BASE = Pow<Power>::res;

    using DigContiner = std::vector<Digt>;
    using DigIter     = DigContiner::iterator;
    using DigRang     = std::pair<DigIter, DigIter>;

    DigRang slice(SizeType from, SizeType to);

    Base_BigInt(): _sign(true), _reveres_digts(1, 0) {}
    Base_BigInt(const long long &ll);

private:
    std::vector<Digt> _reverse_digts;
    bool              _sign;
};

template <SizeType Power, typename Digt>
BigInt<Power, Digt> operator+(const BigInt<Power, Digt>::DigRang &lop,
                              const BigInt<Power, Digt>::DigRang &rop);

using BigInt = Base_BigInt<8, long long>;

template <size_t Power, typename Digt, class CharT, class Traits = std::char_traits<CharT> >
std::basic_istream<CharT, Traits> &operator>>(std::basic_istream<CharT, Traits> &is,
                                              const Base_BigInt<Power, Digt> &   op_bi)
{
    return is;
}
template <size_t Power, typename Digt, class CharT, class Traits = std::char_traits<CharT> >
std::basic_ostream<CharT, Traits> &operator<<(std::basic_ostream<CharT, Traits> &os,
                                              const Base_BigInt<Power, Digt> &   op_bi)
{
    return os;
}
}  // namespace BigInt