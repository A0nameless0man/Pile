#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<algorithm>
class country
{
public:
	country()
	{}
	~country() {}
	std::string name;
	std::string state;
	int No;
	int NumOfAthe;
	bool operator<(const country b)
	{
		return b.name == "China" || this->name != "China"&&this->name < b.name;
	}
};
country countries[10000];
template <typename T>void swap(T&a, T&b)
{
	T t = a;
	a = b;
	b = t;
}
template <typename T> void buble_sort(T* from, T* After_To)
{
	for (T* i = from; i < After_To; i++)
	{
		for (T* j = from; j < i; j++)
		{
			if (!(*j < *i))
			{
				swap(*j, *i);
			}
		}
	}
}
int main(void)
{
	int n;
	freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			std::cin >> countries[i].No >> countries[i].name >> countries[i].NumOfAthe >> countries[i].state;
		}
		buble_sort(countries, &countries[n]);
		//std::qsort(countries, n, sizeof(country));
		for (int i = 0; i < n; i++)
		{
			std::cout << countries[i].No << ' ' << countries[i].name << ' ' << countries[i].NumOfAthe << ' ' << countries[i].state << std::endl;
		}
	}
	return 0;
}
