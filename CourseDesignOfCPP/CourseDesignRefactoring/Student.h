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
	using StudentClassLogicalID = unsigned long long;
	using StudentClassName = std::string;
	using StudentGrade = size_t;
	Student(User user, StudentClassLogicalID className, StudentGrade startYear);
	Student(const json& js);
	Student::StudentClassLogicalID getClass()const;
	void setClassName(Student::StudentClassLogicalID newClass);
	Student::StudentGrade getStartYear()const;
	json serialize()const;
private:
	StudentClassLogicalID myClass;
	StudentGrade myStartYear;
};

