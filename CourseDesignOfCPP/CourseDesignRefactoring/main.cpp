#include<iostream>
#include<map>
#include"User.h"
#include"Student.h"
#include"Docs.h"
#include"Server.h"
#include "ThirdPartyLib/colourStream.h"
#include"interactiveReader.h"

using namespace kerbal::utility::costream;
class Quit
{
};

//select

template<typename OS ,typename IS>
Student::StudentClassLogicalID selectClass(const Server& server,OS&os = std::cout,IS&is = std::cin)
{
	while (true)try
	{
		auto m = iReader::InteractiveReader<std::string>().read(is, os, "选择班级的方法", iReader::WithIn<std::string>({ "List","Name","Quit" }), iReader::StdIstreamStringReader());
		switch (m[0])
		{
		case 'N':
		{
			auto s = iReader::InteractiveReader<Student::StudentClassName>().read(is,os, "班级的名字", iReader::NoRestrict<Student::StudentClassName>(), iReader::StdIstreamStringReader());
			return server.getClassLogicalIdByClassName(s);
		}
		case 'L':
		{
			auto pair = server.getClassesList();
			for (auto i = pair.first; i != pair.second; i++)
			{
				costream<os>(LIGHT_BLUE) << i->first << " " << i->second << std::endl;
			}
		}
		default:
			throw Quit();
			break;
		}
	}
	catch (CmdResalt & res)
	{
		costream<os>(LIGHT_RED) << res.operator const std::string & () << std::endl;
	}
}
Server::StudentIdSet selectStudent(const Server& server)
{
	while (true)
	{
		auto s = iReader::InteractiveReader<std::string>().read(std::cin, std::cout, "选择学生的条件", iReader::WithIn<std::string>({ "ID","Name","Class","Quit" }), iReader::StdIstreamStringReader());
		try
		{
			switch (s[0])
			{
			case 'I':
				return Server::StudentIdSet({ server.getStudentLogicIdByID(iReader::InteractiveReader<Student::ID>().read(std::cin,std::cout,"学生的ID",iReader::NoRestrict<Student::ID>(),iReader::StdIstreamStringReader())) });
				break;
			case 'N':
				return server.getStudentLogicIdByName(iReader::InteractiveReader<Student::UserName>().read(std::cin, std::cout, "学生的姓名", iReader::NoRestrict<Student::UserName>(), iReader::StdIstreamStringReader()));
				break;
			case 'C':
				return server.getStudentLogicIdByClass(selectClass(server));
			default:
				throw Quit();
				break;
			}
		}
		catch (CmdResalt & res)
		{
			costream<std::cout>(LIGHT_RED) << res.operator const std::string & () << std::endl;
		}
	}

}
Course::CourseID selectCourse(const Server& server)
{

}
//brif
template<typename OS>
void oneLineBrifOnStudent(const Server& server, const Student::LogicID& id, OS& os)
{
	auto& s = server.getStudentByLogicId(id);
	os << "姓名:\t" << s.getName() << ",\t" << "学号:\t" << s.getID() << std::endl;
}
template<typename OS>
void brifOnStudent(const Server& server, const Student::LogicID& id, OS& os)
{
	auto& s = server.getStudentByLogicId(id);
	auto CSR = server.getCourseSelectionRecordIdByStudentId(id);
	auto className = server.getClassNameByClassID(s.getClass());
	os << "姓名:\t" << s.getName() << std::endl;
	os << "学号:\t" << s.getID() << std::endl;
	os << "班级:\t" << className << std::endl;
	os << "性别:\t" << s.getGender().to_string() << std::endl;;
	os << "入学年份:\t" << s.getStartYear() << std::endl;
	os << "成绩:\n" << std::endl;
	CourseSelectionRecord::GradeOfCourse sumGrade = 0;
	Course::ClassHourOfCourse sumClassHour = 0;
	for (auto i : server.getCourseSelectionRecordIdByStudentId(id))
	{
		const auto& csr = server.getCourseSelectionRecordByID(i);//csr for CourseSelectionRecord
		const auto& course = server.getCourseByCourseId(csr.getCourseID());
		sumGrade += csr.getGrade() * course.getClassHour();
		sumClassHour += course.getClassHour();
		os << "\t" << course.getName() << " : \t" << csr.getGrade() << std::endl;
	}
	if (sumClassHour > 0.5)
		os << "\t平均成绩:" << sumGrade / sumClassHour << std::endl;

}	template<typename OS>
void brifOfClass(const Server& server, const Student::StudentClassLogicalID& id, OS& os)
{
	auto& className = server.getClassNameByClassID(id);
	auto students = server.getStudentLogicIdByClass(id);
	os << "班级:\t" << className << std::endl;
	for (auto s : students)
	{
		oneLineBrifOnStudent(server, s, os);
	}
}


int asStudent(void)
{
	return 1;
}
int asAdmin(void)
{
	return 2;
}
int __main__(void)
{
	Server myServer;
	auto s = iReader::InteractiveReader<std::string>().read(std::cin, std::cout, "登陆名", iReader::WithIn<std::string>({ "s","student","a","admin" }), iReader::StdIstreamStringReader());
	costream<std::cout>(LIGHT_RED) << s << std::endl;
	return 0;
}
int test(void)
{
	Server myServer;
	std::cout << "start" << std::endl;
	myServer.addClass("2b");
	myServer.addStudent(Student(User("123", "hh"), 0, 2019));
	myServer.addCourse(Course("lm", 1.0));
	myServer.addCourseSelectionRecord(*(myServer.getStudentLogicIdByName("hh").begin()), myServer.getCourseIdByCourseName("lm"));
	for (auto s : selectStudent(myServer))
		brifOnStudent(myServer, s, std::cout);
	auto s = myServer.getStudentLogicIdByClass(
		myServer.getClassLogicalIdByClassName("2b")
	);


	costream<std::cout>(LIGHT_RED) << Server(myServer.serialize()).serialize().dump(4) << std::endl;
	std::cout << myServer.serialize().dump(4) << std::endl;
	return 0;
}
int main(void)
{
	while (true)
		test();
	return 	__main__();

}