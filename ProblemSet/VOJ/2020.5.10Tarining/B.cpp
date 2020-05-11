#include <iostream>
#include <stack>
#include <string>

int main(void)
{
    std::string input;
    int         i = 0;
    while(std::getline(std::cin, input))
    {
        std::stack<bool> num;
        std::stack<int>  op;
        for(size_t i = input.length(); i > 0; --i)
        {
            char curc = input[i - 1];
            switch(curc)
            {
                case 'V':
                    num.push(true);
                    break;
                case 'F':
                    num.push(false);
                    break;
                case '!':
                {
                    int nextop = 0;
                    while((!op.empty() && op.top() != -1) && nextop >= op.top())
                    {
                        int curop = op.top();
                        op.pop();
                        switch(curop)
                        {
                            case 0:
                                if(num.size() >= 1)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    num.push(!curnum);
                                }
                                else
                                {
                                    std::cerr << "not enough 1" << std::endl;
                                }
                                break;
                            case 1:
                                if(num.size() >= 2)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    bool curnum2 = num.top();
                                    num.pop();
                                    num.push(curnum && curnum2);
                                }
                                else
                                {
                                    std::cerr << "not enough 2" << std::endl;
                                }

                                break;
                            case 2:
                                if(num.size() >= 2)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    bool curnum2 = num.top();
                                    num.pop();
                                    num.push(curnum || curnum2);
                                }
                                else
                                {
                                    std::cerr << "not enough -1" << std::endl;
                                }

                                break;
                            default:
                                break;
                        }
                    }
                    op.push(nextop);
                    break;
                }
                case '&':
                {
                    int nextop = 1;
                    while((!op.empty() && op.top() != -1) && nextop >= op.top())
                    {
                        int curop = op.top();
                        op.pop();
                        switch(curop)
                        {
                            case 0:
                                if(num.size() >= 1)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    num.push(!curnum);
                                }
                                else
                                {
                                    std::cerr << "not enough 1" << std::endl;
                                }
                                break;
                            case 1:
                                if(num.size() >= 2)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    bool curnum2 = num.top();
                                    num.pop();
                                    num.push(curnum && curnum2);
                                }
                                else
                                {
                                    std::cerr << "not enough 2" << std::endl;
                                }

                                break;
                            case 2:
                                if(num.size() >= 2)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    bool curnum2 = num.top();
                                    num.pop();
                                    num.push(curnum || curnum2);
                                }
                                else
                                {
                                    std::cerr << "not enough -1" << std::endl;
                                }

                                break;
                            default:
                                break;
                        }
                    }
                    op.push(nextop);

                    break;
                }
                case '|':
                {
                    int nextop = 2;
                    while((!op.empty() && op.top() != -1) && (nextop >= op.top()))
                    {
                        int curop = op.top();
                        op.pop();
                        switch(curop)
                        {
                            case 0:
                                if(num.size() >= 1)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    num.push(!curnum);
                                }
                                else
                                {
                                    std::cerr << "not enough 1" << std::endl;
                                }
                                break;
                            case 1:
                                if(num.size() >= 2)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    bool curnum2 = num.top();
                                    num.pop();
                                    num.push(curnum && curnum2);
                                }
                                else
                                {
                                    std::cerr << "not enough 2" << std::endl;
                                }

                                break;
                            case 2:
                                if(num.size() >= 2)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    bool curnum2 = num.top();
                                    num.pop();
                                    num.push(curnum || curnum2);
                                }
                                else
                                {
                                    std::cerr << "not enough -1" << std::endl;
                                }

                                break;
                            default:
                                break;
                        }
                    }
                    op.push(nextop);

                    break;
                }
                case ')':
                {
                    int nextop = -1;
                    while((!op.empty() && op.top() != -1) && nextop >= op.top())
                    {
                        int curop = op.top();
                        op.pop();
                        switch(curop)
                        {
                            case 0:
                                if(num.size() >= 1)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    num.push(!curnum);
                                }
                                else
                                {
                                    std::cerr << "not enough 1" << std::endl;
                                }
                                break;
                            case 1:
                                if(num.size() >= 2)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    bool curnum2 = num.top();
                                    num.pop();
                                    num.push(curnum && curnum2);
                                }
                                else
                                {
                                    std::cerr << "not enough 2" << std::endl;
                                }

                                break;
                            case 2:
                                if(num.size() >= 2)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    bool curnum2 = num.top();
                                    num.pop();
                                    num.push(curnum || curnum2);
                                }
                                else
                                {
                                    std::cerr << "not enough -1" << std::endl;
                                }

                                break;
                            default:
                                break;
                        }
                    }
                    op.push(nextop);

                    break;
                }
                case '(':
                    while(op.top() != -1)
                    {
                        int curop = op.top();
                        op.pop();
                        switch(curop)
                        {
                            case 0:
                                if(num.size() >= 1)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    num.push(!curnum);
                                }
                                else
                                {
                                    std::cerr << "not enough 1" << std::endl;
                                }
                                break;
                            case 1:
                                if(num.size() >= 2)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    bool curnum2 = num.top();
                                    num.pop();
                                    num.push(curnum && curnum2);
                                }
                                else
                                {
                                    std::cerr << "not enough 2" << std::endl;
                                }

                                break;
                            case 2:
                                if(num.size() >= 2)
                                {
                                    bool curnum = num.top();
                                    num.pop();
                                    bool curnum2 = num.top();
                                    num.pop();
                                    num.push(curnum || curnum2);
                                }
                                else
                                {
                                    std::cerr << "not enough -1" << std::endl;
                                }

                                break;
                            default:
                                break;
                        }
                    }
                    op.pop();
                    break;
                default:
                    break;
            }
        }
        while(!op.empty())
        {
            int curop = op.top();
            op.pop();
            switch(curop)
            {
                case 0:
                    if(num.size() >= 1)
                    {
                        bool curnum = num.top();
                        num.pop();
                        num.push(!curnum);
                    }
                    else
                    {
                        std::cerr << "not enough 1" << std::endl;
                    }
                    break;
                case 1:
                    if(num.size() >= 2)
                    {
                        bool curnum = num.top();
                        num.pop();
                        bool curnum2 = num.top();
                        num.pop();
                        num.push(curnum && curnum2);
                    }
                    else
                    {
                        std::cerr << "not enough 2" << std::endl;
                    }

                    break;
                case 2:
                    if(num.size() >= 2)
                    {
                        bool curnum = num.top();
                        num.pop();
                        bool curnum2 = num.top();
                        num.pop();
                        num.push(curnum || curnum2);
                    }
                    else
                    {
                        std::cerr << "not enough -1" << std::endl;
                    }

                    break;
                default:
                    break;
            }
        }
        char ans = num.top() ? 'V' : 'F';
        std::cout << "Expression " << ++i << ": " << ans << std::endl;
    }
}