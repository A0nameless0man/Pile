#pragma once
#include<string>
namespace Docs
{
	using S = const std::string;
	S hashSalt = "mySpecialSalt";
	S studentIDconfilctError = "学号发生冲突,请检查是否已经存在此学生";
	S studentClassLogicalIdNotExistError = "找不到此班级,请确认已经创建该班级";
}