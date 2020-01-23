#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
/*
Time: 2020-01-23 11:18:14
Describe: accepted after learned to jump over meaning less jump on fail tree
Statue: ACCEPTED
*/
using ULL       = unsigned long long;
const ULL MAX_N = 500007;
const ULL MAX_M = 26;
const ULL INF   = 10e15;

inline ULL ctoi(char &c)
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
    ULL root, cnt;

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
        cur.len   = 0;
        ++cnt;
        return cnt - 1;
    }

    inline void insert(char buf[], ULL cost = 0)
    {
        auto len = strlen(buf);
        ULL  cur = root;
        for(size_t i = 0; i < len; i++)
        {
            ULL &next = nodes[cur].next[ctoi(buf[i])];
            if(next == INF)
            {
                next = newNode();
            }
            cur = next;
        }
        nodes[cur].count = 1;
        nodes[cur].cost  = std::min(nodes[cur].cost, cost);
        nodes[cur].len   = len;
    }

    void buildFailTree(void)
    {
        std::queue<ULL> que;
        nodes[root].fail = root;
        for(ULL i = 0; i < MAX_M; ++i)
        {
            auto cur = nodes[root].next[i];
            if(cur != INF)
            {
                nodes[cur].fail = root;
                que.push(cur);
            }
            else
            {
                nodes[root].next[i] = root;
            }
        }
        while(!que.empty())
        {
            auto cur = que.front();
            que.pop();
            for(ULL i = 0; i < MAX_M; ++i)
            {
                ULL next = nodes[cur].next[i];
                if(next == INF)
                {
                    nodes[cur].next[i] = nodes[nodes[cur].fail].next[i];
                }
                else
                {
                    nodes[next].fail = nodes[nodes[cur].fail].next[i];
                    que.push(next);
                }
            }
        }
    }
    void query(char buf[], ULL dp[])
    {
        ULL len = strlen(buf);
        ULL cur = root;
        for(ULL i = 0; i < len; i++)
        {
            cur      = nodes[cur].next[ctoi(buf[i])];
            ULL tmp  = cur;
            ULL tmp2 = tmp;
            dp[i]    = INF;
            while(tmp != root)
            {
                if(nodes[tmp].count)
                {
                    if(tmp2!=tmp)
                    {  // Skip the useless fail jump;
                        nodes[tmp2].fail = tmp;
                        tmp2             = tmp;
                    }
                    if(i >= nodes[tmp].len)
                    {
                        dp[i] = std::min(dp[i], dp[i - nodes[tmp].len] + nodes[tmp].cost);
                    }
                    else
                    {
                        dp[i] = std::min(dp[i], nodes[tmp].cost);
                    }
                }
                tmp = nodes[tmp].fail;
            }
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
        // for(int i = 0; i < len;i++)
        // {
        //     std::cout << dp[i] << " ";
        // }
        // std::cout << std::endl;
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
