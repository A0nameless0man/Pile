#include"Format.h"

const std::map<char, std::string> TransformChar
{
	{'\\',"\\\\"},
	{'\n',"\\n"},
	{'\'',"\\\'"},
	{'\"',"\\\""},
	{'\r',"\\r"},
	{'\f',"\\f"},
	{'\v',"\\v"},
	{'\t',"\\t"}
};
const std::map<char, char> RevTransformChar
{
	{'\\','\\'},
	{'n','\n'},
	{'\'','\''},
	{'\"','\"'},
	{'r','\r'},
	{'f','\f'},
	{'v','\v'},
	{'t','\t'},
};

template<class T_1, class T_2>
std::string format(std::map<T_1, T_2> map)
{
	std::string res;
	res += "{";
	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		res += format(iter->first);
		res += ":";
		res += format(iter->second);
		res += ",";
	}
	//res.pop_back();//kill useless ','
	res += "}";
		return res;
}

template<class T>
std::string format(T dat)
{
	std::array<char, 100> str;
	auto [p, ec] = std::to_chars(str.data(), str.data() + str.size(), 42);
	if (ec == std::errc())
	{
		return std::string(str.data(), p - str.data());
	}
	else
	{
		throw ec;
	}
	//std::to_chars(str, str + 107, dat);
	//return std::string(str);
}

template<>
std::string format(std::string string)
{
	std::string res;
	res += "\"";
	for (auto c : string)
	{
		if (TransformChar.find(c) != TransformChar.end())
		{
			res += TransformChar.find(c)->second;
		}
		else
		{
			res += c;
		}
	}
	res += "\"";
	return res;
}

template<>
std::string format(char c)
{
	if (TransformChar.find(c) != TransformChar.end())
	{
		return "\'" + TransformChar.find(c)->second + "\'";
	}
	else
	{
		return "\'"+std::string(1,c)+"\'";
	}
}

template<class os = std::ostream>
os & test(os & o)
{
	return o << format(TransformChar) << std::endl;
}

int main(void)
{
	test(std::cout);
	system("pause");
	return 0;
}