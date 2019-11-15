#include"Student.h"
#include"ThirdPartyLib/md5.h"
#include"Docs.h"
#include"SerializationAid.h"

Student::Student(User user, StudentClassName className, StudentGrade startYear):
	User(user),
	myClass(className),
	myStartYear(startYear)
{
}

Student::Student(const json& js) :
	UnSerialize(js,User),
	UnSerialize(js,myClass),
	UnSerialize(js,myStartYear)
{
}

json Student::serialize() const
{
	json js;
	SerializeWithBaseClass(js, User, serialize());
	Serialize(js, myClass);
	Serialize(js, myStartYear);
	return js;
}
