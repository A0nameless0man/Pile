#define _CRT_SECURE_NO_WARNINGS//shut up MS//NOT fo CPP//scanf VS. scanf_s
//#define DEBUG
#include<stdio.h>
#include<iostream>//stream
#include<sstream>//stringstream
#include<fstream>//file
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<string>
#include<algorithm>
//STL
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
//STL
#ifdef DEBUG
#include<Windows.h>//sleep()
#include<stdlib.h>//system("pause")
#endif // DEBUG

//template <typename T> void swap(T &a, T &b)
//{
//	T t = a;
//	a = b;
//	b = t;
//}
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int MAX_N = 10007;
int n, m, a, b, j, k;
const int habb_year = 365;
const int Tzoljin_year = 13 * 20;
const string habb_Mouhth[] = { "pop","no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu" ,"uayet"};
const string Tzolkin_Mounth[] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt",std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG
	map<string, int> Habb_Mounth;
	for (int i = 0; i < 19; i++)
	{
		Habb_Mounth.insert(pair<string,int>(habb_Mouhth[i], i));
	}
	while (std::cin>>n)
	{
		long long a;
		string b;
		long long c;
		for (int i = 0; i < n; i++)
		{
			std::cin >> a >> b >> c;
			long long day = c * habb_year + Habb_Mounth[b] * 20 + a;
			std::cout << day % Tzoljin_year % 13 +1<< ' ' << Tzolkin_Mounth[day % Tzoljin_year % 20] << ' ' << day / Tzoljin_year << std::endl;
		}
	}
#ifdef DEBUG
	system("pause");
	Sleep(-1);
#endif // DEBUG
	return 0;
}
