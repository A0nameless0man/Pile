#include"DataType.h"
#include"md5.h"
#include"Docs.h"
#include"json.hpp"
Sex::Sex(enumSex sex):mySex(sex)
{
}

Sex::Sex(const json& js):mySex(js["sex"])
{
}

json Sex::serialize() const
{
	json js;
	js["sex"] = mySex;
	return std::move(js);
}

std::string Sex::to_string() const
{
	switch (mySex)
	{
	case enumSex::male:
		return "male";
		break;
	case enumSex::female:
		return "female";
		break;
	case enumSex::unknow:
		return "unknow";
		break;
	default:
		return "error";
		break;
	}
}
