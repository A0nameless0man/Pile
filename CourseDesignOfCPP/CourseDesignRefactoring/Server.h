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
	template <typename T>
	using IterPair = std::pair<T, T>;
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
	Server();//+
	Server(const json& js);
	json serialize()const;

	//login
	[[nodiscard]] CmdResalt loginAsStudent(const Student::ID& id, const Student::PWD& pwd)const;//?
	[[nodiscard]] CmdResalt loginAsUser(const User::ID& id, const User::PWD& pwd)const;//+

	//add
	[[maybe_unused]] CmdResalt addUser(const User& user);//+
	[[maybe_unused]] CmdResalt addStudent(const Student& student);//+
	[[maybe_unused]] CmdResalt addClass(const Student::StudentClassName& className);//+
	[[maybe_unused]] CmdResalt addCourseSelectionRecord(const Student::LogicID& stuId,const Course::CourseID& course);//+
	[[maybe_unused]] CmdResalt addCourse(const Course& course);//+

	//set
	[[nodiscard]] CmdResalt setPasswardOfUser(const User::ID& userId, const User::PWD& newPwd);//+
	[[nodiscard]] CmdResalt setPassWordOfStudent(const Student::LogicID& studentId, const Student::PWD & newPwd);//?
	[[nodiscard]] CmdResalt setCourseGrade(const Student::LogicID& stuId, const Course::CourseID& courseId,const CourseSelectionRecord::GradeOfCourse& grade);//?
	[[nodiscard]] CmdResalt setCourseGrade(const CourseSelectionRecord::CourseSelectionRecordID csrid,const CourseSelectionRecord::GradeOfCourse& grade);//?

	//remove
	[[nodiscard]] CmdResalt removeStudentByLogicId(const Student::LogicID& logicId);//+
	[[nodiscard]] CmdResalt removeCourseSelectionRecord(const Student::LogicID& stuId, const Course::CourseID& courseId);//?
	[[nodiscard]] CmdResalt removeCSR(const CourseSelectionRecord::CourseSelectionRecordID& CSRid);


	  //-----------------//
	 //getInfoByNothing//
	//---------------//
	[[nodiscard]] IterPair<ClassNameRecord::const_iterator> getClassesList(void)const;
	[[nodiscard]] Server::IterPair<Server::CoursesRecord::const_iterator> getCoursesRecord(void)const;


	//-----------//
	//getInfoByID//
	//-----------//

	[[nodiscard]] const Student& getStudentByLogicId(const Student::LogicID& id)const;//?
	[[nodiscard]] const Course& getCourseByCourseId(const Course::CourseID& id)const;//?
	[[nodiscard]] const Student::StudentClassName& getClassNameByClassID(const Student::StudentClassLogicalID& id)const;//?
	[[nodiscard]] const CourseSelectionRecord& getCourseSelectionRecordByID(const CourseSelectionRecord::CourseSelectionRecordID& id)const;//?

	//------------//
	//getIdByOther//
	//------------//

	//get all the stu in a class
	[[nodiscard]] const Server::StudentIdSet getStudentLogicIdByClass(const Student::StudentClassLogicalID& classid)const;//+

	//get CourseId by Course Name
	[[nodiscard]] const Course::CourseID getCourseIdByCourseName(const Course::CourseName& courseName)const;//+

	//get stuID by his or her name
	[[nodiscard]] const Server::StudentIdSet getStudentLogicIdByName(const Student::UserName& name)const;//+

	//get logicID by lieralID
	[[nodiscard]] const Student::LogicID getStudentLogicIdByID(const Student::ID& id)const;//+

	//get classID by Class name
	[[nodiscard]] const Student::StudentClassLogicalID getClassLogicalIdByClassName(const Student::StudentClassName& className)const;//+

	//get all the CSR this student has
	[[nodiscard]] const Server::CourseSelectionRecordIdSet getCourseSelectionRecordIdByStudentId(const Student::LogicID& stuId)const;//?

	//get CSR_ID by student and course
	[[nodiscard]] const CourseSelectionRecord::CourseSelectionRecordID getCourseSelectionRecordIdByStudentIdAndCourseID(const Student::LogicID& stuId, const Course::CourseID& courseId)const;//?
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

