#include"Condition.h"

#include <algorithm>

IDVec operator&(const IDVec& a, const IDVec& b)
{
	IDVec aa = a, bb = b;
	std::sort(aa.begin(), aa.end());
	std::sort(bb.begin(), bb.end());
	IDVec ret;
	std::set_intersection(aa.begin(), aa.end(), bb.begin(), bb.end(), std::back_inserter(ret));
	return ret;
}

IDVec operator|(const IDVec& a, const IDVec& b)
{
	IDset aa(a.begin(), a.end());
	aa.insert(b.cbegin(), b.cend());
	IDVec ans(aa.begin(), aa.end());
	return ans;
}