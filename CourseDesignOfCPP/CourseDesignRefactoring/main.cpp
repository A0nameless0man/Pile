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
	iReader::InteractiveReader<int, iReader::WithIn<int>> reader("just int", iReader::WithIn<int>({1,2,5,9}));
	std::cout << reader.read(std::cin, std::cout) << std::endl;
	return 0;
}
int main(void)
{
	return readerTest();
}