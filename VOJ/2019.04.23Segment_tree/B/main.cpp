#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <stack>
#include <stdio.h>
struct node
{
    int   max;
    int   left;
    int   right;
    int   toSet;
    node *l;
    node *r;
    node *p;
};
bool isLeaf(const node &a)
{
    return a.left == a.left;
}
void pushDown(node &a)
{
    if(a.toSet != 0)
    {
        if(a.l != NULL)
        {
            node &l = *(a.l);
            if(!isLeaf(l) && l.toSet != 0)
            {
                pushDown(l);
            }
            l.max   = a.toSet;
            l.toSet = a.toSet;
        }
        if(a.r != NULL)
        {
            node &r = *(a.r);
            if(!isLeaf(r) && r.toSet != 0)
            {
                pushDown(r);
            }
            r.max   = a.toSet;
            r.toSet = a.toSet;
        }
        a.toSet = 0;
    }
}
void takeUp(node &a)
{
    a.max = std::max(((a.r == NULL) ? 0 : a.r->max), ((a.l == NULL) ? 0 : a.l->max));
}
void pushUp(node &a)
{
    if(a.p != NULL)
    {
        takeUp(*(a.p));
        pushUp(*(a.p));
    }
}
int max(int from, int to, node &a)
{
    int ans = 0;
    if(from <= a.left && to >= a.right)
    {
        ans = std::max(ans, a.max);
    }
    else
    {
        if(a.l != NULL)
        {
            node &l = *(a.l);
            if(l.left <= to && l.right >= to || l.left <= from && l.right >= from ||
               from <= l.left && to >= l.right)
            {
                ans = std::max(ans, max(from, to, l));
            }
        }
        if(a.r != NULL)
        {
            node &r = *(a.r);
            if(r.left <= to && r.right >= to || r.left <= from && r.right >= from ||
               from <= r.left && to >= r.right)
            {
                ans = std::max(ans, max(from, to, r));
            }
        }
    }
    return ans;
}

void set(int from, int to, node &a, int val)
{
    if(from <= a.left && to >= a.right)
    {
        a.max   = val;
        a.toSet = val;
        pushUp(a);
    }
    else
    {
        if(a.l != NULL)
        {
            node &l = *(a.l);
            if(l.left <= to && l.right >= to || l.left <= from && l.right >= from ||
               from <= l.left && to >= l.right)
            {
                set(from, to, l, val);
            }
        }
        if(a.r != NULL)
        {
            node &r = *(a.r);
            if(r.left <= to && r.right >= to || r.left <= from && r.right >= from ||
               from <= r.left && to >= r.right)
            {
                set(from, to, r, val);
            }
        }
    }
}

void build(size_t n, node *tar)
{
    struct val
    {
        int pos;
        int left;
        int right;
    };
    std::stack<val> stack;
    // std::stack<size_t> s2;
    stack.push(val({ (int) 1, (int) 1, (int) n }));
    while(!stack.empty())
    {
        val V = stack.top();
        stack.pop();
        tar[V.pos].left  = V.left;
        tar[V.pos].right = V.right;
        tar[V.pos].max   = 0;
        tar[V.pos].toSet = 0;
        if(V.pos == 1)
        {
            tar[V.pos].p = NULL;
        }
        else
        {
            tar[V.pos].p = tar + V.pos / 2;
        }
        if(V.left == V.right)
        {
            tar[V.pos].l = NULL;
            tar[V.pos].r = NULL;
            scanf("%d", &tar[V.pos].max);
            pushUp(tar[V.pos]);
        }
        else
        {
            tar[V.pos].l = tar + V.pos * 2;
            tar[V.pos].r = tar + V.pos * 2 + 1;
            int mid      = (V.left + V.right) / 2;
            stack.push(val({ V.pos * 2 + 1, mid + 1, V.right }));
            stack.push(val({ V.pos * 2, V.left, mid }));
        }
    }
    // for (size_t i = n/2; i != size_t(-1); i--)
    //{
    //	takeUp(tar[i]);
    //}
}
node no[200000 * 10];
int  main(void)
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        build(n, no);
        char s[10];
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%s", s);
            scanf("%d%d", &a, &b);
            switch(s[0])
            {
                case 'Q':
                    // std::cin >> a >> b;
                    // std::cout << S_t.max(a - 1, b - 1) << std::endl;
                    printf("%d\n", max(a, b, no[1]));
                    break;
                case 'U':
                    // std::cin >> a >> c;
                    set(a, a, no[1], b);
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}