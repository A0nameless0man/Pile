#include "CourseSelectionRecord.h"

CourseSelectionRecord::CourseSelectionRecord
(
	User::LogicID student,
	CourseSelectionRecord::GradeOfCourse grade, 
	Course::CourseID course
):
	student(student),
	grade(grade),
	courseID(course)
{
}

CourseSelectionRecord::CourseSelectionRecord(const json& js) :
	UnSerialize(js,student),
	UnSerialize(js,grade),
	UnSerialize(js,courseID)
{
}

CourseSelectionRecord::GradeOfCourse CourseSelectionRecord::getGrade()const
{
	return grade;
}

void CourseSelectionRecord::setGrade(CourseSelectionRecord::GradeOfCourse newGrade)
{
	grade = newGrade;
}

Course::CourseID CourseSelectionRecord::getCourseID()const
{
	return courseID;
}

json CourseSelectionRecord::serialize() const
{
	json js;
	Serialize(js, student);
	Serialize(js, grade);
	Serialize(js, courseID);
	return js;
}

