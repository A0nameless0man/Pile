#pragma once
#include<string>
namespace Docs
{
	using S = const std::string;
	//Note
	S insertSuccessNoteSuffix = " 行数据已被插入";
	S setSuccessNoteSuffix = " 行数据已修改";
	S removeSuccessNoteSuffix = " 行数据已被移除";
	S successLoginNote = "登陆成功";
	//Warning
	S pwdNotMatchWarrning = "密码错误";
	//Error
	S adminIdNotExistError = "管理员账号不存在,请确认后再试";
	S adminIdConflictError = "管理员账号已存在,请确认后再试";
	S studentIDNotExistError = "找不到该学号对应的学生,请确认后再试";
	S studentIDconflictError = "学号发生冲突,请检查是否已经存在此学生";
	S studentNameNotExistError = "找不到该姓名的学生,请确认后再试";
	S studentClassNameNotExistError = "找不到此班级,请确认已经创建该班级";
	S studentClassNameConflictError = "此班级已存在,请确认";
	S courseNameNotExistError = "找不到这个课程,请确认后再试";
	S courseNameConflictError = "这个课程已存在,请确认后再试";
	S noCourseSelectionRecordForThisStudentError = "找不到该学生的选课记录,请查证后重试";
	S noSuchCourseSelectionRecordForThisStudentError = "该学生未选择本课程,请查证后重试";
	//InnerError
	S studentLogicIDNotExistError = "该学生不存在,请确认后再试";
	S studentClassLogicalIdNotExistError = "该班级不存在,请确认已经创建该班级";
	S courseLogicIdNotExistError = "该课程不存在,请确认";
	S CSRNotExit = "不存在这条选课记录";
	//other
	S hashSalt = "mySpecialSalt";
}