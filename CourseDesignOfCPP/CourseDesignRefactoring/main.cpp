#include<iostream>
#include<map>
#include"User.h"
#include"Student.h"
#include"Docs.h"
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
int __main__(int argCnt, char** arg)
{
	return 0;
}
int readerTest(void)
{
	InteractiveReader<int,InRange<int>> reader("just int",InRange<int>(0,10));
	reader.read(std::cin, std::cout);
	return 0;
}
int main(void)
{
	return readerTest();
}