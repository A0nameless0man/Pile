#pragma once
#include<string>
class CmdResalt
{
public:
	CmdResalt(bool success, std::string msg = "");
	operator bool()const;
	operator const std::string& ()const;
private:
	bool success;
	std::string msg;
};

#define RunTimeAssert(condition,msg) \
if(!(condition)) \
{\
	return CmdResalt(false,msg);\
}