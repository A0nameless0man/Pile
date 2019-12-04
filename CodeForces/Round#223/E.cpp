//前缀和+ST表
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

//#define DEBUG

#ifdef DEBUG
#define Check(x) std::cout << #x << " : " << (x) << std::endl;
#else
#define Check(x)
#endif //DEBUG

const int MAX_N = 1000007;
int ST[MAX_N][32];
int sum[MAX_N];
char input[MAX_N];
int main(void)
{
	while (scanf("%s", input) != EOF)
	{
		int len = strlen(input);
		int n = len + 1;
		int prefix = 0;
		sum[0] = 0;
		for (int i = 0; i < len; ++i)
		{
			if (input[i] == '(')
			{
				prefix += 1;
			}
			else
			{
				prefix -= 1;
			}
			sum[i + 1] = prefix;
		}
		for (int i = 0; i < n; i++)
		{
			ST[i][0] = sum[i];
		}
		for (int j = 1, k = 1; k < n; ++j, k <<= 1)
		{
			int i;
			for (i = 0; i + k < n; ++i)
			{
				ST[i][j] = std::min(ST[i][j - 1], ST[i + k][j - 1]);
			}
			for (; i < n; i++)
			{
				ST[i][j] = ST[i][j - 1];
			}
		}
#ifdef DEBUG
		{
			for (int i = 0; i < n; ++i)
			{
				printf("%3d", sum[i]);
			}
			printf("\n");
			for (int j = 0, k = 1; k < n; ++j, k <<= 1)
			{
				for (int i = 0; i < n; ++i)
				{
					printf("%3d", ST[i][j]);
				}
				printf("\n");
			}
		} //Debug
#endif	//DEBUG
		int m;
		//std::cin >> m;
		scanf("%d",&m);
		for (int i = 0; i < m; i++)
		{
			int l, r;
			// std::cin >> l >> r;
			scanf("%d%d",&l,&r);
			//++r;
			--l;
			int dis = r - l;
			int disl = floor(log2(dis));
			int min = std::min(ST[l][disl], ST[r - (1<<disl)+1][disl]);
#ifdef DEBUG
			for (int i = l; i < r; ++i)
			{
				std::cout << input[i];
			}
			std::cout << std::endl;
			for(int i = l;i<=r;++i)
			{
				printf("%3d",sum[i]);
			}
			printf("\n");
			Check(sum[l]);
			Check(sum[r]);
			Check(dis);
			Check(disl);
			Check(ST[l][disl]);
			Check(r - (1<<disl)+1);
			for(int i = r - (1<<disl)+1;i<r+1;i++)
			{
				printf("%3d",sum[i]);
			}
			printf("\n");
			Check(ST[r - (1<<disl)+1][disl]);
			Check(min);
#endif //DEBUG
			// std::cout << dis - std::abs(sum[l] - min) - std::abs(sum[r] - min) << std::endl;
			int ans = dis - std::abs(sum[l] - min) - std::abs(sum[r] - min);
			printf("%d\n",ans);
		}
	}
}
/*
())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10
*/
//((())))()()))
/*
)())((((((((()()())((((())))()()))(((((()(((()(((((())(((((()))(()((()()(()((()()())()((())())))(
60
65 74
42 63
15 89
32 37
21 90
21 54
14 95
4 62
57 89
10 53
15 70
28 29
7 56
24 33
39 95
55 66
35 43
8 88
54 93
78 84
92 97
16 39
61 81
36 55
32 65
79 87
8 36
39 91
10 91
7 19
39 40
77 94
15 50
28 91
36 61
26 43
1 5
62 84
2 33
1 26
4 42
24 29
51 93
41 41
30 72
11 21
21 33
49 57
28 58
8 39
10 80
44 76
30 65
12 13
1 36
20 37
2 90
59 85
33 43
1 78
*/