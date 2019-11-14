#pragma once
#include<string>
#include"SerializationAid.h"

enum class enumGender
{
	male, female, unknow
};
class Gender
{
public:
	Gender(enumGender sex = enumGender::unknow);
	Gender(const json& js);
	json serialize()const;
	std::string to_string()const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Gender interactiveBuild(Is& is, Os& os);
private:
	enumGender mySex;
};

class User
{
public:
	using ID = std::string;
	using PWD = std::string;
	using UserName = std::string;
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
private:
	Gender mySex;
	UserName myName;
	ID myID;
	PWD hashedPWD;
};

User::PWD hash(const User::PWD& in);