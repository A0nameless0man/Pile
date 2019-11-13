#include"DataType.h"
IDVec operator&(const IDVec& a, const IDVec& b)
{
	IDVec aa = a, bb = b;
	std::sort(aa.begin(), aa.end());
	std::sort(bb.begin(), bb.end());
	auto ai = aa.begin();
	auto bi = bb.begin();
	IDVec ans;
	while (ai != aa.end() && bi != bb.end())
	{
		if (*ai == *bi)
		{
			ans.push_back(*ai);
			ai++;
			bi++;
		}
		else
		{
			if (*ai > * bi)
			{
				bi++;
			}
			else
			{
				ai++;
			}
		}

	}
	return ans;
}

IDVec operator|(const IDVec& a, const IDVec& b)
{
	IDset aa(a.begin(), a.end());
	for (auto p : b)
	{
		aa.insert(p);
	}
	IDVec ans(aa.begin(), aa.end());
	return ans;
}
PWD hash(const PWD& in)
{
	return MD5(in + "salt").md5();
}