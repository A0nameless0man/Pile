#pragma once
#include<map>
#include"DataType.h"
#include"md5.h"
#include"Docs.h"
class Server;
class Condition;
class Server
{
private:
	std::map<ID, User> admin;
	std::map<ID, Student> students;
public:
	bool containsStudent(const ID& id)const;
	Student& getStudent(const ID& id);
	void setStudent(const Student& student);
	void setStudent(Student&& student);
	bool containsUser(const ID& id)const;
	User& getUser(const ID& id);
	void setUser(const User& user);
	void setUser(User&& user);
	bool loginAsUser(const ID& id, const PWD& pwd)const;
	bool loginAsStudent(const ID& id, const PWD& pwd)const;
	std::string serialize()const;
	template<class Is = stdIstream>
	static Server unSerializ(Is& is);
	template<class Is = stdIstream, class Os = stdOstream>
	static Server interactiveBuild(Is& is, Os& os);

};
class Condition
{
public:
	Condition(const std::string& str);
	Condition(std::string&& str);
	bool operator()(const Student& student)const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Condition interactiveBuild(Is& is, Os& os);
private:
	/*Not Ready Yet*/
};