#pragma once
#include "BigInt.h"
namespace RatNum
{
class RationalNumber
{
public:
    RationalNumber();
    ~RationalNumber();
    RationalNumber operator+(const RationalNumber &b) const;
    RationalNumber operator-(const RationalNumber &b) const;
    RationalNumber operator*(const RationalNumber &b) const;
    RationalNumber operator/(const RationalNumber &b) const;

private:
    bit::BigInt molecule, denominator;
};

RationalNumber::RationalNumber(): molecule(bit::DEC, 0), denominator(bit::DEC, 0) {}

RationalNumber::~RationalNumber() {}
inline RationalNumber RationalNumber::operator+(const RationalNumber &b) const
{
    return RationalNumber();
}
inline RationalNumber RationalNumber::operator-(const RationalNumber &b) const
{
    return RationalNumber();
}
inline RationalNumber RationalNumber::operator*(const RationalNumber &b) const
{
    return RationalNumber();
}
inline RationalNumber RationalNumber::operator/(const RationalNumber &b) const
{
    return RationalNumber();
}
}  // namespace RatNum