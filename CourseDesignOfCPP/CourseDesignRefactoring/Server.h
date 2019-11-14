#pragma once
#include<map>
#include"User.h"
#include"Student.h"
#include"Course.h"
#include"CourseSelectionRecord.h"
#include"ThirdPartyLib/md5.h"
#include"Docs.h"

class Server
{
private:
	std::map<User::ID, User> admin;
	std::map<Student::ID, Student> students;
public:
	std::string serialize()const;
	template<class Is = stdIstream>
	static Server unSerializ(Is& is);
	template<class Is = stdIstream, class Os = stdOstream>
	static Server interactiveBuild(Is& is, Os& os);

};
