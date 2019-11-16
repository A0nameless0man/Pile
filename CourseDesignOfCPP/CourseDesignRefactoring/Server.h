#pragma once
#include<vector>
#include<map>
#include"User.h"
#include"Student.h"
#include"Course.h"
#include"CourseSelectionRecord.h"
#include"ThirdPartyLib/md5.h"
#include"Docs.h"
#include"myAssert.h"

class Server
{
public:
	using AdminRecord = std::map<User::LogicID, User>;
	using StudentRecord = std::map<Student::LogicID, Student>;
	using CoursesRecord = std::map<Course::CourseID, Course>;
	using CourseSelectionRecords = std::map<CourseSelectionRecord::CourseSelectionRecordID, CourseSelectionRecord>;
	using ClassNameRecord = std::map<Student::StudentClassLogicalID, Student::StudentClassName>;
	using ClassNameIndex = std::map<Student::StudentClassName, Student::StudentClassLogicalID>;
	using PlacementIndex = std::multimap<Student::StudentClassLogicalID, Student::LogicID>;
	using StudentNameIndex = std::multimap<Student::UserName, Student::LogicID>;
	using StudentIdIndex = std::map<Student::ID, Student::LogicID>;
	enum class LoginType
	{
		admin, student
	};
	Server();
	Server(const json& js);
	json serialize()const;
	CmdResalt addStudent(const Student& student);
	CmdResalt addClass(const Student::StudentClassName& className);
	CmdResalt removeStudentById(const Student::ID& id);
	CmdResalt removeStudentByName(const Student::UserName& name);

private:
	//Section 1: data
	AdminRecord admin;
	User::LogicID adminCount;

	StudentRecord students;
	Student::LogicID studentCount;

	CoursesRecord courses;
	Course::CourseID courseCount;

	CourseSelectionRecords courseSelectionRecords;
	CourseSelectionRecord::CourseSelectionRecordID courseSelectionCount;

	ClassNameRecord classes;
	Student::StudentClassLogicalID classesCount;

	//Section 2 : indexs
	ClassNameIndex classNameIndex;
	PlacementIndex placementIndex;
	StudentNameIndex studentNameIndex;
	StudentIdIndex studentIdIndex;
};

