#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<queue>
using ULL = unsigned long long;
int main(void)
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int n;
		ULL k;
		std::cin >> n >> k;
		std::priority_queue<ULL> pool, caught;
		for (ULL i = 0; i < n; i++)
		{
			ULL temp;
			//std::cin >> temp;
			scanf("%llu", &temp);
			pool.push(temp);
		}
		ULL currentTime = 0;
		ULL potOcBefore = 0;
		while (!pool.empty()||!caught.empty())
		{
				if (!pool.empty())
				{
					while ((currentTime+k<=potOcBefore||caught.empty())&& !pool.empty())
					{
						currentTime += k;
						caught.push(pool.top());
						pool.pop();
					}
				}			
			currentTime = std::max(potOcBefore, currentTime);
			potOcBefore = caught.top()+currentTime;
			caught.pop();
		}
		std::cout << potOcBefore << std::endl;
	}
}