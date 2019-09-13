#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#include"Chairman_Tree.h"
int main()
{
	size_t n, m;
	while (std::cin>>n>>m)
	{
		C_Tree::Chairman_Tree<long, long> C_T;
		using pair = std::pair<long long,long long>;
		std::vector< pair> vec;
		for (long long i = 1; i <= n; i++)
		{
			long long k;
			//std::cin >> k;
			scanf("%lld", &k);
			vec.push_back(pair(i, k));
		}
		//std::random_shuffle(vec.begin(), vec.end());
		std::stack<pair> sta;
		sta.push(pair(0, n - 1));
		while (!sta.empty())
		{
			pair p = sta.top();
			sta.pop();
			if (p.first==p.second)
			{
				C_T.insert(vec[p.first].first, vec[p.first].second, 0);
			}
			else
			{
				long long mid = (p.first + p.second) / 2;
				C_T.insert(vec[mid].first, vec[mid].second, 0);
				if (p.first<=mid-1)
				{
					sta.push(pair(p.first, mid-1));
				}
				if (mid+1<=p.second)
				{
					sta.push(pair(mid + 1, p.second));
				}
			}
		}
		//for (size_t i = 0; i < n; i++)
		//{
		//	C_T.insert(vec[i].first, vec[i].second, 0);
		//}
		for (size_t i = 0; i < m; i++)
		{
			int ver;
			int op;
			//std::cin >> ver >> op;
			scanf("%d%d", &ver, &op);
			if (op==1)
			{
				int key, val;
				//std::cin >> key >> val;
				scanf("%d%d", &key, &val);
				C_T.newVer(ver);
				C_T.set(key, val, i + 1);
			}
			else
			{
				int key;
				//std::cin >> key;
				scanf("%d", &key);
				C_T.newVer(ver);
				std::cout << C_T.consalt(key, i + 1) << std::endl;
			}
		}
	}
	return 0;
}