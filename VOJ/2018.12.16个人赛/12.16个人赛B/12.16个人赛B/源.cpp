#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<set>
const int MAX_N = 10007;
struct group
{
	std::set<int> R, M;
};
group groups[MAX_N];
int main(void)
{
	int m;
	bool safe = true;
	while (scanf("%*d%d",&m)!=EOF)
	{
		for (size_t i = 0; i < m; i++)
		{
			int k;
			bool safeg = false;
			scanf("%d", &k);
			for (size_t j = 0; j < k; j++)
			{
				int v;
				scanf("%d", &v);
				groups[i].M.insert(v);
			}
			std::set<int>::iterator iter;
			for ( iter = groups[i].M.begin(); iter !=groups[i].M.end(); iter++)
			{
				if (groups[i].M.count(-(*iter))==1)
				{
					safeg = true;
				}
			}
			if (!safeg)
			{
				safe = false;
			}
			groups[i].M.clear();
		}
		printf("%s\n", safe ? "NO" : "YES");
	}
	return 0;
}
