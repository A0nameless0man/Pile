#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<set>
#include<map>
const int MAX_N = 100005;
struct LCS_ele
{
	int data;
	int No;
};
struct LCS_ele_No_set
{
	int No[2];//如果每个数只出现一次，可以小一些，如果不确定，还是大一点好。
	int Noc;
	void add(int a)
	{
		No[Noc++] = a;
	}
};

int n,Acount,Bcount;
//int mem_DP[MAX_N][MAX_N];
int a[MAX_N], ClearedB[MAX_N], ClearedA[MAX_N];


int LIS[(unsigned long long)(1.3*MAX_N)],lis;
inline int max(int a, int b)
{
	return a > b ? a : b;
}
//int DP_FindLCS(int i, int j)
//{
//
//	if (i < 0 || j < 0)
//	{
//		return 0;
//	}
//	if (mem_DP[i][j] != -1&&false)
//	{
//		return mem_DP[i][j];
//	}
//	if (ClearedA[i] == ClearedB[j])
//	{
//		return mem_DP[i][j] = DP_FindLCS(i - 1, j - 1) + 1;
//	}
//	return mem_DP[i][j] = max(DP_FindLCS(i - 1, j), DP_FindLCS(i, j - 1));
//}
int findLIS(int a[], int n)
{
	int MaxLen = 0, _LIS[(unsigned long long)(1.3*MAX_N)];
//	_LIS[MaxLen] = LIS[0];
	for (size_t i = 0; i < n; i++)
	{
		_LIS[i] = 10*MAX_N;
	}
	for (size_t i = 0; i < n; i++)
	{
		int left = 0, right = MaxLen + 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (_LIS[mid] >= LIS[i])
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		_LIS[right] = LIS[i];
		MaxLen = max(MaxLen, right);
	}
	return n>0?MaxLen+1:0;
}
int main(void)
{
	//freopen("testdata.in", "r", stdin);
	while (scanf("%d", &n) != EOF)
	{
		std::set<int> ea;
		std::map<int, LCS_ele_No_set>  nb;
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			ea.insert(a[i]);//记录ai的值，存进set方便比对
		}
		int Bcount=0;
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &ClearedB[Bcount]);
			if (ea.count(ClearedB[Bcount])!=0)//a中没有的，不要
			{
				if (nb.count(ClearedB[Bcount])==0)//记录每个元素对应的序号
				{
					LCS_ele_No_set temp;
					temp.Noc = 0;
					temp.add(Bcount);
					nb.insert(std::pair<int, LCS_ele_No_set>(ClearedB[Bcount], temp));
				}
				else
				{
					std::map<int, LCS_ele_No_set>::iterator temp;
					temp = nb.find(ClearedB[Bcount]);
					temp->second.add(Bcount);
				}
			//	eb.insert(ClearedB[Bcount]);
				Bcount++;
			}
		}
		Acount = 0;
		for (size_t i = 0; i < n; i++)
		{
			if (nb.count(a[i])==1)//清理b中没有的元素
			{
				ClearedA[Acount++] = a[i];
			}
		}
		lis = 0;
		for (size_t i = 0; i < Acount; i++)
		{
			LCS_ele_No_set tempNo;
			std::map<int, LCS_ele_No_set>::iterator iter;
			iter = nb.find(ClearedA[i]);
			tempNo = iter->second;
			for (int i = tempNo.Noc - 1; i >= 0; i--)
			{
				LIS[lis++] = tempNo.No[i];
			}
		}
		//printf("%d\n", DP_FindLCS(Acount - 1, Bcount - 1));
		printf("%d\n", findLIS(LIS, lis));
	}
	return 0;
}
