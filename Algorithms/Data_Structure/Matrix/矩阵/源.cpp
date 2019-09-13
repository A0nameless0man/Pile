#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
template <class E> inline void swap(E& a, E& b)
{
	E temp = a;
	a = b;
	b = temp;
	return;
}
template <class E> class Maytrax
{
public:
	Maytrax(int x, int y)
	{
		_x = x, _y = y;
		IsTransplated = false;
		data = (E*)malloc(_x*_y * sizeof(E));
		memset(data, 0, _x*_y * sizeof(E));
	}
	~Maytrax()
	{
		free(data);
	}
	E GetDataByXY(int x, int y)
	{
		if (IsLlegalAccess(x, y))
		{
			return *GetAddByXY(x, y);
		}
		else
		{
			exit(-1);
		}
	}
	bool SetDataByXY(int x, int y, E input)
	{
		if (IsLlegalAccess(x, y))
		{
			*GetAddByXY(x, y) = input;
			return true;
		}
		else
		{
			return false;
		}
	}
	void transport(void)
	{
		IsTransplated = !IsTransplated;
	}
	int GetSideLen(bool IsWide)
	{
		return (IsTransplated ^ IsWide) ? _x : _y;
	}
	Maytrax<E> operator+(Maytrax<E> b)
	{
		if (this->GetSideLen(true)==b.GetSideLen(true)&&this->GetSideLen(false)==b.GetSideLen(false))
		{
			Maytrax<E> r(this->GetSideLen(true), this->GetSideLen(false));
			for (size_t i = 0; i < this->GetSideLen(true); i++)
			{
				for (size_t j = 0; j < this->GetSideLen(false); j++)
				{
					r.SetDataByXY(i, j, this->GetDataByXY(i, j) + b.GetDataByXY(i, j));
				}
			}
			return r;
		}
		else
		{
			exit(-1);
			
		}
	}
	Maytrax<E> operator*(Maytrax<E> b)
	{
		if (this->GetSideLen(true)==b.GetSideLen(false))
		{
			Maytrax<E> r(b.GetSideLen(true), this->GetSideLen(false));
			for (size_t i = 0; i < b.GetSideLen(true); i++)
			{
				for (size_t j = 0; j < this->GetSideLen(false); j++)
				{
					for (size_t m = 0; m < this->GetSideLen(true); m++)
					{
						r.SetDataByXY(i, j, r.GetDataByXY(i, j) + this->GetDataByXY(i, m)*b.GetDataByXY(m, j));
					}
				}
			}
			return r;
		}
		else
		{
			exit(-1);
		}
	}
private:
	inline bool IsLlegalAccess(int x, int y)
	{
		if (IsTransplated)
		{
			swap(x, y);
		}
		if (x >= 0 && x < _x && y >= 0 && y < _y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	E* GetAddByXY(int x, int y)
	{
		if (IsLlegalAccess(x, y))
		{
			if (IsTransplated)
			{
				swap(x, y);
			}
			return data + y*_x+x;
		}
		else
		{
			return NULL;
		}
	}
	E* data;
	int _x, _y;//x是列数，y是行数
	bool IsTransplated;
};

int main(void)
{
	int a, b;
	Maytrax<int> *M;
	while (true)
	{
		printf("欢迎使用胡广的矩阵转置程序。\n请输入所需矩阵的列数和行数:\n");
		if (scanf("%d%d",&a,  &b) == EOF)
		{
			return 0;
		}
		if ((M = new Maytrax<int>(a, b)) != NULL)
		{
			printf("内存分配完毕，请输入数据。\n");
			for (size_t j = 0; j < M->GetSideLen(false); j++)
			{
				for (size_t i = 0; i < M->GetSideLen(true); i++)
				{
					int buffer;
					scanf("%d", &buffer);
					M->SetDataByXY(i, j, buffer);
				}
			}
		}
		else
		{
			printf("内存不足，请缩小数组规模或稍后再试。\n");
			continue;
		}
		printf("已读入足够数据。\n");
//		do
//		{
//			getchar();
//			printf("请问要转置吗？y/n\n");
//		} while (getchar()!='n'||(M->transport(),false));
			if (true)
			{
				M->transport();
			}
		printf("下面输出\n");
		for (size_t j = 0; j < M->GetSideLen(false); j++)
		{
			for (size_t i = 0; i < M->GetSideLen(true); i++)
			{
				printf("%d", M->GetDataByXY(i, j));
				if(i!=M->GetSideLen(true)-1)
				{
					putchar(' ');
				}else{
					putchar('\n');
				}
			}
			
		}
		delete M;
	}
}