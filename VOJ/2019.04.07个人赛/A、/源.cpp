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
int n, m, a, b, j, k;
int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt", std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG

	while (scanf("%d", &n) != EOF)
	{
		int count = 0;
		ios::sync_with_stdio(false);
		stringstream ans;
		char command[29];
		int x;
		priority_queue<int> que;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", command);
			if (command[0] == 'r') //removeMin
			{
				if (que.empty()) //empty
				{
					ans << "insert 1" << endl;
					count++;
					que.push(-1);
				}
				ans << "removeMin" << endl; //remove
				count++;
				que.pop();
			}
			else //extra x needed
			{
				scanf("%d", &x);
			}
			if (command[0] == 'i') //insert
			{
				que.push(-x);
				ans << "insert"
					<< " " << x << endl;
				count++;
			}
			if (command[0] == 'g') //getMin
			{
				if (!que.empty() && que.top() == -x) //is x
				{
					ans << "getMin"
						<< " " << x << endl;
					count++;
				}
				else
				{
					while (!que.empty() && -que.top() < x) //not x&&smaller than x
					{
						que.pop();
						ans << "removeMin" << endl;
						count++;
					}
					if (que.empty() || que.top() + x != 0) //empty||biger than x
					{
						ans << "insert"
							<< " " << x << endl;
						count++;
						que.push(-x);
					}
					ans << "getMin " << x << endl;
					count++; //get x
				}
			}
		}
		cout << count << endl;
		string buf;
		while (ans >> buf)
		{
			printf("%s", buf.c_str());
			if (buf[0] != 'r')
			{
				ans >> x;
				printf(" %d", x);
			}
			printf("\n");
		}
	}
#ifdef DEBUG
	system("pause");
	Sleep(-1);
#endif // DEBUG
	return 0;
}
