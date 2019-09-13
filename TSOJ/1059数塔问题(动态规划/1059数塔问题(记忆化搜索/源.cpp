#define _CRT_SECURE_NO_WARNINGS//shut up MS
//#define DEBUG
#include<stdio.h>
#include<iostream>
//#include<sstream>
//#include<fstream>
//#include<string.h>
//#include<ctype.h>
//#include<math.h>
//#include<string>
#include<algorithm>
////STL
//#include<map>
//#include<set>
//#include<vector>
//#include<queue>
//#include<stack>
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
const ULL INF = 0xf00f0f0f0f0f;
const int MAX_N = 100000;
//ULL mp[MAX_N][MAX_N];
//ULL mem[MAX_N][MAX_N];
ULL input[MAX_N], DP[MAX_N];
int n, m, a, b, j, k;
//ULL dfs(int x, int y)
//{
//	//if (y>x||x>=n||x<0||y<0)
//	//{
//	//	throw exception("out of range");
//	//	return 0;
//	//}
//	if (mem[x][y] !=INF)
//	{
//		return mem[x][y];
//	}
//	if (x==n-1)
//	{
//		return mem[x][y] = mp[x][y];
//	}
//	return mem[x][y] = std::min(dfs(x + 1, y), dfs(x + 1, y + 1))+mp[x][y];
//
//}
int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt", std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG
	while (std::cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> input[j];
			}
			if (i!=0)
			{
				DP[i] = DP[i - 1] + input[i];
			}
			else
			{
				DP[0] = input[0];

			}
			for (int j = i - 1; j > 0; j--)
			{
				DP[j] = input[j] + min(DP[j], DP[j - 1]);
			}
			if (i != 0)
			{
				DP[0] += input[0];
			}
		}
		ULL Min = INF;
		for (int i = 0; i < n; i++)
		{
			Min = min(Min, DP[i]);
		}
		cout << Min << endl;
		//cout << dfs(0, 0) << endl;
		//printf("%lld\n", dfs(0, 0));
	}
#ifdef DEBUG
	system("pause");
	system("pause");
	Sleep(-1);
#endif // DEBUG

	return 0;
	}
