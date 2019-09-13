#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string>
#include<sstream>		
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
template <typename T> void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}
const int MAX_N = 10007;
int n, m, a, b, j, k;
int main(void)
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif // DEBUG
	int i = 0;
	int tmp[30];
	while (std::cin >> tmp[i++]);
	i--;
	std::sort(tmp, tmp + i);
	for (int j = 0; j < i; j++)
	{
		std::cout << tmp[j] << std::endl;
	}

#ifdef DEBUG
	system("pause");
	system("pause");
#endif // DEBUG

	return 0;
}
