#include<iostream>
#include<map>
#include"User.h"
#include"Student.h"
#include"Docs.h"
#include"Server.h"
#include "ThirdPartyLib/colourStream.h"
#include"interactiveReader.h"

using namespace kerbal::utility::costream;
Student::StudentClassLogicalID selectClass(const Server& server)
{
	while(true)try
	{
		auto m = iReader::InteractiveReader<std::string>().read(std::cin, std::cout, "选择班级的方法", iReader::WithIn<std::string>({ "List","Name","Quit" }), iReader::StdIstreamStringReader());
		switch (m[0])
		{
		case 'N':
		{
			auto s = iReader::InteractiveReader<Student::StudentClassName>().read(std::cin, std::cout, "班级的名字", iReader::NoRestrict<Student::StudentClassName>(), iReader::StdIstreamStringReader());
			return server.getClassLogicalIdByClassName(s);
		}
		case 'L':
		{
			auto pair = server.getClassesList();
			for (auto i = pair.first; i != pair.second; i++)
			{
				costream<std::cout>(LIGHT_BLUE) << i->first << " " << i->second << std::endl;
			}
		}
		default:
			break;
		}
	}
	catch (CmdResalt & res)
	{
		costream<std::cout>(LIGHT_RED) << res.operator const std::string & () << std::endl;
	}
}
Server::StudentIdSet selectStudent(const Server& server)
{
	while (true)
	{
		auto s = iReader::InteractiveReader<std::string>().read(std::cin, std::cout, "选择学生的条件", iReader::WithIn<std::string>({ "ID","Name","Class","Quit"}), iReader::StdIstreamStringReader());
		try
		{
			switch (s[0])
			{
			case 'I':
				return Server::StudentIdSet({ server.getStudentLogicIdByID(iReader::InteractiveReader<Student::ID>().read(std::cin,std::cout,"学生的ID",iReader::NoRestrict<Student::ID>(),iReader::StdIstreamStringReader())) });
				break;
			case 'N':
				return server.getStudentLogicIdByName(iReader::InteractiveReader<Student::UserName>().read(std::cin,std::cout,"学生的姓名",iReader::NoRestrict<Student::UserName>(),iReader::StdIstreamStringReader()));
				break;
			case 'C':
				return server.getStudentLogicIdByClass(selectClass(server));
			default:
				break;
			}
		}
		catch(CmdResalt& res)
		{
			costream<std::cout>(LIGHT_RED) << res.operator const std::string & () << std::endl;
		}
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
	myServer.addCourse(Course("lm",1.0));
	myServer.addCourseSelectionRecord(*(myServer.getStudentLogicIdByName("hh").begin()), myServer.getCourseIdByCourseName("lm"));
	selectStudent(myServer);
	auto s = myServer.getStudentLogicIdByClass(
	myServer.getClassLogicalIdByClassName("2b")
	);
	using namespace kerbal::utility::costream;
	costream<std::cout>(LIGHT_RED) << Server(myServer.serialize()).serialize().dump(4) << std::endl;
	std::cout << myServer.serialize().dump(4) << std::endl;
	return 0;
}
int main(void)
{
	while(true)
	test();
	return 	__main__();

}