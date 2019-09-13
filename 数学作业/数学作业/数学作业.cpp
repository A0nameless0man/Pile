// 数学作业.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>

int main()
{
	int a = 2;
	int x = 4;
	int y = pow(a,x);
	while(y <= 10*x+3)
	{
		x++;
		y = pow(a, x);
	}
	return x;
}

