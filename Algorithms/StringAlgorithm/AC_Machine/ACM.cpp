#include <cstring>
#include <iostream>
#include <queue>
const size_t MAX_N = 100007;
const size_t MAX_M = 26;
const size_t INF = -1;
size_t ctoi(char &c)
{
    return c - 'a';
}
struct Trie
{
    struct Node
    {
        size_t next[MAX_M];
        size_t fail;
        size_t count;
    } nodes[MAX_N];
    size_t root, cnt;
    void Tire(size_t n = MAX_N)
    {
        cnt = 0;root = newNode();
    }
    size_t newNode()
    {
        Node &cur = nodes[cnt];
        for (size_t i = 0; i < MAX_M; i++)
        {
            cur.next[i] = INF;
        }
        cur.fail = INF;
        cur.count = 0;
        ++cnt;
        return cnt - 1;
    }
    void insert(char buf[],size_t id)
    {
        size_t len = strlen(buf);
        size_t cur = root;
        for (size_t i = 0; i < len;i++)
        {
            size_t &next = nodes[cur].next[ctoi(buf[i])];
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
        std::queue<size_t> que;
        nodes[root].fail = root;
        for (size_t i = 0; i < MAX_M; i++)
        {
            if(nodes[root].next[i]==INF)
            {
                nodes[root].next[i] = root;
            }
            else
            {
                nodes[nodes[root].next[i]].fail = root;
                
            }
            
        }
        
    }
};