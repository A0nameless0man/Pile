#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<algorithm>
const long long int  MAX_N = 100007;
std::map<long long int ,long long int > planetindex[MAX_N];
long long int  cost[MAX_N];
long long int  n, q, s;
long long int  t, v, u, l, r,w;
void DFS(long long int  k)
{
	if (cost[k]==-1)
	{
		cost[k] = 0;
	}
	std::map<long long int , long long int >::iterator iter;
	for ( iter = planetindex[k].begin(); iter != planetindex[k].end(); iter++)
	{
		if (cost[iter->first]>cost[k]+iter->second||cost[iter->first]==-1)
		{
			cost[iter->first] = cost[k] + iter->second;
			DFS(iter->first);
		}
	}
}
void insert(long long int  u, long long int  v, long long int  w)
{
	std::map<long long int , long long int >::iterator iter;
	if ((planetindex[u].count(v))==1)
	{
		iter = planetindex[u].find(v);
		iter->second = std::min(iter->second, w);
	}
	else
	{
		planetindex[u].insert(std::pair<long long int , long long int >(v, w));
	}
}
int  main(void)
{
	while (scanf("%lld%lld%lld",&n,&q,&s)!=EOF)
	{
		for (size_t i = 0; i <= n; i++)
		{
			planetindex[i].clear();
			cost[i] = -1;
		}
		for (size_t i = 0; i < q; i++)
		{
			scanf("%lld", &t);
			switch (t)
			{
			case 1:
				scanf("%lld%lld%lld", &v, &u,&w);
				insert(v, u, w);
				break;
			case 2:
				scanf("%lld%lld%lld%lld", &v, &l, &r,&w);
				for (size_t i = l; i <= r; i++)
				{
					insert(v, i, w);
				}
				break;
			case 3:
				scanf("%lld%lld%lld%lld", &v, &l, &r,&w);
				for (size_t i = l; i <= r; i++)
				{
					insert(i, v, w);
				}
				break;
			default:
				break;
			}
		}
		DFS(s);
		for (size_t i = 1; i <= n; i++)
		{
			printf("%lld", cost[i]);
			if (i<n)
			{
				putchar(' ');
			}
		}
		putchar('\n');
	}
	return 0;
}
