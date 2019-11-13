#pragma once
#include<string>
namespace Docs
{
	using CS = std::string;
	CS help = R"()";
	CS loginTypeNote = R"(请选择登陆用户类型:
a:	管理员
s:	学生
)";
	CS unKnowLoginTypeNote = R"(登陆用户类型错误,请重试)";
}