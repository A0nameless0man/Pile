#include "Course.h"

Course::Course(CourseName name, ClassHourOfCourse classHour) :
	myCourseName(name),
	classHourOfThisCourse(classHour)
{
}

Course::Course(const json& js) :
	UnSerialize(js,myCourseName),
	UnSerialize(js,classHourOfThisCourse)
{
}

Course::CourseName Course::getName() const
{
	return myCourseName;
}

void Course::setName(Course::CourseName newName)
{
	myCourseName = newName;
}

Course::ClassHourOfCourse Course::getClassHour() const
{
	return classHourOfThisCourse;
}

void Course::resetClassHour(Course::ClassHourOfCourse newClassHour)
{
	classHourOfThisCourse = newClassHour;
}

json Course::serialize() const
{
	json js;
	Serialize(js, myCourseName);
	Serialize(js, classHourOfThisCourse);
	return js;
}
