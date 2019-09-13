#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<chrono>
using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;
const long long int range = 1000000000;
bool N[range] = { 0 };
int main(void)
{
	TimePoint from = Clock::now();
	FILE* f = fopen("table.txt", "w+");
	//for (long long int  i = 0; i < range; i++)
	//{
	//	N[i] = true;
	//}
	N[0] = false;
	N[1] = false;
	N[2] = true;
	for (long long int  i = 3; i < range; i++)
	{
		N[i] = true;
	}
	for (long long int i = 2; i < range; )
	{
		printf("%f %% \r", (float)i / range*100);
		//printf("%lld\n", i);
		fprintf(f, "%lld\n", i);
		N[i] = true;
		for (long long int j = 0; j < range; j += i)
		{
			N[j] = false;
		}
		i++;
		while (N[i] == false && i < range)
		{
			i++;
		}
	}
	TimePoint to = Clock::now();
	std::chrono::duration<double> timeUsed = to - from;
	std::cout << std::endl << timeUsed.count() << std::endl;
	system("pause");
}