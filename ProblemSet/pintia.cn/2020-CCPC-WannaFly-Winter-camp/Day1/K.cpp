#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using ULL = long long;

const ULL MAX_N = 1000007;
const ULL MAX_M = 26;
const ULL INF   = static_cast<ULL>(10e15);

inline ULL ctoi(const char &c)
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
        ULL cost;
        ULL len;
    } nodes[MAX_N];
    ULL  root, cnt;
    void clear(void)
    {
        cnt  = 0;
        root = newNode();
    }
    inline ULL newNode()
    {
        Node &cur = nodes[cnt];
        for(ULL i = 0; i < MAX_M; i++)
        {
            cur.next[i] = INF;
        }
        cur.fail  = INF;
        cur.count = 0;
        cur.cost  = INF;
        ++cnt;
        return cnt - 1;
    }
    void insert(const char buf[], ULL cost = 0)
    {
        ULL len = strlen(buf);
        ULL cur = root;
        for(ULL i = 0; i < len; i++)
        {
            ULL &next = nodes[cur].next[ctoi(buf[i])];
            if(next == INF)
            {
                next = newNode();
            }
            cur = next;
        }
        nodes[cur].count++;
        nodes[cur].cost = std::min(nodes[cur].cost, cost);
        nodes[cur].len  = len;
    }
    void buildFailTree(void)
    {
        std::queue<ULL> que;
        nodes[root].fail = root;
        auto op          = [this, &que](const ULL &tar) -> void {
            for(ULL i = 0; i < MAX_M; i++)
            {
                if(nodes[tar].next[i] == INF)
                {
                    nodes[tar].next[i] = tar == root ? root : nodes[nodes[tar].fail].next[i];
                }
                else
                {
                    nodes[nodes[tar].next[i]].fail =
                      tar == root ? root : nodes[nodes[tar].fail].next[i];
                    que.push(nodes[tar].next[i]);
                }
            }
        };
        op(root);
        while(!que.empty())
        {
            op(que.front());
            que.pop();
        }
    }
    int query(const char buf[], ULL dp[])
    {
        ULL len = strlen(buf);
        ULL cur = root;
        for(ULL i = 0; i < len; ++i)
        {
            dp[i] = INF;
        }
        for(ULL i = 0; i < len; i++)
        {
            cur     = nodes[cur].next[ctoi(buf[i])];
            ULL tmp = cur;
            while(tmp != root)
            {
                // ans += nodes[tmp].count;
                if(nodes[tmp].count)
                {
                    if(i >= nodes[tmp].len)
                    {
                        dp[i] = std::min(dp[i], dp[i - nodes[tmp].len] + nodes[tmp].cost);
                    }
                    else
                    {
                        dp[i] = nodes[tmp].cost;
                    }
                }
                tmp = nodes[tmp].fail;
            }
        }
        return 0;
    }
    void debug(void)
    {
        for(ULL i = 0; i < cnt; i++)
        {
            printf("{\"id\" : %3llu , \"fail\" : %3llu , \"chi\" : [", i, nodes[i].fail);
            for(ULL j = 0; j < MAX_M; j++)
            {
                printf(" %3llu ,", nodes[i].next[j]);
            }
            printf("],\n");
        }
    }
};
char buf[MAX_N];
ULL  dp[MAX_N];
Trie acm;
int  main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        acm.clear();
        while(n--)
        {
            int cost;
            scanf("%s", buf);
            // std::cin >> cost;
            scanf("%d", &cost);
            acm.insert(buf, cost);
        }
        scanf("%s", buf);
        acm.buildFailTree();
        acm.query(buf, dp);
        ULL len = strlen(buf);

        if(dp[len - 1] != INF)
        {
            std::cout << dp[len - 1] << std::endl;
        }
        else
        {
            std::cout << -1 << std::endl;
        }
    }
    return 0;
}
/*
4
ab 5
cd 10
abc 100
d 1
abcd
3
ab 10
ab 5
a 1
ababa
3
ba 10
ab 5
a 1
ababa
3
ba 10
b 2
a 1
ababa
*/
