#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <unordered_map>

const int           BUFFER_SIZE = 512;
const double        ex          = 0.000001;
std::map<char, int> pri         = { { '+', 1 }, { '-', 1 }, { '*', 2 }, { '/', 2 } };

bool prior(char opa, char opb)
{
    return pri[opa] > pri[opb];
}
void pop(std::stack<double> &num, std::stack<char> &op)
{
    if(!op.empty() && num.size() >= 2)
    {
        char o = op.top();
        op.pop();
        double n[2];
        n[0] = num.top();
        num.pop();
        n[1] = num.top();
        num.pop();
        switch(o)
        {
            case '+':
                num.push(n[1] + n[0]);
                break;
            case '-':
                num.push(n[1] - n[0]);
                break;
            case '*':
                num.push(n[1] * n[0]);
                break;
            case '/':
                if(fabs(n[0]) < ex)
                {
                    throw std::invalid_argument("dev 0");
                }
                num.push(n[1] / n[0]);
                break;
            default:
                throw std::invalid_argument("unknow orerator");
                break;
        }
    }
    else
    {
        throw std::out_of_range("out of range when pop stack:operator");
    }
}
double eval(const std::string &input)
{
    std::stringstream  ss(input);
    std::stack<char>   op;
    std::stack<double> num;
    while(ss)
    {
        if(isdigit(ss.peek()))
        {
            double n;
            ss >> n;
            num.push(n);
        }
        else if(pri.count(ss.peek()) != 0)
        {
            if(!op.empty() && !prior(ss.peek(), op.top()))
            {
                pop(num, op);
            }
            else
            {
                op.push(ss.get());
            }
        }
        else if(ss.peek() == '(')
        {
            op.push(ss.get());
        }
        else if(ss.peek() == ')')
        {
            while(op.top() != '(' && !op.empty() && num.size() >= 2)
            {
                pop(num, op);
            }
            op.pop();
            ss.get();
        }
        else
        {
            ss.get();
        }
    }
    while(!op.empty())
    {
        pop(num, op);
    }
    return num.top();
}
int main(void)
{
    std::string buffer;
    while(std::cin >> buffer)
    {
        try
        {
            std::cout << std::setiosflags(std::ios_base::fixed) << std::setprecision(2)
                      << eval(buffer) << std::endl;
        }
        catch(std::exception &)
        {
            std::cout << "error!" << std::endl;
        }
    }
    return 0;
}