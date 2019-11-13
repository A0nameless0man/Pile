#pragma once
#include<string>
namespace Docs
{
	using S = const std::string;
	S help = R"()";
	S loginTypeNote = R"(请选择登陆用户类型:
a:	管理员
s:	学生)";
	S unKnowLoginTypeNote = R"(登陆用户类型错误,请重试)";
}