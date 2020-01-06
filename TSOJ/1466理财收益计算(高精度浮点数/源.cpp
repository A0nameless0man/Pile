#include <stdio.h>
#include <algorithm>
#include <ctype.h>
#include <fstream>   //file
#include <iostream>  //stream
#include <math.h>
#include <sstream>  //stringstream
#include <string.h>
#include <string>
// STL
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
using LL        = long long;
using ULL       = unsigned long long;
const int MAX_N = 10007;
int       n, m, a, b, j, k;
#define Check(a) (std::cout << #a << ':' << (a) << std::endl);
namespace bit
{
using Pos        = short;
using Digt       = int;
using singleDigt = short;
using IntStore   = std::vector<singleDigt>;
const Pos BIN    = 2;
const Pos OCT    = 8;
const Pos DEC    = 10;
const Pos HXE    = 16;
char      itoc(int);
int       ctoi(char);
class BigInt
{
public:
    BigInt(Pos pos, long long def);
    ~BigInt();
    std::string          string(void) const;
    BigInt               operator+(const BigInt &b) const;
    BigInt               operator+=(const BigInt &b);
    BigInt               operator-(const BigInt &b) const;
    BigInt               operator*(const singleDigt &) const;
    BigInt               operator*(const BigInt &b) const;
    BigInt               operator/(const BigInt &b) const;
    bool                 operator<(const BigInt &b) const;
    bool                 operator==(const BigInt &b) const;
    friend std::ostream &operator<<(std::ostream &os, const BigInt &in);
    friend std::istream &operator>>(std::istream &os, BigInt &in);

private:
    IntStore    ReverseInt;
    Pos         pos;
    bool        postive;
    Digt        PositionOfDot;
    BigInt      move(Digt);
    bool        absSmaller(const BigInt &) const;
    inline void correctPostive(void);
    inline bool isZero(void) const;
};
BigInt::BigInt(Pos pos, long long def = 0): pos(pos)
{
    int i = 0;
    if(def == 0)
    {
        postive = false;
    }
    else
    {
        if(def > 0)
        {
            postive = true;
        }
        else
        {
            postive = false;
            def     = -def;
        }
        Digt i = 0;
        while(def != 0)
        {
            ReverseInt.push_back(def % pos);
            def /= pos;
            i++;
        }
    }
    PositionOfDot = 0;
}
BigInt::~BigInt()
{
    ReverseInt.clear();
}
std::string BigInt::string(void) const
{
    std::string ans;
    if(isZero())
        return "0";
    if(!postive)
    {
        ans.push_back('-');
    }
    if(PositionOfDot >= ReverseInt.size())
    {
        ans += ".";
        for(size_t i = 0; i < PositionOfDot - ReverseInt.size(); i++)
        {
            ans.push_back('0');
        }
        for(auto i = ReverseInt.rbegin(); i != ReverseInt.rend(); i++)
        {
            ans.push_back(itoc(*i));
        }
    }
    else
    {
        Digt j = ReverseInt.size() - PositionOfDot;
        for(auto i = ReverseInt.rbegin(); i != ReverseInt.rend(); i++, j--)
        {
            if(j == 0)
            {
                ans.push_back('.');
            }
            ans.push_back(itoc(*i));
        }
    }
    if(PositionOfDot != 0)
    {
        while(ans.back() == '0')
        {
            ans.pop_back();
        }
        if(ans.back() == '.')
        {
            ans.pop_back();
        }
    }
    return ans;
}
BigInt BigInt::operator+(const BigInt &b) const
{
    if(postive == b.postive)
    {
        BigInt ans(pos);
        Digt   i = 0;
        BigInt a(*this), b2(b);
        a.move(b.PositionOfDot), b2.move(PositionOfDot);
        int extra = 0;
        while(i < (Digt) a.ReverseInt.size() || i < (Digt) b2.ReverseInt.size() || extra != 0)
        {
            if(i < (Digt) a.ReverseInt.size())
            {
                extra += a.ReverseInt[i];
            }
            if(i < (Digt) b2.ReverseInt.size())
            {
                extra += b2.ReverseInt[i];
            }
            ans.ReverseInt.push_back(extra % (singleDigt) pos);
            extra /= (singleDigt) pos;
            i++;
        }
        ans.postive       = postive;
        ans.PositionOfDot = PositionOfDot + b.PositionOfDot;
        ans.correctPostive();
        return ans;
    }
    else
    {
        BigInt b2(b);
        b2.postive = !b2.postive;
        return *this - b2;
    }
}
BigInt BigInt::operator+=(const BigInt &b)
{
    *this = *this + b;
    return *this;
}
BigInt BigInt::operator-(const BigInt &b) const
{
    BigInt ans(pos);
    if(absSmaller(b))
    {
        ans         = b - *this;
        ans.postive = !ans.postive;
    }
    else
    {
        if(postive == b.postive)
        {
            Digt   i     = 0;
            int    extra = 0;
            BigInt a(*this), b2(b);
            a.move(b.PositionOfDot), b2.move(PositionOfDot);
            while(i < (Digt) a.ReverseInt.size() || i < (Digt) b2.ReverseInt.size() || extra != 0)
            {
                if(i < (Digt) a.ReverseInt.size())
                {
                    extra += a.ReverseInt[i];
                }
                if(i < (Digt) b2.ReverseInt.size())
                {
                    extra -= b2.ReverseInt[i];
                }
                ans.ReverseInt.push_back((extra % (singleDigt) pos + (singleDigt) pos) %
                                         (singleDigt) pos);
                extra = (extra - ans.ReverseInt.back()) / (singleDigt) pos;
                i++;
            }
            ans.postive       = postive;
            ans.PositionOfDot = PositionOfDot + b.PositionOfDot;
            return ans;
        }
        else
        {
            BigInt b2(b);
            b2.postive = !b2.postive;
            return *this + b2;
        }
    }
    ans.correctPostive();
    return ans;
}
BigInt BigInt::operator*(const singleDigt &b) const
{
    BigInt       ans(pos);
    unsigned int extra = 0;
    Digt         i     = 0;
    while(i < (Digt) ReverseInt.size() || extra != 0)
    {
        if(i < (Digt) ReverseInt.size())
        {
            extra += ReverseInt[i] * b;
        }
        ans.ReverseInt.push_back(extra % pos);
        extra /= pos;
        i++;
    }
    ans.postive = postive;
    ans.correctPostive();
    return ans;
}
BigInt BigInt::operator*(const BigInt &b) const
{
    BigInt ans(pos);
    Digt   i = 0;
    while(i < (Digt) b.ReverseInt.size())
    {
        ans += ((*this) * b.ReverseInt[i]).move(i);
        i++;
    }
    ans.postive       = (postive == b.postive);
    ans.PositionOfDot = PositionOfDot + b.PositionOfDot;
    ans.correctPostive();
    return ans;
}
BigInt BigInt::operator/(const BigInt &b) const
{
    BigInt ans(pos);
    if(!absSmaller(b))
    {
        ans.postive = (postive == b.postive);
        BigInt rest(*this), b2(b);
        rest.postive = true;
        b2.postive   = true;
        rest += BigInt(pos, 1);
        rest.correctPostive();
        b2.correctPostive();
        Digt i = rest.ReverseInt.size() - b2.ReverseInt.size();
        b2.move(i);
        for(; i != Digt(-1); i--)
        {
            singleDigt l = 0, r = pos - 1;
            while(l < r)
            {
                singleDigt mid = (l + r + 1) / 2;
                if((b2 * mid).absSmaller(rest))
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            rest = rest - (b2 * l);
            rest.correctPostive();
            ans.ReverseInt.push_back(l);
            b2.move(-1);
        }
        std::reverse(ans.ReverseInt.begin(), ans.ReverseInt.end());
        ans.correctPostive();
    }
    return ans;
}
bool BigInt::operator<(const BigInt &b) const
{
    if(isZero() && b.isZero())
    {
        return false;
    }
    else
    {
        if(postive == b.postive)
        {
            return (!postive) ^ absSmaller(b);
        }
        else
        {
            return !postive;
        }
    }
}
bool BigInt::operator==(const BigInt &b) const
{
    if(isZero() && b.isZero())
    {
        return true;
    }
    else
    {
        if(postive == b.postive &&
           ReverseInt.size() - PositionOfDot == b.ReverseInt.size() - b.PositionOfDot)
        {
            BigInt a(*this), b2(b);
            Digt   offset = std::max(PositionOfDot, b.PositionOfDot);
            a.move(offset - PositionOfDot), b2.move(offset - b.PositionOfDot);
            for(Digt i = 0; i < (Digt) a.ReverseInt.size(); i++)
            {
                if(a.ReverseInt[i] != b2.ReverseInt[i])
                    return false;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
}
BigInt BigInt::move(Digt dis = 0)
{
    IntStore newStore;
    Digt     i = 0;
    if(dis < 0)
        i = -dis;
    else
        for(Digt j = 0; j < dis; j++)
        {
            newStore.push_back(0);
        }
    while(i < (Digt) ReverseInt.size())
    {
        newStore.push_back(ReverseInt[i]);
        i++;
    }
    ReverseInt = newStore;
    return *this;
}
bool BigInt::absSmaller(const BigInt &b) const
{
    if(ReverseInt.size() - PositionOfDot == b.ReverseInt.size() - b.PositionOfDot)
    {
        BigInt a(*this), b2(b);
        Digt   offset = std::max(PositionOfDot, b.PositionOfDot);
        a.move(offset - PositionOfDot), b2.move(offset - b.PositionOfDot);
        for(Digt i = a.ReverseInt.size() - 1; i != Digt(-1); --i)
        {
            if(a.ReverseInt[i] < b2.ReverseInt[i])
                return true;
            if(b2.ReverseInt[i] < a.ReverseInt[i])
                return false;
        }
        return false;
    }
    else
    {
        return ReverseInt.size() < b.ReverseInt.size();
    }
}
void BigInt::correctPostive(void)
{
    while(!ReverseInt.empty() && ReverseInt.back() == 0)
    {
        ReverseInt.pop_back();
    }
    if(isZero())
    {
        postive = false;
        ReverseInt.clear();
    }
}
inline bool BigInt::isZero(void) const
{
    if(ReverseInt.size() == 0)
    {
        return true;
    }
    else
    {
        for(auto i: ReverseInt)
        {
            if(i != 0)
            {
                return false;
            }
        }
        return true;
    }
}
char itoc(int in)
{
    if(in < 10)
    {
        return in + '0';
    }
    else
    {
        return in + 'A';
    }
    return 0;
}
int ctoi(char in)
{
    if(isdigit(in))
    {
        return in - '0';
    }
    else
    {
        if(isalpha(in))
        {
            return toupper(in) - 'A';
        }
    }
}
std::ostream &operator<<(std::ostream &os, const BigInt &out)
{
    os << out.string();
    return os;
}
std::istream &operator>>(std::istream &is, BigInt &in)
{
    while(!isalnum(is.peek()) && is.peek() != '-' && is.peek() != '+' && is.peek() != '.')
    {
        is.get();
    }
    if(is)
    {
        if(is.peek() == '-' || is.peek() == '+')
        {
            in.postive = (is.get() == '+');
        }
        else
        {
            in.postive = true;
        }
        in.ReverseInt.clear();
        while(isalnum(is.peek()) || is.peek() == '.')
        {
            if(is.peek() == '.')
            {
                is.get();
                while(isalnum(is.peek()))
                {
                    in.ReverseInt.push_back(ctoi(is.get()));
                    in.PositionOfDot++;
                }
            }
            else
            {
                in.ReverseInt.push_back(ctoi(is.get()));
            }
        }
        std::reverse(in.ReverseInt.begin(), in.ReverseInt.end());
        in.correctPostive();
    }
    return is;
}
}  // namespace bit
int main(void)
{
    int t;
    while(std::cin >> t)
    {
        for(int i = 0; i < t; i++)
        {
            bit::BigInt r(10), k(10);
            std::cin >> r >> n;
            bit::BigInt ans(r);
            for(int i = 0; i < n - 1; i++)
            {
                ans = ans * r;
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}
