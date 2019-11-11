```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <queue>
using ULL = unsigned long long;
const ULL MAX_N = 100007;
const ULL MAX_M = 26;
const ULL INF = -1;
ULL ctoi(char &c)
{
    return c - 'a';
}
struct Trie
{
    struct Node
    {
        ULL next[MAX_M];
        ULL fail;
        ULL count;
    } nodes[MAX_N];
    ULL root, cnt;
    void clear(void)
    {
        cnt = 0;
        root = newNode();
    }
    ULL newNode()
    {
        Node &cur = nodes[cnt];
        for (ULL i = 0; i < MAX_M; i++)
        {
            cur.next[i] = INF;
        }
        cur.fail = INF;
        cur.count = 0;
        ++cnt;
        return cnt - 1;
    }
    void insert(char buf[])
    {
        ULL len = strlen(buf);
        ULL cur = root;
        for (ULL i = 0; i < len; i++)
        {
            ULL &next = nodes[cur].next[ctoi(buf[i])];
            if (next == INF)
            {
                next = newNode();
            }
            cur = next;
        }
        nodes[cur].count++;
    }
    void buildFailTree(void)
    {
        std::queue<ULL> que;
        nodes[root].fail = root;
        auto op = [this, &que](const ULL &tar) -> void {
            for (ULL i = 0; i < MAX_M; i++)
            {
                if (nodes[tar].next[i] == INF)
                {
                    nodes[tar].next[i] = tar == root ? root : nodes[nodes[tar].fail].next[i];
                }
                else
                {
                    nodes[nodes[tar].next[i]].fail = tar == root ? root : nodes[nodes[tar].fail].next[i];
                    que.push(nodes[tar].next[i]);
                }
            }
        };
        op(root);
        while (!que.empty())
        {
            op(que.front());
            que.pop();
        }
    }
    int query(char buf[])
    {
        ULL len = strlen(buf);
        ULL cur = root;
        ULL ans = 0;
        for (ULL i = 0; i < len; i++)
        {
            cur = nodes[cur].next[ctoi(buf[i])];
            ULL tmp = cur;
            while (tmp != root)
            {
                ans += nodes[tmp].count;
                tmp = nodes[tmp].fail;
            }
        }
        return ans;
    }
    void debug(void)
    {
        for (ULL i = 0; i < cnt; i++)
        {
            printf("{\"id\" : %3llu , \"fail\" : %3llu , \"chi\" : [", i, nodes[i].fail);
            for (ULL j = 0; j < MAX_M; j++)
            {
                printf(" %3llu ,", nodes[i].next[j]);
            }
            printf("],\n");
        }
    }
};
char buf[MAX_N];
Trie acm;
int main(void)
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int m;
        scanf("%d", &m);
        acm.Tire();
        while (m--)
        {
            scanf("%s", buf);
            acm.insert(buf);
        }
        acm.buildFailTree();
        scanf("%s", buf);
        printf("%d match found.\n", acm.query(buf));
        // acm.debug();
    }
    return 0;
}
/*
1
10
a
b
ab
c
d
cd
abcd
e
f
ef
abcdef
*/
```