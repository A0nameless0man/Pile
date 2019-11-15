#include"Server.h"
CmdResalt Server::addStudent(const Student& student)
{
	RunTimeAssert(!studentIDRecord.contains(student.getID), Docs::studentIDconfilctNote);

}
