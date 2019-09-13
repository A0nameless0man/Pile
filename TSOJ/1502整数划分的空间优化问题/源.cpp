#define _CRT_SECURE_NO_WARNINGS//shut up MS//NOT fo CPP//scanf VS. scanf_s
//#define DEBUG
//#define InFile
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
#ifdef InFile
#include<Windows.h>//sleep()
#include<stdlib.h>//system("pause")
#endif // InFile
#ifdef DEBUG
#define Check(X) std::cout<<"Express \""<<#X<<"\" is "<<(X)<<std::endl
#else 
#define Check(X) ;
#endif
//template <typename T> void swap(T &a, T &b)
//{
//	T t = a;
//	a = b;
//	b = t;
//}
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int MAX_N = 20007;
const LL MOD = 100000007;
int n, m, a, b, j, k;
//int table[MAX_N][MAX_N];
//ULL f(ULL tar, ULL lim)
//{
//	if (tar<2000&&lim<2000)
//	{
//		return table[tar][lim];
//	}
//	if (tar == 0)
//	{
//		return 0;
//	}
//	if (tar == 1)
//	{
//		return 1;
//	}
//	if (lim == 0)
//	{
//		return 0;
//	}
//	if (lim >= tar)
//	{
//		return f(tar, tar - 1) + 1;
//	}
//	[[likely]] return (f(tar - lim, lim) + f(tar, lim - 1)) % MOD;
//}
LL tab[MAX_N] = { 0 };
LL p(LL n)
{
	if (n >= 0)
	{
		if (tab[n] != 0)return tab[n];
		else
		{
			LL ans = 0;
			for (LL k = 1; k <= n; k++)
			{
				LL set = (p(n - ((k) * (3 * k - 1)) / 2) + p(n - ((k) * (3 * k + 1)) / 2));
				if (set == 0)break;
				if (k & 1)
				{
					ans += set;
				}
				else
				{
					ans -= set;
				}
				ans = (ans + MOD) % MOD;
			}
			return tab[n] = ans;
		}
	}
	else
	{
		return 0;
	}
}
int main(void)
{
#ifdef InFile
	std::fstream fin;
	fin.open("./in.txt", std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // InFile

	//n = 2000;
	//for (int i = 0; i <= n; i++)
	//{
	//	table[0][i] = 0;

	//	table[i][0] = 0;
	//	table[1][i] = 1;
	//}
	//for (int tar = 2; tar <= n; tar++)
	//{
	//	for (int lim = 1; lim < tar; lim++)
	//	{
	//		table[tar][lim] = (table[tar - lim][lim] + table[tar][lim - 1]) % MOD;
	//	}
	//	table[tar][tar] = table[tar][tar - 1] + 1;
	//	for (int i = tar + 1; i <= n; i++)
	//	{
	//		table[tar][i] = table[tar][tar];
	//	}
	//}
	tab[0] = 1;
	//tab[1] = 1;
	for (int i = 1; i <= 20000; i++)
	{
		p(i);
	}
	while (std::cin >> n)
	{
		std::cout << p(n) << std::endl;;
	}
#ifdef InFile
	system("pause");
	Sleep(-1);
#endif // InFile
	return 0;
}
