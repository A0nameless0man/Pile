#include"Server.h"
Server::Server() :
	studentCount(0),
	courseCount(0),
	courseSelectionCount(0),
	classesCount(0)
{
}
CmdResalt Server::loginAsStudent(const Student::ID& id, const Student::PWD& pwd) const
{
	auto logicId = studentIdIndex.find(id);
	RunTimeAssert(logicId != studentIdIndex.end(), Docs::studentIDNotExistError);
	auto stu = students.find(logicId->second);
	RunTimeAssert(stu != students.end(), Docs::studentLogicIDNotExistError);
	RunTimeAssert(stu->second.login(pwd), Docs::pwdNotMatchWarrning);
	return CmdResalt(true, Docs::successLoginNote);
}
CmdResalt Server::loginAsUser(const User::ID& id, const User::PWD& pwd) const
{
	return CmdResalt(true, Docs::successLoginNote);
}
CmdResalt Server::addStudent(const Student& student)
{
	//When add a student to the sys, make sure that he has unique ID and have a class for him
	RunTimeAssert(!studentIdIndex.contains(student.getID()), Docs::studentIDconflictError);
	RunTimeAssert(classes.contains(student.getClass()), Docs::studentClassLogicalIdNotExistError);
	placementIndex[student.getClass()].insert({ studentCount });
	studentIdIndex.insert({ student.getID(), studentCount });
	studentNameIndex[student.getName()].insert({ studentCount });
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

CmdResalt Server::addCourseSelectionRecord(const Student::LogicID& stuId, const Course::CourseID& course)
{
	RunTimeAssert(students.contains(stuId), Docs::studentLogicIDNotExistError);
	RunTimeAssert(courses.contains(course), Docs::courseLogicIdNotExistError);
	courseSelectionRecords.insert({ courseSelectionCount,CourseSelectionRecord(stuId,0,course) });
	auto iter = courseSelectionIndex[stuId];
	iter.insert({ course,courseSelectionCount });
	//++courseSelectionCount;
	return CmdResalt(true, std::to_string(1) + Docs::insertSuccessNoteSuffix);
}

CmdResalt Server::removeStudentByLogicId(const Student::LogicID& logicId)
{
	RunTimeAssert(students.contains(logicId), Docs::studentLogicIDNotExistError);
	Student& stu = students.find(logicId)->second;
	placementIndex[stu.getClass()].erase(logicId);

	studentIdIndex.erase(stu.getID());

	auto name = studentNameIndex.find(stu.getName());
	name->second.erase(logicId);
	if (name->second.empty())
	{
		studentNameIndex.erase(name);
	}

	courseSelectionIndex.erase(logicId);

	students.erase(logicId);
	return CmdResalt(true, std::to_string(1) + Docs::removeSuccessNoteSuffix);
}


const CourseSelectionRecord::CourseSelectionRecordID Server::getCourseSelectionRecordIdByStudentIdAndCourseID(const Student::LogicID& stuId, const Course::CourseID& courseId) const
{
	auto iter = courseSelectionIndex.find(stuId);
	RunTimeAssert(iter != courseSelectionIndex.end(), Docs::noCourseSelectionRecordForThisStudentError);
	auto iteriter = iter->second.find(courseId);
	RunTimeAssert(iteriter != iter->second.end(), Docs::noSuchCourseSelectionRecordForThisStudentError);
	return iteriter->second;
}

const Server::CourseSelectionRecordIdSet Server::getCourseSelectionRecordIdByStudentId(const Student::LogicID& stuId) const
{
	auto iter = courseSelectionIndex.find(stuId);
	RunTimeAssert(iter != courseSelectionIndex.end(), Docs::noCourseSelectionRecordForThisStudentError);
	Server::CourseSelectionRecordIdSet ans;
	for (auto i : iter->second)
	{
		ans.insert(i.second);
	}
	return ans;
}

const Server::StudentIdSet Server::getStudentLogicIdByClass(const Student::StudentClassLogicalID& classid) const
{
	auto iter = placementIndex.find(classid);
	RunTimeAssert(iter != placementIndex.end(), Docs::studentClassLogicalIdNotExistError);
	return iter->second;
}

const Student Server::getStudentByLogicId(const Student::LogicID& id) const
{
	auto iter = students.find(id);
	RunTimeAssert(iter != students.end(), Docs::studentLogicIDNotExistError);
	return iter->second;
}

const Course::CourseID Server::getCourseIdByCourseName(const Course::CourseName& courseName) const
{
	auto iter = courseNameIndex.find(courseName);
	RunTimeAssert(iter != courseNameIndex.end(), Docs::courseNameNotExistError);
	return iter->second;
}

const Server::StudentIdSet Server::getStudentLogicIdByName(const Student::UserName& name) const
{
	auto iter = studentNameIndex.find(name);
	RunTimeAssert(iter != studentNameIndex.end(), Docs::studentNameNotExistError);
	return studentNameIndex.find(name)->second;
}

const Server::StudentIdSet Server::getStudentLogicIdByID(const Student::ID& id) const
{
	auto iter = studentIdIndex.find(id);
	RunTimeAssert(iter != studentIdIndex.end(), Docs::studentIDNotExistError);
	return Server::StudentIdSet();
}

const Student::StudentClassLogicalID Server::getClassLogicalIdByClassName(const Student::StudentClassName& className) const
{
	auto iter = classNameIndex.find(className);
	RunTimeAssert(iter != classNameIndex.end(), Docs::studentClassNameNotExistError);
	return iter->second;
}
