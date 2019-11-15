#pragma once
#include<vector>
#include<map>
#include"User.h"
#include"Student.h"
#include"Course.h"
#include"CourseSelectionRecord.h"
#include"ThirdPartyLib/md5.h"
#include"Docs.h"

class Server
{
public:
	enum class LoginType
	{
		admin, student
	};
	Server(const json& js);
	json serialize()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Server interactiveBuild(Is& is, Os& os);
private:
	std::map<User::LogicID, User> admin;
	std::map<Student::LogicID, Student> students;
	std::map<Student::StudentClassName, Student::LogicID> placementRecord;
	std::map<Course::CourseID, Course> courses;
	std::map
	<
		CourseSelectionRecord::CourseSelectionRecordID,
		CourseSelectionRecord
	>
		courseSelectionRecords;
};
