#include"Server.h"
#include"ThirdPartyLib/colourStream.h"
#include<cstdlib>
Server::Server() :
	studentCount(0),
	courseCount(0),
	courseSelectionCount(0),
	classesCount(0)
{
	addUser(User("0", "Admin"));
	setPasswardOfUser("0", "admin");
}
Server::Server(const json& js) :
	UnSerialize(js, studentCount),
	UnSerialize(js, courseCount),
	UnSerialize(js, courseSelectionCount),
	UnSerialize(js, classesCount)
{
	auto stull = [](const std::string& str)->unsigned long long {return std::strtoull(str.c_str(), NULL, 0); };

#define Auto(i,js,x,y,z) if(js.contains(#x))for(auto i = js[#x].begin();i!=js[#x].end();i++)x.insert({(y),(z)})
#define AutoFor(i,js,x) if(js.contains(#x))for(auto i = js[#x].begin();i!=js[#x].end();i++)

	Auto(i, js, admin,i.key(), User(*i) );
	Auto(i, js, students,stull(i.key()),Student(*i));
	Auto(i, js, courses,stull(i.key()),Course(*i) );
	Auto(i, js, courseSelectionRecords,stull(i.key()), CourseSelectionRecord(*i) );
	Auto(i, js, classes, stull(i.key()), *i);
	Auto(i, js, classNameIndex, i.key(), *i);
	Auto(i, js, placementIndex, stull(i.key()), *i);
	Auto(i, js, studentNameIndex, i.key(), *i);
	Auto(i, js, studentIdIndex, i.key(), *i);
	Auto(i, js, courseNameIndex, i.key(), *i);
	AutoFor(i, js, courseSelectionIndex)
	{
		auto& iter = courseSelectionIndex[stull(i.key())];
		for (auto j = i->begin(); j != i->end(); j++)
		{
			iter.insert({ stull(j.key()),*j });
		}
	}
	//Auto(i, js, courseSelectionIndex, stull(i.key()), *i);

#undef Auto
#undef AutoFor
}
json Server::serialize() const
{
	json js;
	Serialize(js, classNameIndex);
	//Serialize(js, placementIndex);
	Serialize(js, studentNameIndex);
	Serialize(js, studentIdIndex);
	Serialize(js, courseNameIndex);
	//Serialize(js, courseSelectionIndex);
	Serialize(js, studentCount);
	Serialize(js, courseCount);
	Serialize(js, courseSelectionCount);
	Serialize(js, classesCount);
	for (auto& i : admin)
	{
		js["admin"][i.first] = i.second.serialize();
	}
	for (auto& i : students)
	{
		js["students"][std::to_string(i.first)] = i.second.serialize();
	}
	for (auto& i : courses)
	{
		js["courses"][std::to_string(i.first)] = i.second.serialize();
	}
	for (auto& i : courseSelectionRecords)
	{
		js["courseSelectionRecords"][std::to_string(i.first)] = i.second.serialize();
	}
	for (auto& i : classes)
	{
		js["classes"][std::to_string(i.first)] = i.second;
	}
	for (auto& i : placementIndex)
	{
		js["placementIndex"][std::to_string(i.first)] = i.second;
	}
	for (auto& i : courseSelectionIndex)
	{
		for (auto& j : i.second)
		{
			js["courseSelectionIndex"][std::to_string(i.first)][std::to_string(j.first)] = j.second;
		}
	}
	return js;
}
CmdResalt Server::loginAsStudent(const Student::ID& id, const Student::PWD& pwd) const
{
	auto logicId = getStudentLogicIdByID(id);
	auto stu = students.find(logicId);
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
	courseSelectionIndex[stuId].insert({ course,courseSelectionCount });
	++courseSelectionCount;
	return CmdResalt(true, std::to_string(1) + Docs::insertSuccessNoteSuffix);
}

CmdResalt Server::addCourse(const Course& course)
{
	RunTimeAssert(!courseNameIndex.contains(course.getName()), Docs::courseNameConflictError);
	courses.insert({ courseCount,course });
	courseNameIndex.insert({ course.getName(),courseCount });
	++courseCount;
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

CmdResalt Server::setCourseGrade(const Student::LogicID& stuId, const Course::CourseID& courseId, const CourseSelectionRecord::GradeOfCourse& grade)
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
	auto CSRid = iteriter->second;
	courseSelectionRecords.erase(CSRid);
	iter->second.erase(iteriter);
	return CmdResalt(true, std::to_string(1) + Docs::removeSuccessNoteSuffix);
}

CmdResalt Server::removeCSR(const CourseSelectionRecord::CourseSelectionRecordID& CSRid)
{
	auto iter = courseSelectionRecords.find(CSRid);
	RunTimeAssert(iter != courseSelectionRecords.end(), Docs::CSRNotExit);
	return removeCourseSelectionRecord(iter->second.getStudent(), iter->second.getCourseID());
}

Server::IterPair<Server::ClassNameRecord::const_iterator> Server::getClassesList(void) const
{
	return std::pair(classes.begin(), classes.end());
}

Server::IterPair<Server::CoursesRecord::const_iterator> Server::getCoursesRecord(void) const
{
	return Server::IterPair<Server::CoursesRecord::const_iterator>(courses.begin(),courses.end());
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

const CourseSelectionRecord& Server::getCourseSelectionRecordByID(const CourseSelectionRecord::CourseSelectionRecordID& id)const
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

const Student::LogicID Server::getStudentLogicIdByID(const Student::ID& id) const
{
	auto iter = studentIdIndex.find(id);
	RunTimeAssert(iter != studentIdIndex.end(), Docs::studentIDNotExistError);
	return iter->second;
}

const Student::StudentClassLogicalID Server::getClassLogicalIdByClassName(const Student::StudentClassName& className) const
{
	auto iter = classNameIndex.find(className);
	RunTimeAssert(iter != classNameIndex.end(), Docs::studentClassNameNotExistError);
	return iter->second;
}
