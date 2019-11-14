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
private:
	using StudentClassName = std::string;
	using StudentGrade = size_t;
	StudentClassName myClass;
	StudentGrade myStartYear;
public:
	Student(User user, StudentClassName className, StudentGrade startYear);
	StudentClassName getClass()const;
	StudentGrade getStartYear();
	json serialize()const;
	std::string to_string()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Student interactiveBuild(Is& is, Os& os);
};

