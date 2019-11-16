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
	Gender(enumGender gender = enumGender::unknow);
	Gender(const json& js);
	json serialize()const;
	std::string to_string()const;
private:
	enumGender myGender;
};

class User
{
public:
	using LogicID = unsigned long long;
	using ID = std::string;
	using PWD = std::string;
	using UserName = std::string;
	User(ID id, UserName name, Gender gender = Gender());
	User(const json& js);
	User::UserName getName()const;
	void setName(User::UserName newName);
	Gender getGender()const;
	void setGender(Gender newGender);
	User::ID getID()const;
	bool login(User::PWD token)const;
	void setPWD(User::PWD newPWD);
	json serialize()const;
private:
	Gender myGender;
	UserName myName;
	ID myID;
	PWD hashedPWD;
};

User::PWD hash(const User::PWD& in);