#pragma once
#include<string>
namespace Docs
{
	using S = const std::string;
	S hashSalt = "mySpecialSalt";
	S help = R"()";
	S argForLoginType = "-t";
	S loginTypeNote = R"(请选择登陆用户类型:
a:	管理员
s:	学生)";
	S unKnowLoginTypeNote = R"(登陆用户类型错误,请重试)";
	S sexTypeNote = R"(请输入性别:
m:	男
f:	女
u:	不明)";
	S unKnowSexTypeNote = R"(性别类型错误,请重试)";
}