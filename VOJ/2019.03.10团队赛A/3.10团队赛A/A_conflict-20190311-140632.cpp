#include <algorithm>
#include <iostream>
#include <map>
#include <stdlib.h>
// struct line
//{
//	long long start;
//	long long e;
// long long cost[2];
//	bool operator< (const line &a)const{return start<a.start;}
//};

// std::map<line,cos> mp;
// using iter = std::map<line,cos>::iterator;
const int       MAX = 3e5;
const long long INF = 5e10;
// line lines[MAX];
long long cost[MAX];
long long p[MAX];
long long s[MAX];
int       main(void)
{
    int T;
    std::cin >> T;
    while(T--)
    {
        int n, m;
        std::cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            std::cin >> s[i] >> p[i];
            cost[i] = s[i] * p[i];
        }
        cost[n] = INF;
        int i   = n - 1;
        while(i--)
        {
            cost[i] = std::min(cost[i], cost[i + 1]);
        }
        // int offset=0;
        // for(int i =n-1;i-offset>=0;i--)
        //{
        //	while(cost[i-offset]>cost[i])
        //	{
        //		offset++;
        //	}
        //	p[i]=p[i-offset];
        //	s[i]=s[i-offset];
        //	cost[i]=cost[i-offset];
        //}
        // int linecount=0;
        // for(int i=offset;i<n-1;i++)
        //{
        //	lines[linecount].start=s[i];
        //	lines[linecount].cost[0]=p[i];
        //	lines[linecount].cost[1]=p[i+1]*s[i+1];
        //	lines[linecount].e=p[i+1]*s[i+1]/p[i];
        //	linecount++;
        //}
        // lines[linecount].start = s[n - 1];
        // lines[linecount].cost[0] = p[n - 1];
        // lines[linecount].e = INF;
        // linecount++;
        long long q;
        for(int i = 0; i < m; i++)
        {
            std::cin >> q;
            int left  = 0;
            int right = n - 1;
            while(left < right)
            {
                int mid = (left + right) / 2;
                if(s[mid] >= q)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            while(s[left] > q)
                left--;
            long long cq = std::min(p[left] * q, cost[left + 1]);
            //	 long long cq = (q > lines[left].e) ? lines[left].cost[1] : lines[left].cost[0] * q;
            std::cout << cq << std::endl;
        }
    }
    system("pause");
    return 0;
}
