#define _CRT_SECURE_NO_WARNINGS
#include <random>
#include <stdio.h>
#include <string.h>
int         input[200000];
inline void swap(int &a, int &b)
{
    int t = a;
    a     = b;
    b     = t;
}
void q_short(int from, int to)
{

    if(to == from)
    {
        return;
    }
    if(to - from == 1)
    {
        if(input[from] > input[to])
        {
            swap(input[from], input[to]);
        }
        return;
    }
    int thatone = input[(from + to) / 2];
    int i = from, j = to;
    while(i < j)
    {
        while(input[i] < thatone)
        {
            i++;
        }
        while(input[j] > thatone)
        {
            j--;
        }
        if(i <= j)
        {
            swap(input[i], input[j]);
            i++;
            j--;
        }
    }
    if(from < j)
    {
        q_short(from, j);
    }
    if(i < to)
    {
        q_short(i, to);
    }
}
// void r_sort(int from, int to)
//{
//	int j, temp;
//	for (size_t i = from; i < to; i++)
//	{
//		j = from + rand() % (to - from);
//		temp = input[j];
//		input[j] = input[i];
//		input[i] = temp;//交换
//
//	}
//}
int main(void)
{
    unsigned int n;
    // l:;
    scanf("%d", &n);
    for(size_t i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }
    // r_sort(0, n - 1);
    q_short(0, n - 1);
    for(size_t i = 0; i < n; i++)
    {
        printf("%d", input[i]);
        if(i < n - 1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    // goto l;
    // getchar();
    // getchar();
    // getchar();
    // getchar();
}