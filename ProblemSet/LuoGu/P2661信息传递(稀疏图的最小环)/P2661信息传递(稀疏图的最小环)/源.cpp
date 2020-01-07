#define _CRT_SECURE_NO_WARNINGS
#define DEBUG
#include <algorithm>
#include <ctype.h>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
template <typename T>
void swap(T &a, T &b)
{
    T t = a;
    a   = b;
    b   = t;
}
class student
{
public:
    int  loopNo;
    int  LookForLoop(int);
    void set(int);
    void resetDeep(void)
    {
        deepth = -1;
    }
    bool isUsed(void)
    {
        return used;
    }
    void ini(void)
    {
        Ti     = this;
        deepth = -1;
        used   = false;
    }
    student(student *T)
    {
        Ti     = T;
        deepth = -1;
        used   = false;
    }
    student(void)
    {
        student(this);
    }

private:
    student *Ti;
    int      deepth;
    bool     used;
};
const int MAX_N = 200007;
int       n, m, a, b, j, k;
int       minLoop = MAX_N;
student   room[MAX_N];
void      student::set(int T)
{
    Ti = &room[T];
}
int student::LookForLoop(int deep)  //直接调用时deep=0
{
    loopNo           = this - room;
    student *current = this;
#ifdef DEBUG
    printf("\n\nstu:%d\n\r", current - room);
#endif  // DEBUG

    while(true)
    {
        if(current->isUsed() && current->loopNo != loopNo || deep > minLoop)
        {
#ifdef DEBUG
            printf("quit.\n");
#endif  // DEBUG
            return MAX_N;
        }
        current->used   = true;
        current->loopNo = loopNo;
        if(current->deepth != -1)
        {
#ifdef DEBUG
            printf("loop!\n");
#endif  // DEBUG

            return deep - current->deepth;
        }
        else
        {
            current->deepth = deep;
            current         = current->Ti;
            deep++;
#ifdef DEBUG
            printf("deep:%d\r", deep);
#endif  // DEBUG
        }
    }
}
int main(void)
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif  // DEBUG

    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            room[i].ini();
            scanf("%d", &m);
            room[i].set(m);
        }
        minLoop = MAX_N;
        srand(200);
        for(int i = 1; i <= n; i++)
        {
            // k = rand() % n + 1;
            k = i;
            if(!room[k].isUsed())
            {
                minLoop = std::min(minLoop, room[k].LookForLoop(0));
            }
        }
        printf("%d\n", minLoop);
    }
#ifdef DEBUG
    system("pause");
    system("pause");
#endif  // DEBUG

    return 0;
}
