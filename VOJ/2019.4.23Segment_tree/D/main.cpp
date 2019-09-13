#include<iostream>
#include<queue>
struct node
{
	int left_w;
	int row;
};
bool operator<(const node& a, const node& b)
{
	if (a.left_w>b.left_w)
	{
		return false;
	}
	if (a.left_w<b.left_w)
	{
		return true;
	}
	if (a.row<b.row)
	{
		return false;
	}
	return true;
}
int main(void)
{
	int h, w, n;
	while (std::cin>>h>>w>>n)
	{
		if (h>=n)
		{
			int k;
			for (size_t i = 1; i <= n; i++)
			{
				std::cin >> k;
				std::cout << n << std::endl;
			}
		}
		else
		{
			std::priority_queue<node> que;
			for (int i = 1; i <= h; i++)
			{
				que.push({ w,i });
			}
			int k;
			for (size_t i = 0; i < n; i++)
			{
				std::cin >> k;
				if (que.top().left_w>=k)
				{
					node n = que.top();
					que.pop();
					n.left_w -= k;
					std::cout << "ans"<<n.row<<std::endl;
					que.push(n);
				}
				else
				{
					std::cout << -1 << std::endl;
				}
			}
		}
	}
	return 0;
}