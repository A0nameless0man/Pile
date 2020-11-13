#include <iostream>
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
                        case:
                            '\\': sta = State::strescape;
                            std::cout << c;
                        default:
                            std::cout << c;
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}