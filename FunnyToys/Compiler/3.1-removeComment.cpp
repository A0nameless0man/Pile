#include <exception>
#include <iostream>
#include <map>
#include <string>

enum class State
{
    normal,
    strnormal,
    strescape,
    commentbeg,
    linecomment,
    longcomment,
    longcommentend,
};

const std::map<char, char> escapeChars { { 'n', '\n' },
                                         { '0', '\0' },
                                         { '\\', '\\' },
                                         { '\'', '\'' },
                                         { '\"', '\"' } };

int main(void)
{
    std::string s;
    State       sta = State::normal;
    while(std::getline(std::cin, s))
    {
        s.push_back('\n');
        for(auto c: s)
        {
            switch(sta)
            {
                case State::normal:
                    switch(c)
                    {
                        case '"':
                            sta = State::strnormal;
                            std::cout << c;
                            break;
                        case '/':
                            sta = State::commentbeg;
                            break;
                        default:
                            std::cout << c;
                            break;
                    }
                    break;
                case State::strnormal:
                    switch(c)
                    {
                        case '"':
                            sta = State::normal;
                            std::cout << c;
                            break;
                        case '\\':
                            sta = State::strescape;
                            std::cout << c;
                        default:
                            std::cout << c;
                            break;
                    }
                    break;
                case State::strescape:
                {
                    auto iter = escapeChars.find(c);
                    if(iter != escapeChars.end())
                    {
                        std::cout << iter->second;
                    }
                    else
                    {
                        throw new std::logic_error(
                          "Unknow escape");
                    }
                    break;
                }
                case State::commentbeg:
                {
                    switch(c)
                    {
                        case '/':
                            sta = State::linecomment;
                            break;
                        case '*':
                            sta = State::longcomment;
                            break;
                        default:
                            sta = State::normal;
                            std::cout << '/' << c;
                            break;
                    }
                    break;
                }
                case State::linecomment:
                {
                    switch(c)
                    {
                        case '\n':
                            sta = State::normal;
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case State::longcomment:
                {
                    switch(c)
                    {
                        case '*':
                            sta = State::longcommentend;
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case State::longcommentend:
                {
                    switch(c)
                    {
                        case '/':
                            sta = State::normal;
                            break;
                        default:
                            sta = State::longcomment;
                            break;
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
    return 0;
}