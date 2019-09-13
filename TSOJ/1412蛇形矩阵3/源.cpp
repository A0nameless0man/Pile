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
int gengrate(int* output, int n,int aa,int b)
{
	//for (size_t i = 0; i < n; i++)
	//{
	//	for (size_t j = 0; j < n; j++)
	//	{
	//		*(output + i * n + j) = 0;
	//	}
	//}
	//³õÊ¼»¯
	int i = 0, j = 0, heading = 0, element = 0;
	//0=right
	//1=down
	//2=left
	//3=up
	for (size_t a = 0; a < n * n; a++)
	{
		switch (heading)
		{
		case 0:
			if (i + j == n - 1)
			{
				heading = 1;
			}
			break;
		case 1:
			if (i == j)
			{
				heading = 2;
			}
			break;
		case 2:
			if (i + j == n - 1)
			{
				heading = 3;
			}
			break;
		case 3:
			if (i - j == 1)
			{
				heading = 0;

			}
			break;
		default:
			break;
		}
		element++;
		//cout << i << " " << j << " " << element << endl;
		if (i==aa&&j==b)
		{
			return element;
		}
		switch (heading)
		{
		case 0:j++; break;
		case 1:i++; break;
		case 2:j--; break;
		case 3:i--; break;
		default:
			break;
		}
	}
}
int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt", std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG

	while (std::cin >> n >> a >> b)
	{
		a--;
		b--;
		cout << gengrate(NULL, n, a, b) << endl;
		//for (size_t i = 0; i < n; i++)
		//{
		//	for (size_t j = 0; j < n; j++)
		//	{
		//		cout << *(matrix + i * n + j);
		//		if (j < n - 1)
		//		{
		//			cout << " ";
		//		}
		//	}
		//	cout << endl;
		//}
	}
#ifdef DEBUG
	system("pause");
	Sleep(-1);
#endif // DEBUG
	return 0;
}
