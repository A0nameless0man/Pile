#pragma once
#include<string>
#include"SerializationAid.h"

//using Course = std::pair<CourseName, ScoreOnOneCourse>;
class Course
{
public:
	using CourseID = unsigned long long;
	using ClassHourOfCourse = double;
	using CourseName = std::string;
	Course(CourseName name,ClassHourOfCourse classHour = 1.0);
	CourseName getName()const;
	void setName(CourseName newName);
	ClassHourOfCourse getClassHour()const;
	void resetClassHour(ClassHourOfCourse newClassHour);
	json serialize()const;
	std::string to_string()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Course interactiveBuild(Is& is, Os& os);
private:
	CourseName myCourseName;
	ClassHourOfCourse classHourOfThisCourse;

};