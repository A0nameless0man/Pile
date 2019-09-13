#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
const int BUFFER_SIZE = 512;
const int SHORT_BUFFER_SIZE = 16;
class domath;
class Uncertain_Num;
class variable;
class Uncertain_Num
{/*定义测量结果结构体*/
public:
	float average;  //平均值 
	float u;   //不确定度 
	int print(void)
	{
		//输出
		return printf("%f±%f", average, u);
	}
	//以下是重载+-*/运算符和幂函数
	Uncertain_Num operator*(const Uncertain_Num& a)
	{
		Uncertain_Num result;
		result.average = a.average * this->average;
		result.u = pow(pow(a.average*this->u, 2) + pow(this->average*a.u, 2), 0.5);
		return result;
	}
	Uncertain_Num operator-(Uncertain_Num& a)
	{
		Uncertain_Num result;
		result.average = this->average - a.average;
		result.u = this->u + a.u;
		return result;
	}
	Uncertain_Num operator+(Uncertain_Num& a)
	{
		Uncertain_Num result;
		result.average = this->average + a.average;
		result.u = this->u + a.u;
		return result;
	}
	Uncertain_Num operator/(Uncertain_Num& a)
	{
		Uncertain_Num result;
		result.average = this->average / a.average;
		result.u = pow(pow(this->u / a.average, 2) + pow(this->average / pow(a.average, 2)*a.u, 2), 0.5);
		return result;
	}
	Uncertain_Num pow_u(float n)
	{
		Uncertain_Num result;
		result.average = pow(this->average, n);
		result.u = n * pow(this->average, n - 1)*this->u;
		return result;
	}
};
class variable
{
public:
	Uncertain_Num * GetbyName(char inputname)
	{
		if (name == inputname)
		{
			return &content;
		}
		else
		{
			if (next != NULL)
			{
				return next->GetbyName(inputname);
			}
			else
			{
				return NULL;
			}
		}
	}
	Uncertain_Num* CreatebyName(char inputname)
	{
		if (next == NULL)
		{
			next = (variable*)malloc(sizeof(variable));
			next->next = NULL;
			next->name = inputname;
			printf("请输入“%c”的值。\n", inputname);
			scanf("%f", &next->content.average);
			printf("请输入“%c”的不确定度。\n", inputname);
			scanf("%f", &next->content.u);
			printf("%c已记录\n", inputname);
			return &next->content;
		}
		else
		{
			return next->CreatebyName(inputname);
		}
	}
	variable()
	{
		next = NULL;
	}
	void ini(void)
	{
		next = NULL;
		content.average = 3.141592653;
		content.u = 0;
		name = 'p';
	}
private:
	char name;
	Uncertain_Num content;
	variable *next;
};
class domath
{
public:
	Uncertain_Num caculat(void)
	{
		//计算本式子的结果并返回该结果
		Uncertain_Num left_r, right_r;
		if (IsNum)
		{
			return *num;
		}
		else
		{
			left_r = left->caculat();
			right_r = right->caculat();
			switch (op)
			{
			case '+':
				return right_r + left_r;
				break;
			case '-':
				return left_r - right_r;
				break;
			case '*':
				return left_r * right_r;
				break;
			case '/':
				return left_r / right_r;
				break;
			case '^':
				return left_r.pow_u(right_r.average);
			default:
				break;
			}
		}
	}
	void strin(char* input, variable* buffer)
	{
		//如果有括号
		if (strchr(input, '(') != NULL)
		{
			char *beg = strchr(input, '(');
			char *end;
			int i = 1;
			for (end = strchr(input, '(') + 1; i != 0; end++)
			{
				switch (*end)
				{
				case '(':
					i++;
					break;
				case ')':
					i--;
					break;
				default:
					break;
				}
			}
			end--;
			//如果式子在一头
			if (beg == input || *(end + 1) == '\0')
			{//如果式子左右都是括号
				if (beg == input && *(end + 1) == '\0')
				{
					*end = '\0';
					this->strin(beg + 1, buffer);
					return;
				}
				if (beg == input)
				{
					*end = '\0';
					strcpy(left_s, beg + 1);
					strcpy(right_s, end + 2);
					op = *(end + 1);
				}
				else
				{
					op = *(beg - 1);
					*(beg - 1) = '\0';
					strcpy(left_s, input);
					*end = '\0';
					strcpy(right_s, beg + 1);
				}
			}
			else
			{
				//如果括号在式子中间
				//如果括号左边是+-
				if (*(beg - 1) == '+' || *(beg - 1) == '-')
				{
					op = *(beg - 1);
					*(beg - 1) = '\0';
					strcpy(left_s, input);
					strcpy(right_s, beg);
				}
				else
				{
					op = *(end + 1);
					*(end + 1) = '\0';
					strcpy(left_s, input);
					strcpy(right_s, end + 2);
				}
			}
		}
		else
		{
			//没有括号
			if (strpbrk(input, "+-*/") != NULL)
			{//有运算符
				if (!(strchr(input, '+') == NULL && strchr(input, '-') == NULL))
				{
					op = *strpbrk(input, "+-");
					char *temp = strpbrk(input, "+-");
					*temp = '\0';
					strcpy(left_s, input);
					strcpy(right_s, temp + 1);
				}
				else
				{
					op = *strpbrk(input, "*/");
					char *temp = strpbrk(input, "*/");
					*temp = '\0';
					strcpy(left_s, input);
					strcpy(right_s, temp + 1);
				}
			}
			else
			{//没有运算符
				IsNum = true;
				if (buffer->GetbyName(*input) != NULL)
				{
					num = buffer->GetbyName(*input);
				}
				else
				{
					num = buffer->CreatebyName(*input);
				}
				return;
			}
		}
		//read left
		IsNum = false;
		left = (domath*)malloc(sizeof(domath));
		left->ini();
		left->strin(left_s, buffer);
		//read right
		right = (domath*)malloc(sizeof(domath));
		right->ini();
		right->strin(right_s, buffer);
	}
	void ini(void)
	{
		num = NULL;
		left = NULL;
		right = NULL;
	}
private:
	Uncertain_Num * num;
	domath *left;
	domath *right;	char left_s[BUFFER_SIZE];
	char right_s[BUFFER_SIZE];
	char op;
	bool IsNum;
};
int main(void)
{
	Uncertain_Num result;
	domath *math = (domath*)malloc(sizeof(domath));
	math->ini();
	variable *buffer = (variable*)malloc(sizeof(variable));
	buffer->ini();
	char input[BUFFER_SIZE];
	printf("输入算式，数字以字母代表。\n");
	scanf("%s", input);
	math->strin(input, buffer);
	result = math->caculat();
	printf("结果是：");
	result.print();
	printf("\n");
	getchar();
	getchar();
	return 0;
}
