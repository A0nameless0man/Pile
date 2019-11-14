#pragma once
#include<string>
#include"SerializationAid.h"
using ID = std::string;
using PWD = std::string;
using UserName = std::string;
class User;
PWD hash(const PWD& in);
enum class enumGender
{
	male, female, unknow
};
class Gender
{
private:
	enumGender mySex;
public:
	Gender(enumGender sex = enumGender::unknow);
	Gender(const json& js);
	json serialize()const;
	std::string to_string()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Gender interactiveBuild(Is& is, Os& os);
};

class User
{
private:
	Gender mySex;
	UserName myName;
	ID myID;
	PWD hashedPWD;
public:
	User(ID id, UserName name, Gender = Gender());
	UserName name()const;
	void setName(UserName newName);
	Gender sex()const;
	void setSex(Gender naeSex);
	ID id()const;
	bool login(PWD token)const;
	void setPWD(PWD newPWD);
	json serialize()const;
	std::string to_string()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static User interactiveBuild(Is& is, Os& os);
};