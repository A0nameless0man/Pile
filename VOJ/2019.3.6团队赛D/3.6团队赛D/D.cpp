//#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<map>
#include<queue>
using namespace std;
struct node {
	priority_queue<long long> q1, q2;
};

map<string, node> mp;
map<string, priority_queue<long long>> mp2;
int  main() {
	std::ios::sync_with_stdio(false);
	long long k, n;
	cin >> k >> n;
	while (k--) {
		string s;
		long long tmp;
		cin >> s >> tmp;//输入
		string sr = s;
		reverse(sr.begin(), sr.end());
		if (sr == s)
		{
			mp2[s].push(tmp);
		}
		else//自回文串和非自回文串分开处理
		{
			if (s > sr) {
				mp[s].q1.push(tmp);//非自回文串存到字典序大的那个里面去
			}
			else {
				mp[sr].q2.push(tmp);
			}
		}

	}
	long long ans = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it)//挑选可以成对的非自回文串
	{
		while (!(it->second).q1.empty() && !(it->second).q2.empty() && (it->second).q1.top() + (it->second).q2.top() > 0) {
			ans += (it->second).q1.top() + (it->second).q2.top();
			(it->second).q1.pop();
			(it->second).q2.pop();
		}
	}

	for (auto it = mp2.begin(); it != mp2.end(); ++it)//挑选必然成对的自回文串
	{
		while ((it->second).size() >= 2 && (it->second).top() > 0)
		{
			long long a = (it->second).top();
			(it->second).pop();
			long long b = (it->second).top();
			(it->second).pop();
			if (a > 0 && b > 0)
			{
				ans += a + b;
			}
			else
			{
				(it->second).push(a);
				(it->second).push(b);
				break;
			}
		}
	}

	//long long mx = 0;
	//map<string, priority_queue<long long>>::iterator itt;
	//for (auto it = mp2.begin(); it != mp2.end(); ++it)
	//{
	//	if (!(it->second).empty() && (it->second).top() > mx)
	//	{
	//		mx = (it->second).top();
	//		itt = it;
	//	}
	//}
	//ans += mx;
	//(itt->second).pop();
	priority_queue<long long> potential_center;
	for (auto it = mp2.begin(); it != mp2.end(); ++it)
	{
		if ((it->second).size() >= 2 && (it->second).top() > 0)
		{
			long long a = (it->second).top();
			(it->second).pop();
			long long b = (it->second).top();
			(it->second).pop();
			if (a + b >= 0)
			{
				ans += a + b;
				potential_center.push(-b);
			}
			else
			{
				potential_center.push(a);
			}
		}
		else if (it->second.size()>0&&it->second.top()>0)
		{
			potential_center.push(it->second.top());
		}
	}
	if(potential_center.size()>0&&potential_center.top()>0)
		ans += potential_center.top();
	cout << ans << endl;
	return 0;
}

