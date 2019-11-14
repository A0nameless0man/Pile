#pragma once
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
class Sex;
using stdIstream = std::basic_istream<char, std::char_traits<char> >;
using stdOstream = std::basic_ostream<char, std::char_traits<char> >;
using ID = std::string;
using IDVec = std::vector<ID>;
using IDset = std::set<ID>;
using PWD = std::string;
using UserName = std::string;
class User;
using PointOfExam = double;
using ClassHourOfCourse = double;
using CourseName = std::string;
class Course;
//using Course = std::pair<CourseName, ScoreOnOneCourse>;
using CoursesRecord = std::map<CourseName, Course>;
using StudentClassName = std::string;
using StudentGrade = size_t;
class Student;


PWD hash(const PWD& in);
enum enumSex
{
	male,female,unknow
};
class Sex
{
private:
	enumSex mySex;
public:
	Sex(enumSex sex = unknow);
	std::string serialize()const;
	template<class Is = stdIstream>
	static Sex unSerializ(Is& is);
	template<class Is = stdIstream, class Os = stdOstream>
	static Sex interactiveBuild(Is& is, Os& os);
};
class Course
{
private:
	CourseName myCourseName;
	PointOfExam pointOnThisCourse;
	ClassHourOfCourse classHourOfThisCourse;
public:
	Course(CourseName name, PointOfExam point, ClassHourOfCourse classHour = 1.0);
	CourseName name()const;
	void setName(CourseName newName);
	PointOfExam getPoint()const;
	void resetPoint(PointOfExam newPoint);
	ClassHourOfCourse getClassHour()const;
	void resetClassHour(ClassHourOfCourse newClassHour);
	std::string serialize()const;
	template<class Is = stdIstream>
	static Course unSerializ(Is& is);
	template<class Is = stdIstream, class Os = stdOstream>
	static Course interactiveBuild(Is& is, Os& os);
};
class User
{
private:
	Sex mySex;
	UserName myName;
	ID myID;
	PWD hashedPWD;
public:
	User(ID id, UserName name, Sex = Sex());
	UserName name()const;
	void setName(UserName newName);
	Sex sex()const;
	void setSex(Sex naeSex);
	ID id()const;
	bool login(PWD token)const;
	void setPWD(PWD newPWD);
	std::string serialize()const;
	template<class Is = stdIstream>
	static User unSerializ(Is& is);
	template<class Is = stdIstream, class Os = stdOstream>
	static User interactiveBuild(Is& is, Os& os);
};
class Student :public User
{
private:
	CoursesRecord myCourseRecord;
	StudentClassName myClass;
	StudentGrade myStartYear;
public:
	Student(User user, StudentClassName className, StudentGrade startYear);
	const CoursesRecord& getCoureseRecord()const;
	Course getCouresByName(CourseName courseName)const;
	void containsCourse(const CourseName& courseName)const;
	void setCourse(const Course& newCourse);
	void setCourse(Course&& newCourse);
	StudentClassName getClass()const;
	StudentGrade getStartYear();
	std::string serialize()const;
	template<class Is = stdIstream>
	static Student unSerializ(Is& is);
	template<class Is = stdIstream, class Os = stdOstream>
	static Student interactiveBuild(Is& is, Os& os);
};
