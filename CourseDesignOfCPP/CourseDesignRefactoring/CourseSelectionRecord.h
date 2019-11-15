#pragma once
#include"Course.h"
#include"User.h"
class CourseSelectionRecord
{
public:
	using CourseSelectionRecordID = unsigned long long;
	using GradeOfCourse = double;
	CourseSelectionRecord(User::LogicID student,CourseSelectionRecord::GradeOfCourse grade, Course::CourseID course);
	CourseSelectionRecord(const json& js);
	CourseSelectionRecord::GradeOfCourse getGrade();
	void setGrade(CourseSelectionRecord::GradeOfCourse newGrade);
	Course::CourseID getCourseID();
	json serialize()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Course interactiveBuild(Is& is, Os& os);
private:
	User::LogicID student;
	GradeOfCourse grade;
	Course::CourseID courseID;
};

