#include "main.h"
#include <iostream>
//#include<windows.h>
const int BUF_SIZE = 128 * 1024;
char      buf[BUF_SIZE];
int       colourtest(void)
{
    // setvbuf(stdout, buf, _IOFBF, BUF_SIZE);
    for(int i = 0; i < 256; i++)
    {
        // std::cout << "i:\t" << i << "\t";
        std::cout << std::flush << "\033[38;5;" << i << "m"
                  << "\033[48;5;" << 255 - i << "m" << std::flush;
        std::cout << "Hello World!"
                  << "\033[0m" << std::flush;
        if(i && !((i + 3) % 6))
        {
            std::cout << "\n";
        }
        else
        {
            std::cout << std::flush  //<<"\t"<<std::flush;
              ;
        }
    }
    return 0;
}
StudentList        MainList;
std::map<ID, User> admins;
int                main(int argCnt, char **arg)
{
    std::vector<std::string>                        rawArgs;
    std::map<std::string, std::vector<std::string>> args = {
        { "rubbish", {} }, { "-t", {} }, { "-u", {} }, { "-p", {} }, { "-f", {} },
    };
    for(int i = 0; i < argCnt; i++)
    {
        rawArgs.push_back(std::move(std::string(arg[i])));
    }
    std::string option = "rubbish";
    for(auto i = rawArgs.begin(); i != rawArgs.end(); i++)
    {
        if(args.contains(*i))
        {
            option = *i;
        }
        else
        {
            args[option].push_back(*i);
        }
    }
    enum LoginType
    {
        admin,
        student
    } loginType;
    {
        std::map<std::string, LoginType> map = { { "admin", admin },
                                                 { "a", admin },
                                                 { "student", student },
                                                 { "s", student },
                                                 { "stu", student } };
        while(true)
        {
            std::string loginTypeInput;
            if(!(args["-t"].empty()))
            {
                loginTypeInput = args["-t"][0];
                args["-t"].clear();
            }
            else
            {
                std::cout << Docs::loginTypeNote << std::endl;
                std::cin >> loginTypeInput;
            }
            if(map.contains(loginTypeInput))
            {
                loginType = map[loginTypeInput];
            }
            else
            {
                std::cout << Docs::unKnowLoginTypeNote << std::endl;
            }
        }
    }
    return 0;
}