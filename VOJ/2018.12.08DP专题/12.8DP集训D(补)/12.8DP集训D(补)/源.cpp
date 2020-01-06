#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
const int  MAX_N = 10007;
int        n, right, left, useddot, usedside;
inline int max(int a, int b)
{
    return a > b ? a : b;
}
struct dot;
struct side;
side *lloc(void);
struct side
{
    dot * to;
    side *next;
    void  ini(dot *t)
    {
        to   = t;
        next = NULL;
    }
    void add(dot *t)
    {
        if(next == NULL)
        {
            next = lloc();
            next->ini(t);
        }
        else
        {
            next->add(t);
        }
    }
    void end(void)
    {
        if(next != NULL)
        {
            next->end();
            next = NULL;
        }
    }
};
struct dot
{
    side *sides;
    int   No;
    void  ini(int n)
    {
        sides = NULL;
        No    = n;
    }
    void add(dot *t)
    {
        if(sides == NULL)
        {
            sides = lloc();
            sides->ini(t);
        }
        else
        {
            sides->add(t);
        }
    }
    void end(void)
    {
        if(sides != NULL)
        {
            sides->end();
            sides = NULL;
        }
    }
    int depth(int no)
    {
        int   r        = 1;
        side *nextside = sides;
        while(nextside != NULL)
        {
            if(nextside->to->No != no)
            {
                r += nextside->to->depth(this->No);
                if(r > n / 2)
                {
                    break;
                }
            }
            nextside = nextside->next;
        }
        return r;
    }
    bool cutable(void)
    {
        int   r        = 0;
        side *nextside = sides;
        while(nextside != NULL)
        {
            if(nextside->to != this)
            {
                r = max(r, nextside->to->depth(this->No));
                if(r > n / 2)
                {
                    break;
                }
            }
            nextside = nextside->next;
        }
        return r <= n / 2;
    }
    bool ring(dot *nd, int depth, int no)
    {
        if(this == nd && depth != 0 || depth > n)
        {
            return true;
        }
        else
        {
            side *ns = sides;
            while(ns != NULL)
            {
                if(ns->to->No != no)
                {
                    if(ns->to->ring(nd, depth + 1, this->No))
                    {
                        return true;
                    }
                }
                ns = ns->next;
            }
            return false;
        }
    }
};
dot   grapth[MAX_N];
side  s[MAX_N];
side *lloc(void)
{
    return &s[usedside++];
}
int main(void)
{
    while(scanf("%d", &n) != EOF)
    {
        useddot = usedside = 0;
        for(size_t i = 0; i <= n; i++)
        {
            grapth[i].end();
            grapth[i].ini(i);
            s[i].next = NULL;
            s[i].to   = 0;
        }
        for(size_t i = 0; i < n - 1; i++)
        {
            scanf("%d%d", &left, &right);
            grapth[left].add(&grapth[right]);
            grapth[right].add(&grapth[left]);
        }
        for(size_t i = 1; i <= n; i++)
        {
            if(grapth[i].ring(&grapth[i], 0, i))
            {
                goto l;
            }
        }
        for(size_t i = 1; i <= n; i++)
        {
            if(grapth[i].cutable())
            {
                printf("%d\n", i);
            }
        }
        continue;
    l:;
        printf("NONE\n");
    }
    return 0;
}
