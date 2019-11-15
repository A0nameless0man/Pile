#include"Student.h"
#include"ThirdPartyLib/md5.h"
#include"Docs.h"
#include"SerializationAid.h"

Student::Student(User user, StudentClassName className, StudentGrade startYear) :
	User(user),
	myClass(className),
	myStartYear(startYear)
{
}

Student::Student(const json& js) :
	UnSerialize(js, User),
	UnSerialize(js, myClass),
	UnSerialize(js, myStartYear)
{
}

Student::StudentClassName Student::getClass() const
{
	return myClass;
}

void Student::setClassName(Student::StudentClassName newClass)
{
	myClass = newClass;
}

Student::StudentGrade Student::getStartYear()const
{
	return myStartYear;
}

json Student::serialize() const
{
	json js;
	SerializeWithBaseClass(js, User, serialize());
	Serialize(js, myClass);
	Serialize(js, myStartYear);
	return js;
}
