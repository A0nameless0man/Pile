#pragma once
#include <vector>
#include <set>
#include "DataType.h"

using IDVec = std::vector<ID>;
using IDset = std::set<ID>;

class Condition
{
public:
	Condition(const std::string& str);
	Condition(std::string&& str);
	bool operator()(const Student& student)const;
	template<class Is = stdIstream, class Os = stdOstream>
	static Condition interactiveBuild(Is& is, Os& os);
private:

};
