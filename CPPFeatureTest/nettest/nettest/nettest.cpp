// nettest.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <time.h>/*使用了sleep*/

//#define IPSTR "207.148.72.48" //服务器IP地址;
//#define PORT 80
//#define BUFSIZE 1024
typedef void (*load)(void *mun);

bool createthreat(load task, int *input, unsigned int id, void *handle)
{
    if(!(handle =
           (void *) _beginthreadex(NULL, 0, (_beginthreadex_proc_type) task, input, 0, NULL)))
    {
        return false;
    }
    return true;
}

typedef class node
{
public:
    void (*task)(void *mun); /*需要执行的任务*/
    unsigned int nodeid;     /*识别号*/
    struct node *next;       /*链表*/
    int          taskid;
    void *       myhandle;
    bool         start()
    {
        return createthreat(task, &taskid, nodeid, myhandle);
    }

} TaskNode;

typedef struct nodepool
{
    struct node *firstnode;
    unsigned int nodecount;

} Nodepool;
int addnode(void (*task)(void *mun), unsigned int id, nodepool *pool)
{
    node *newnode   = (node *) (malloc(sizeof(node))); /*初始化节点(没有做防止内存泄露的工作，当心)*/
    newnode->task   = task;
    newnode->nodeid = id;
    newnode->next   = NULL;
    newnode->taskid = (int) id;
    pool->nodecount++; /*增加节点计数*/
    /*添加任务到队伍未端*/
    node *temp = pool->firstnode;
    if(pool->firstnode == NULL)
    {
        pool->firstnode = newnode;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return pool->nodecount;
}
void test(void *a)
{
    int b = *(int *) a;
    printf("%d\n", b);
}
int main(void)
{
    static nodepool *pool = (nodepool *) malloc(sizeof(nodepool));
    pool->firstnode       = NULL;
    pool->nodecount       = 0;
    int count             = 0;
    for(unsigned int i = 0; i < 10; i++)
    {
        printf("node%dcreated\n", addnode((void (*)(void *)) * test, i, pool));
    }
    node *temp = pool->firstnode;
    while(temp->next != NULL)
    {
        temp->start();
        temp = temp->next;
        count++;
    }
    temp->start();
    getchar();
    return count;
}