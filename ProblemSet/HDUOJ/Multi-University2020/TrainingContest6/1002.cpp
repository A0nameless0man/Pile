#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for((i) = (s); (i) <= (e); ++(i))

struct Equation
{
    string lhs;
    string rhs;
    string ans;
    char   op;
};

std::string clean(const std::string &op)
{
    auto no_zero_pos = op.find_first_not_of('0');
    if(no_zero_pos != std::string::npos)
        return op.substr(no_zero_pos);
    return "0";
}

Equation parse(const string &e)
{
    size_t eq_idx;
    eq_idx     = e.find_first_of('=');
    string ans = clean(e.substr(eq_idx + 1));

    size_t op_idx = e.find_first_of("+-*/");
    string lhs    = clean(e.substr(0, op_idx));
    string rhs =
      clean(e.substr(op_idx + 1, eq_idx - op_idx - 1));

    return { std::move(lhs),
             std::move(rhs),
             std::move(ans),
             e[op_idx] };
}

bool is_correct(const Equation &e, int base)
{
    ll lhs, rhs, ans;
    try
    {
        lhs = std::stoll(e.lhs, 0, base);
        rhs = std::stoll(e.rhs, 0, base);
        ans = std::stoll(e.ans, 0, base);
    }
    catch(...)
    {
        return false;
    }

    if(e.op == '+')
    {
        return lhs + rhs == ans;
    }
    else if(e.op == '-')
    {
        return lhs - rhs == ans;
    }
    else if(e.op == '*')
    {
        return lhs * rhs == ans;
    }
    else
    {
        return ans * rhs == lhs;
    }
}

int main()
{
    // freopen("1002.in", "r", stdin);

    string equation;

    while(std::cin >> equation)
    {
        Equation e = parse(equation);
        int      base;
        asc(base, 2, 16)
        {
            if(is_correct(e, base))
            {
                break;
            }
        }
        if(base <= 16)
        {
            cout << base << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }
}