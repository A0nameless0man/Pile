#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
int main(void)
{
	std::stringstream buffer;
	std::string input;
	int i = 0;
	while (!std::feof(stdin))
	{
		i = 0;
		std::getline(std::cin,input);
		buffer.clear();
		buffer << input;
		while (buffer>>input)
		{
			i++;
		}
		if (i!=0)
		{
			std::cout << i << std::endl;
		}
	}
	return 0;
}
