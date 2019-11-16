#pragma once
#include<string>
namespace Docs
{
	using S = const std::string;
	S hashSalt = "mySpecialSalt";
	S insertSuccessNoteSuffix = " 行数据已被插入";
	S studentIDconflictError = "学号发生冲突,请检查是否已经存在此学生";
	S studentClassLogicalIdNotExistError = "找不到此班级,请确认已经创建该班级";
	S studentClassNameConflictError = "此班级已存在,请确认";
}