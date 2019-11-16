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
	std::string logintype = iReader::InteractiveReader
		<
		std::string,
		iReader::WithIn<std::string>
		>
		("登陆类型", iReader::WithIn<std::string>({ "admin","student","a","s" }))
		.read(std::cin, std::cout);
	switch (logintype[0])
	{
	case 'a':
		return asAdmin();
		break;
	case 's':
		return asStudent();
		break;
	default:
		return -1;
		break;
	}

}
int test(void)
{
	Server myServer;
	myServer.addClass("2b");
	myServer.addStudent(Student(User("123", "hh"), 0, 2019));
	auto s = myServer.getStudentLogicIdByClass(
	myServer.getClassLogicalIdByClassName("2b")
	);
	for (auto i : s)
	{
		const Student& s = myServer.getStudentByLogicId(i);
		std::cout << s.serialize().dump(4) << std::endl;
		std::cout<<(std::string)myServer.removeStudentByLogicId(i) << std::endl;
	}
	std::cout << (std::string)myServer.loginAsUser("0", "admin") << std::endl;
	return 0;
}
int main(void)
{
	test();
	return 	__main__();

}