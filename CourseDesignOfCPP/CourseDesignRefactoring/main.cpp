#include<iostream>
#include<map>
#include"User.h"
#include"Student.h"
#include"Docs.h"
#include"Server.h"
#include "ThirdPartyLib/colourStream.h"
#include"interactiveReader.h"

//#include<windows.h>
const int BUF_SIZE = 128 * 1024;
char buf[BUF_SIZE];
int colourtest(void)
{

	using namespace kerbal::utility::costream;
	costream<std::cout>(LIGHT_RED) << 123 << std::endl;
	return 0;
}
int __main__(void)
{
	Server myServer;
	myServer.addClass("no");
	myServer.addStudent(Student(User("123", "jk"), 0, 2019));
	//std::cout << (std::string)b << std::endl;
	return 0;
}
int readerTest(void)
{
	using namespace kerbal::utility::costream;
	while (true)
	{
		std::string s;

		costream<std::cout>(LIGHT_RED) << 123 << std::endl;
		//std::getline(std::cin, s);
		std::cin >> s;
		costream<std::cout>(LIGHT_RED) << s.length() << std::endl;
	}
	return 0;
}
int main(void)
{
	__main__();
	return readerTest();
}