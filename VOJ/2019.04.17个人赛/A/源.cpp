#define _CRT_SECURE_NO_WARNINGS //shut up MS//NOT fo CPP//scanf VS. scanf_s
//#define DEBUG
#include <stdio.h>
#include <iostream> //stream
#include <sstream>  //stringstream
#include <fstream>  //file
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
//STL
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
//STL
#ifdef DEBUG
#include <Windows.h> //sleep()
#include <stdlib.h>  //system("pause")
#endif				 // DEBUG

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
long long n, m, a, b, j, k;
long long pow(int a)
{
	long long ans = 1;
	long long e = 10;
	while (a)
	{
		if (a & 1)
		{
			ans *= e;
		}
		e *= e;
		a >>= 1;
	}
	return ans;
}
bool check(long long mid)
{
	//cout <<"((long long)n*(long long)2)"<< ((long long)n) << endl;
	//cout << "pow" << mid << "/2:" << pow(mid)/2 << endl;
	//cout << (((long long)n) < (pow(mid) / 2)) << endl;
	return (((long long)n) < (pow(mid) / 2));
}
int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt", std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG
	//cout << pow(2) << endl;
	while (std::cin >> n)
	{
		long long l = 0, r = 0;
		while (pow(r) < n)
		{
			r++;
		}
		r += 3;
		while (l < r)
		{
			long long mid = (l + r) / 2;
			if (check(mid))
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
			/*cout << "L" << l << endl;
			cout << "R" << r << endl;*/
		}
		long long ans = 0;
		long long exa = 0;
		long long po = pow(l - 1);
		while ((exa + po) / 2 <= n)
		{
			//	cout << "exa" << exa << endl;
			ans += min(n - (po + exa) / 2 + 1, (po + exa) / 2 - 1);
			exa += po;
		}
		if (n < 5)
		{
			ans = n * (n - 1) / 2;
		}
		cout << ans << endl;
	}
#ifdef DEBUG
	system("pause");
	Sleep(-1);
#endif // DEBUG
	return 0;
}