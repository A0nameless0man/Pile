#include"Server.h"
Server::Server() :
	studentCount(0),
	courseCount(0),
	courseSelectionCount(0),
	classesCount(0)
{
	addUser(User("0", "Admin"));
	setPasswardOfUser("0", "admin");
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
	auto iter = admin.find(id);
	RunTimeAssert(iter != admin.end(), Docs::adminIdNotExistError);
	RunTimeAssert(iter->second.login(pwd), Docs::pwdNotMatchWarrning);
	return CmdResalt(true, Docs::successLoginNote);
}
CmdResalt Server::addUser(const User& user)
{
	RunTimeAssert(!admin.contains(user.getID()), Docs::adminIdConflictError);
	admin.insert({ user.getID() , user });
	return CmdResalt(true, std::to_string(1) + Docs::insertSuccessNoteSuffix);
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

CmdResalt Server::setPasswardOfUser(const User::ID& userId, const User::PWD& newPwd)
{
	auto iter = admin.find(userId);
	RunTimeAssert(iter != admin.end(), Docs::adminIdNotExistError);
	iter->second.setPWD(newPwd);
	return CmdResalt(true, std::to_string(1) + Docs::setSuccessNoteSuffix);
}

CmdResalt Server::setPassWordOfStudent(const Student::LogicID& studentId, const Student::PWD& newPwd)
{
	auto iter = students.find(studentId);
	RunTimeAssert(iter != students.end(), Docs::studentLogicIDNotExistError);
	iter->second.setPWD(newPwd);
	return CmdResalt(true, std::to_string(1) + Docs::setSuccessNoteSuffix);
}

CmdResalt Server::removeCourseGrade(const Student::LogicID& stuId, const Course::CourseID& courseId, const CourseSelectionRecord::GradeOfCourse& grade)
{
	auto iter = courseSelectionIndex.find(stuId);
	RunTimeAssert(iter != courseSelectionIndex.end(), Docs::noCourseSelectionRecordForThisStudentError);
	auto iteriter = iter->second.find(courseId);
	RunTimeAssert(iteriter != iter->second.end(), Docs::noSuchCourseSelectionRecordForThisStudentError);
	courseSelectionRecords.find(iteriter->second)->second.setGrade(grade);
	return CmdResalt(true, std::to_string(1) + Docs::setSuccessNoteSuffix);
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

CmdResalt Server::removeCourseSelectionRecord(const Student::LogicID& stuId, const Course::CourseID& courseId)
{
	auto iter = courseSelectionIndex.find(stuId);
	RunTimeAssert(iter != courseSelectionIndex.end(), Docs::noCourseSelectionRecordForThisStudentError);
	auto iteriter = iter->second.find(courseId);
	RunTimeAssert(iteriter != iter->second.end(), Docs::noSuchCourseSelectionRecordForThisStudentError);
	courseSelectionRecords.erase(iteriter->second);
	iter->second.erase(iteriter);
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

const Student& Server::getStudentByLogicId(const Student::LogicID& id) const
{
	auto iter = students.find(id);
	RunTimeAssert(iter != students.end(), Docs::studentLogicIDNotExistError);
	return iter->second;
}

const Course& Server::getCourseByCourseId(const Course::CourseID& id) const
{
	auto iter = courses.find(id);
	RunTimeAssert(iter != courses.end(), Docs::courseLogicIdNotExistError);
	return iter->second;
}

const Student::StudentClassName& Server::getClassNameByClassID(const Student::StudentClassLogicalID& id) const
{
	auto iter = classes.find(id);
	RunTimeAssert(iter != classes.end(), Docs::studentClassLogicalIdNotExistError);
	return iter->second;
}

const CourseSelectionRecord& Server::getCourseSelectionRecordByID(const CourseSelectionRecord::CourseSelectionRecordID& id)
{
	auto iter = courseSelectionRecords.find(id);
	RunTimeAssert(iter != courseSelectionRecords.end(), Docs::CSRNotExit);
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
