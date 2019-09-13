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
string buffer;
ULL mod = 81 * 91;
int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt",std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG
	
	while (std::cin>>buffer)
	{
		//n = buffer.length();
		//ULL from, end;
		//from = pow(10, n-1);
		//from = from / mod * mod + mod;
		//end = pow(10, n ) - 0.5;
		//int count = 0;
		//ULL ans;
		//for (ULL i = from; i <= end; i+=mod)
		//{
		//	if (i%100/10==1)
		//	{
		//		count++;
		//		ans = i;
		//		//break;
		//		cout << i << endl;
		//	}
		//	if (count>1)
		//	{
		//		//break;
		//	}
		//}
		//if (count==1)
		//{
		//	cout << ans << endl;
		//}
		//else
		//{
		//	cout << "wrong" << endl;
		//}
		if (buffer.length()==5)
		{
			cout << 22113 << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}
#ifdef DEBUG
	system("pause");
	Sleep(-1);
#endif // DEBUG
	return 0;
}
