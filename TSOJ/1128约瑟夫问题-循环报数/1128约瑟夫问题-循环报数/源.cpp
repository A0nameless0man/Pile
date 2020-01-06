#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

struct man
{
    int  No;
    man *Child;
};
template <typename T>
void swap(T &a, T &b)
{
    T t = a;
    a   = b;
    b   = t;
}
const int MAX_N = 10007;
man       people[MAX_N];
int       pop(int n, man *from)  //弹出from后面的第n个元素。
{
    for(int i = 2; i < n; i++)
    {
        from = from->Child;
    }
    int r       = from->Child->No;
    from->Child = from->Child->Child;
    return r;
}
int n, m, a, b, j, k;
int main(void)
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif  // DEBUG

    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            people[i].No    = i;
            people[i].Child = &people[i + 1];
        }
        man *from = people[n].Child = &people[1];
        while(from->Child != from)
        {
            int poped = pop(m, from);
            printf("%d", poped);
            putchar(' ');
            from = people[poped].Child;
        }
        printf("%d\n", from->No);
    }
    return 0;
}
