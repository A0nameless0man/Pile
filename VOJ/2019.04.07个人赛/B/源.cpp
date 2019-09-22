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
int x, y;
int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt", std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG

	while (std::cin >> x >> y)
	{
		int ans = 0;
		int n[3] = { y,y,y};
		//if (x>2*y)
		//{
		//	n[0] = 2 * y - 1;
		//	ans++;
		//}
		//else
		//{
		//	n[0] = y;
		//	ans++;
		//}
		while (n[0] != x || n[1] != x||n[2]!=x)
		{
			int big = 0, smal = 0, ele = 0;;
			for (size_t i = 0; i < 3; i++)
			{
				if (n[i]>n[big])
				{
					big = i;
				}
				if (n[i]<n[smal])
				{
					smal = i;
				}
			}
			while (ele==big||ele==smal)
			{
				ele++;
			}
			{
				n[smal] = min(n[ele] + n[big] - 1,x);
				ans++;
			}
		}
		cout << ans<<endl;
	}
#ifdef DEBUG
	system("pause");
	Sleep(-1);
#endif // DEBUG
	return 0;
}
