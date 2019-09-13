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
#define C(a) std::cout<<#a<<":"<<(a)<<std::endl;
//template <typename T> void swap(T &a, T &b)
//{
//	T t = a;
//	a = b;
//	b = t;
//}
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int MAX_N = 999983;
int n, m, a, b, j, k;
ULL buffer[607];
ULL Q_pow(ULL a, ULL b)
{
	ULL ans = 1;
	while (b!=0)
	{
		if (b&1)
		{
			ans *= a;
		}
		a *=a;
		b >>= 1;
	}
	ans %= MAX_N;
	return ans;
}
ULL gcd(ULL a, ULL b)
{
	while (a!=b)
	{
		if (a>b)
		{
			a = (a-1)%b+1;
		}
		else
		{
			b = (b-1)%a+1;
		}
	}
	return b;
}
bool primeToEach(ULL a, ULL b)
{
	if (a==b)
	{
		return false;
	}
	if (a>b)
	{
		swap(a, b);
	}
	return gcd(a,b) == 1;
}
int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt",std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG
	
	while (std::cin>>n)
	{
		if (n == 0)
			return 0;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> buffer[i];
		}
		sort(buffer, buffer + n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (primeToEach(buffer[i],buffer[j]))
				{
					count++;
					//cout << "yes:";
				}
				//else
				//{
				//	cout << "no:";
				//}
				//cout << buffer[i] << " " << buffer[j] << std::endl;
			}
		}
		std::cout << count << std::endl;
	}
#ifdef DEBUG
	system("pause");
	Sleep(-1);
#endif // DEBUG
	return 0;
}
