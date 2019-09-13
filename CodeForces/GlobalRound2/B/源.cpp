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
int n, h,m, a, b, j, k;
map<int, int> milks;
int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt",std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG
	
	while (std::cin>>n>>h)
	{
		milks.clear();
		bool ended = false;
		for (int i = 0; i < n; i++)
		{
			cin >> b;
			if (!ended)
			{
				if (milks.count(b) == 0)
				{
					milks[b] = 1;
				}
				else
				{
					++milks[b];
				}
				int useablespace = h * 2;
				set<int> singleMilk;
				for (auto u : milks)
				{
					useablespace -= 2 * ((u.second / 2) * u.first);
					if (u.second % 2 != 0)
					{
						singleMilk.insert(u.first);
					}
				}
				bool covered = false;
				for (auto i = singleMilk.rbegin(); i != singleMilk.rend(); i++)
				{
					if (!covered)
					{
						useablespace -= 2 * (*i);
						covered = true;
					}
					else
					{
						covered = false;
					}
				}
				if (useablespace < 0)
				{
					cout << i << endl;
					ended = true;
				}

			}
		}
		if (!ended)
		{
			cout << n << endl;
		}
	}
#ifdef DEBUG
	system("pause");
	Sleep(-1);
#endif // DEBUG
	return 0;
}
