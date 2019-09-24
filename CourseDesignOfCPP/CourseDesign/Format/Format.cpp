
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

template<class Key, class Val, class Map>
std::string format(Map map)
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
	res.pop_back();//kill useless ','
	res += "}";
	return res;
}

template<class T>
std::string format(T dat)
{
	return std::to_string(dat);
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
		return "\'" + std::string(1, c) + "\'";
	}
}

template<class Key, class Val, class Is, class Map>
Is& deFormatMap(Is& is, Map& map)
{
	if (is.peek() == '{')
	{
		is.get();
	}
	while (is.peek() != '}')
	{
		Key key;
		Val val;
		deFormat(is, key);
		if (is.peek() == ':')
		{
			is.get();
		}
		deFormat(is, val);
		if (is.peek() == ',')
		{
			is.get();
		}
		map.insert(std::pair<Key, Val>(key, val));
	}
	is.get();
	return is;
}

template<class T, class Is>
Is& deFormat(Is& is, T& t)
{
	is >> t;
	return is;
}

template<class Is>
Is& deFormat(Is& is, char& c)
{
	if (is.peek() == '\'')
	{
		is.get();
	}
	if (is.peek() == '\\')
	{
		is.get();
		if (RevTransformChar.find(is.peek()) != RevTransformChar.end())
		{
			c = RevTransformChar.find(is.peek())->second;
		}
		is.get();
	}
	else
	{
		c = is.get();
	}
	if (is.peek() == '\'')
	{
		is.get();
	}
	return is;
}

template<class Is>
Is& deFormat(Is& is, std::string& str)
{
	if (is.peek() == '\"')
	{
		is.get();
	}
	while (is.peek() != '\"')
	{
		char c;
		deFormat(is, c);
		str.push_back(c);
	}
	is.get();
	return is;
}

//int main(void)
//{
//	std::map<std::string, std::string> map;
//	std::stringstream ss("{\"name\":\"Rufus\",\"age\":\"15\"}");
//	deFormatMap<std::string, std::string>(ss, map);
//	std::cout << format<int, int>(map) << std::endl;
//}