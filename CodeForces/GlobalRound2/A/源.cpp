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
#include<unordered_map>
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
vector<int> houses;
map<int, int> colourFront, colourBack;
class node
{
public:
	node(int col, int pos) :colour(col),pos(pos) {}
	int colour;
	int pos;
	bool operator<(const node& b)const { return pos < b.pos; }
};

int main(void)
{
#ifdef DEBUG
	std::fstream fin;
	fin.open("./in.txt", std::ios::in);
	std::cin.rdbuf(fin.rdbuf());
#endif // DEBUG

	while (std::cin >> n)
	{
		houses.clear();
		colourFront.clear();
		colourBack.clear();
		priority_queue<node> cF, cB;
		for (int i = 0; i < n; i++)
		{
			std::cin >> a;
			houses.push_back(a);
		}
		for (int i = 0; i != houses.size(); i++)
		{
			if (colourFront.count(houses[i]) == 0)
			{
				colourFront[houses[i]] = i;
				cF.push(node(houses[i], -i));
			}
		}
		for (size_t i = houses.size() - 1; i != size_t(-1); i--)
		{
			if (colourBack.count(houses[i]) == 0)
			{
				colourBack[houses[i]] = i;
				cB.push(node(houses[i],i));
			}
		}
		if (cB.top().colour != cF.top().colour)
		{
			cout << abs(colourBack[cB.top().colour] - colourFront[cF.top().colour]) << endl;
		}
		else
		{
			int cB1 = cB.top().colour;
			cB.pop();
			int cB2 = cB.top().colour;
			int cF1 = cF.top().colour;
			cF.pop();
			int cF2 = cF.top().colour;
			cout << max(abs(colourBack[cB1] - colourFront[cF2]), abs(colourBack[cB2] - colourFront[cF1])) << endl;
		}
	}
#ifdef DEBUG
	system("pause");
	Sleep(-1);
#endif // DEBUG
	return 0;
}
