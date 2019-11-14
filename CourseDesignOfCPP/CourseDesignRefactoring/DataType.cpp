#include"DataType.h"
#include"ThirdPartyLib/md5.h"
#include"Docs.h"
#include"ThirdPartyLib/json.hpp"
Gender::Gender(enumGender sex):mySex(sex)
{
}

Gender::Gender(const json& js):mySex(js["gender"])
{
}

json Gender::serialize() const
{
	json js;
	js["gender"] = mySex;
	return js;
}

std::string Gender::to_string() const
{
	switch (mySex)
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
