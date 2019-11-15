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
	enum class LoginType
	{
		admin, student
	};
	Server(const json& js);
	json serialize()const;
	CmdResalt addStudent(const Student& student);
private:
	//Section 1: data
	std::map<User::LogicID, User> admin;
	User::LogicID adminCount;

	std::map<Student::LogicID, Student> students;
	Student::LogicID studentCount;

	std::map<Course::CourseID, Course> courses;
	Course::CourseID courseCount;

	std::map<CourseSelectionRecord::CourseSelectionRecordID, CourseSelectionRecord>courseSelectionRecords;
	CourseSelectionRecord::CourseSelectionRecordID courseSelectionCount;

	std::map<Student::StudentClassLogicalID, Student::StudentClassName> classes;
	Student::StudentClassLogicalID classesCount;

	//Section 2 : indexs
	std::multimap<Student::StudentClassLogicalID, Student::LogicID> placementRecord;
	std::multimap<Student::UserName, Student::LogicID> studentNameRecord;
	std::map<Student::ID, Student::LogicID> studentIDRecord;
};

