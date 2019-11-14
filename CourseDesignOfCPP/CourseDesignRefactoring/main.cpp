#include <iostream>
#include"main.h"
//#include<windows.h>
const int BUF_SIZE = 128 * 1024;
char buf[BUF_SIZE];
int colourtest(void)
{
	//setvbuf(stdout, buf, _IOFBF, BUF_SIZE);
	for (int i = 0; i < 256; i++)
	{
		// std::cout << "i:\t" << i << "\t";
		std::cout << std::flush << "\033[38;5;" << i << "m" << "\033[48;5;" << 255 - i << "m" << std::flush;
		std::cout << "Hello World!" << "\033[0m" << std::flush;
		if (i && !((i + 3) % 6))
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << std::flush;
		}

	}
	return 0;
}
int main(int argCnt, char** arg)
{
	std::map<std::string, std::vector<std::string>> args =
	{
		{"rubbish",{}},
		{Docs::argForLoginType,{}},
		{"-u",{}},
		{"-p",{}},
		{"-f",{}},
	};
	enum class LoginType
	{
		admin, student
	};
	LoginType loginType;
	{
		std::vector<std::string> rawArgs;
		for (int i = 0; i < argCnt; i++)
		{
			rawArgs.push_back(std::move(std::string(arg[i])));
		}
		std::string optionInArgs = "rubbish";
		for (auto i = rawArgs.begin(); i != rawArgs.end(); i++)
		{
			if (args.contains(*i))
			{
				optionInArgs = *i;
			}
			else
			{
				args[optionInArgs].push_back(*i);
			}
		}
	}
	//deal with command line args
	
	{
		const std::map<std::string, LoginType> LoginUserTypeMap =
		{
			{"admin",LoginType::admin},
			{"a",LoginType::admin},
			{"student",LoginType::student},
			{"s",LoginType::student},
			{"stu",LoginType::student}
		};
		while (true)
		{
			std::string loginTypeInput;
			if (!(args[Docs::argForLoginType].empty()))
			{
				loginTypeInput = args[Docs::argForLoginType][0];
				args[Docs::argForLoginType].clear();
			}
			else
			{
				std::cout << Docs::loginTypeNote << std::endl;
				std::cin >> loginTypeInput;
			}
			if (LoginUserTypeMap.contains(loginTypeInput))
			{
				loginType = LoginUserTypeMap.at(loginTypeInput);
				break;
			}
			else
			{
				std::cout << Docs::unKnowLoginTypeNote << std::endl;
			}
		}
	}
	//get userType
	return 0;
}