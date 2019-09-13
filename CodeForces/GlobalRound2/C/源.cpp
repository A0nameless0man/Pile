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
const int MAX_N = 1007;
bool A[MAX_N][MAX_N], B[MAX_N][MAX_N], M[MAX_N][MAX_N];
int n, m, a, b, j, k;
int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt", std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG

	while (std::cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a;
				if (a == 0)
				{
					A[i][j] = false;
				}
				else
				{
					A[i][j] = true;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a;
				if (a == 0)
				{
					B[i][j] = false;
				}
				else
				{
					B[i][j] = true;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				M[i][j] = A[i][j] ^ B[i][j];
				int a = M[i][j] ? 1 : 0;
				//cout << a << " ";
			}
			//cout << endl;
		}
		int Mcont = 0;
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		if (M[i][j])
		//		{
		//			Mcont++;
		//		}
		//	}
		//}
		//if (Mcont % 4 != 0)
		//{
		//	cout << "No" << endl;
		//	continue;
		//}
		for (int i = 0; i < n; i++)
		{
			Mcont = 0;
			for (int j = 0; j < m; j++)
			{
				if (M[i][j])
				{
					Mcont++;
				}
			}
			if (Mcont % 2 != 0)
			{
				cout << "No" << endl;
				goto no;
			}
		}
		for (int i = 0; i < m; i++)
		{
			Mcont = 0;
			for (int j = 0; j < n; j++)
			{
				if (M[j][i])
				{
					Mcont++;
				}
			}
			if (Mcont % 2 != 0)
			{
				cout << "No" << endl;
				goto no;
			}
	}
		cout << "Yes" << endl;
no:	continue;
	}
#ifdef DEBUG
	system("pause");
	Sleep(-1);
#endif // DEBUG
	return 0;
}
