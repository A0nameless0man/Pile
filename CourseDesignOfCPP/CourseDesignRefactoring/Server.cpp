#include"Server.h"
Server::Server() :
	adminCount(0),
	studentCount(0),
	courseCount(0),
	courseSelectionCount(0),
	classesCount(0)
{
}
CmdResalt Server::addStudent(const Student& student)
{
	//When add a student to the sys, make sure that he has unique ID and have a class for him
	RunTimeAssert(!studentIdIndex.contains(student.getID()), Docs::studentIDconflictError);
	RunTimeAssert(classes.contains(student.getClass()), Docs::studentClassLogicalIdNotExistError);
	placementIndex.insert({ student.getClass(), studentCount });
	studentIdIndex.insert({ student.getID(), studentCount });
	studentNameIndex.insert({ student.getName(), studentCount });
	students.insert({ studentCount,student });
	++studentCount;
	return CmdResalt(true, std::to_string(1) + Docs::insertSuccessNoteSuffix);
}

CmdResalt Server::addClass(const Student::StudentClassName& className)
{
	RunTimeAssert(!classNameIndex.contains(className), Docs::studentClassNameConflictError);
	classes.insert({ classesCount,className });
	classNameIndex.insert({ className,classesCount });
	classesCount++;
	return CmdResalt(true, std::to_string(1) + Docs::insertSuccessNoteSuffix);
}
