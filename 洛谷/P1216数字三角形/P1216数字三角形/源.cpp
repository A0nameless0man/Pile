#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
/*
дһ�����������Ҵ���ߵ㵽�ײ����⴦������·����ʹ·���������ֵĺ����ÿһ�������ߵ����·��ĵ�Ҳ���Ե������·��ĵ㡣
�����ʽ��
��һ���а��� R(1<= R<=1000) ,��ʾ�е���Ŀ��

����ÿ��Ϊ������ֽ������ض��а�����������

���еı���Ӧ�������ǷǸ����Ҳ�����100��

�����ʽ��
������һ��,�����Ǹ����ܵõ������ĺ͡�
*/
const int MAX_N = 1007;
int map[MAX_N][MAX_N];
int CurrentMax[MAX_N][MAX_N];
int r;
int main(void)
{
	while (scanf("%d",&r)!=EOF)
	{
		for (size_t i = 0; i < r; i++)
		{
			for (size_t j = 0; j <= i; j++)
			{
				scanf("%d", &map[i][j]);
				CurrentMax[i][j] = 0;
				if (i!=0)
				{
					CurrentMax[i][j] = CurrentMax[i - 1][j];
				}
				if (j!=0)
				{
					if (CurrentMax[i-1][j-1]>CurrentMax[i][j])
					{
						CurrentMax[i][j] = CurrentMax[i-1][j - 1];
					}
				}
				CurrentMax[i][j] += map[i][j];
			}
		}
		int max = 0;
		for (size_t i = 0; i < r; i++)
		{
			if (CurrentMax[r-1][i]>max)
			{
				max = CurrentMax[r - 1][i];
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
