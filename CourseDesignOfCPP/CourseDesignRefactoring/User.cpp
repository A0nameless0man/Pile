#include "User.h"
#include "Docs.h"
#include "ThirdPartyLib/md5.h"
Gender::Gender(enumGender gender): myGender(gender) {}

Gender::Gender(const std::string &str)
{
    if(str == "male" || str == "Male")
    {
        myGender = enumGender::male;
    }
    else if(str == "female" || str == "Female")
    {
        myGender = enumGender::female;
    }
    else
    {
        myGender = enumGender::unknow;
    }
}

Gender::Gender(const json &js): myGender(js["gender"]) {}

json Gender::serialize() const
{
    json js;
    js["gender"] = myGender;
    return js;
}

std::string Gender::to_string() const
{
    switch(myGender)
    {
        case enumGender::male:
            return "male";
            break;
        case enumGender::female:
            return "female";
            break;
        case enumGender::unknow:
            return "unknow";
            break;
        default:
            return "error";
            break;
    }
}
User::PWD hash(const User::PWD &in)
{
    return MD5(in + Docs::hashSalt).md5();
}

User::User(ID id, UserName name, Gender gender): myID(id), myName(name), myGender(gender)
{
    hashedPWD = hash("user");
}

User::User(const json &js):
    UnSerialize(js, myID),
    UnSerialize(js, myName),
    UnSerialize(js, myGender),
    UnSerialize(js, hashedPWD)
{
}

User::UserName User::getName() const
{
    return myName;
}

void User::setName(User::UserName newName)
{
    myName = newName;
}

Gender User::getGender() const
{
    return myGender;
}

void User::setGender(Gender newGender)
{
    myGender = newGender;
}

User::ID User::getID() const
{
    return myID;
}

bool User::login(User::PWD token) const
{
    return hash(token) == hashedPWD;
}

void User::setPWD(User::PWD newPWD)
{
    hashedPWD = hash(newPWD);
}

json User::serialize() const
{
    json js;
    SerializeWithMethod(js, myGender, serialize());
    Serialize(js, myID);
    Serialize(js, myName);
    Serialize(js, hashedPWD);
    return js;
}
