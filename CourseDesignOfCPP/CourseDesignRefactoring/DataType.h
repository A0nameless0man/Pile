#pragma once
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include"ThirdPartyLib/json.hpp"
using json = nlohmann::json;
class Gender;
using stdIstream = std::basic_istream<char, std::char_traits<char> >;
using stdOstream = std::basic_ostream<char, std::char_traits<char> >;
using ID = std::string;
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
enum class enumGender
{
	male,female,unknow
};
class Gender
{
private:
	enumGender mySex;
public:
	Gender(enumGender sex = enumGender::unknow);
	Gender(const json& js);
	json serialize()const;
	std::string to_string()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Gender interactiveBuild(Is& is, Os& os);
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
	json serialize()const;
	std::string to_string()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Course interactiveBuild(Is& is, Os& os);
};
class User
{
private:
	Gender mySex;
	UserName myName;
	ID myID;
	PWD hashedPWD;
public:
	User(ID id, UserName name, Gender = Gender());
	UserName name()const;
	void setName(UserName newName);
	Gender sex()const;
	void setSex(Gender naeSex);
	ID id()const;
	bool login(PWD token)const;
	void setPWD(PWD newPWD);
	json serialize()const;
	std::string to_string()const;
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
	json serialize()const;
	std::string to_string()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Student interactiveBuild(Is& is, Os& os);
};

