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
	using StudentIdSet = std::set<Student::LogicID>;
	using CourseSelectionRecordIdSet = std::set< CourseSelectionRecord::CourseSelectionRecordID>;

	using AdminRecord = std::map<User::ID, User>;
	using StudentRecord = std::map<Student::LogicID, Student>;
	using CoursesRecord = std::map<Course::CourseID, Course>;
	using CourseSelectionRecords = std::map<CourseSelectionRecord::CourseSelectionRecordID, CourseSelectionRecord>;
	using ClassNameRecord = std::map<Student::StudentClassLogicalID, Student::StudentClassName>;

	using ClassNameIndex = std::map<Student::StudentClassName, Student::StudentClassLogicalID>;
	using PlacementIndex = std::map<Student::StudentClassLogicalID, std::set<Student::LogicID>>;
	using StudentNameIndex = std::map<Student::UserName, std::set<Student::LogicID>>;//允许重名学生
	using CourseNameIndex = std::map<Course::CourseName, Course::CourseID>;
	using StudentIdIndex = std::map<Student::ID, Student::LogicID>;
	using CourseSelectionIndex = std::map<Student::LogicID,std::map<Course::CourseID, CourseSelectionRecord::CourseSelectionRecordID>>;
	enum class LoginType
	{
		admin, student
	};
	Server();
	Server(const json& js);
	json serialize()const;

	//login
	[[nodiscard]] CmdResalt loginAsStudent(const Student::ID& id, const Student::PWD& pwd)const;
	[[nodiscard]] CmdResalt loginAsUser(const User::ID& id, const User::PWD& pwd)const;

	//add
	[[maybe_unused]] CmdResalt addStudent(const Student& student);
	[[maybe_unused]] CmdResalt addClass(const Student::StudentClassName& className);

	//remove
	[[nodiscard]] CmdResalt removeStudentById(const Student::ID& id);
	[[nodiscard]] CmdResalt removeStudentByLogicId(const Student::LogicID& logicId);

	//getByID
	[[nodiscard]] const CourseSelectionRecord::CourseSelectionRecordID getCourseSelectionRecordIdByStudentIdAndCourseID(const Student::LogicID& stuId, const Course::CourseID& courseId)const;
	[[nodiscard]] const Server::CourseSelectionRecordIdSet getCourseSelectionRecordIdByStudentId(const Student::LogicID& stuId)const;
	[[nodiscard]] const Server::StudentIdSet getStudentLogicIdByClass(const Student::StudentClassLogicalID& classid)const;
	[[nodiscard]] const Student getStudentByLogicId(const Student::LogicID& id)const;

	//getByOther
	[[nodiscard]] const Course::CourseID getCourseIdByCourseName(const Course::CourseName& courseName)const;
	[[nodiscard]] const Server::StudentIdSet getStudentLogicIdByName(const Student::UserName& name)const;
	[[nodiscard]] const Server::StudentIdSet getStudentLogicIdByID(const Student::ID& id)const;
private:
	//Section 1: data
	AdminRecord admin;

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
	CourseNameIndex courseNameIndex;
	CourseSelectionIndex courseSelectionIndex;
};

