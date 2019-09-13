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
const int MAX_N = 10007;
int n, m, a, b, j, k;
int main(void)
{
#ifdef InFile
	std::fstream fin;
	fin.open("./in.txt",std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // InFile
	
	while (std::cin>>n)
	{
		
	}
#ifdef InFile
	system("pause");
	Sleep(-1);
#endif // InFile
	return 0;
}
