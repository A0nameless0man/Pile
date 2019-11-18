#include<iostream>
#include<map>
#include"User.h"
#include"Student.h"
#include"Docs.h"
#include"Server.h"
#include "ThirdPartyLib/colourStream.h"
#include"interactiveReader.h"

//#include<windows.h>
const int BUF_SIZE = 128 * 1024;
char buf[BUF_SIZE];
//Server::StudentIdSet selectStudent(const Server& server)
//{
//
//}
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
	using namespace kerbal::utility::costream;
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
	//test();
	return 	__main__();

}