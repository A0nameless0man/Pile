#pragma once
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include"User.h"
#include"SerializationAid.h"



class Student :public User
{
public:
	using StudentClassName = std::string;
	using StudentGrade = size_t;
	Student(User user, StudentClassName className, StudentGrade startYear);
	Student(const json& js);
	StudentClassName getClass()const;
	StudentGrade getStartYear();
	json serialize()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Student interactiveBuild(Is& is, Os& os);
private:
	StudentClassName myClass;
	StudentGrade myStartYear;
};

