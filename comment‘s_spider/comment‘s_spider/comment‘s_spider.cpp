// comment‘s_spider.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#pragma once
#include "targetver.h"
//#include<windef.h>
#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<string.h>
#include<WinSock2.h>/*这是<sys/socket.h>的代替*/
#include<io.h>
#include<process.h>/*这一行及以上一行代替<nuistd.h>*/
#include<fcntl.h>
#pragma comment(lib,"WSock32.lib")
#define BUFF_MAX_SIZE 1024*1024
#define PAGE_MAX_SIZE 4096*128
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
const int MAX_URL_LEN = 1024;
const int MAX_FILENAME_LEN = 64;
const int MAX_REUQEST_LEN = 1024;
const int MAX_MID_LEN = 15;
const int MID_PER_NODE = 100;
const long int MID_STR = 10000;
const long int MID_STP = 10010;
const unsigned int WAIT_FOR_RECEVE = 1000;
void to_string(char* output, unsigned long int input)
{

	char numbers[] = { "0123456789" };
	char temp = 0;
	int i = 0;
	for (; input >= 10; i++)
	{
		output[i] = numbers[input % 10];
		input /= 10;
	}
	output[i] = numbers[input];
	output[++i] = '\0';
	i--;
	for (size_t a = 0; a < i / 2; a++)/*手动翻转*/
	{
		temp = output[a];
		output[a] = output[i - a];
		output[i - a] = temp;
	}
}
void request(char* input, unsigned long int oid)
{
	char all[] = "?&oid=";
	char all2[] = "&type=1";
	char mid[MAX_MID_LEN] = { 0 };
	to_string(mid, oid);
	strcat_s(input, MAX_REUQEST_LEN, all);
	strcat_s(input, MAX_REUQEST_LEN, mid);
	strcat_s(input, MAX_REUQEST_LEN, all2);

}

void parseURL(char * url, char* host, char* path)/*解析*/
{
	//char tmp[MAX_URL_LEN] = {0};
	char*ptmp = NULL;
	strcpy_s(host, strlen(url) + 1, url);
	if ((ptmp = strstr(url, "http://")) != NULL)//http format
	{
		ptmp = ptmp + 7;
		strcpy_s(host, strlen(ptmp) + 1, ptmp);
	}
	else if (ptmp = NULL, (ptmp = strstr(url, "https://")) != NULL)//https format
	{
		ptmp = ptmp + 8;
		strcpy_s(host, strlen(ptmp) + 1, ptmp);
	}
	ptmp = NULL;
	if ((ptmp = strpbrk(host, "/")) != NULL)/*找到host结束之处的'/'将其替换为'\0'*/
	{
		strcpy_s(path, strlen(ptmp) + 1, ptmp);
		ptmp[0] = '\0';
	}

}
void getPage(char host[MAX_URL_LEN], char path[MAX_URL_LEN], char file[MAX_FILENAME_LEN], unsigned long int mid)
{


	struct hostent *phost;
	phost = NULL;/*关于host的指针*/

	if (NULL == (phost = gethostbyname(host)))
	{
		printf("host err\n");
		printf("%d", GetLastError());
		getchar();
		exit(1);
	}

	struct sockaddr_in pin;
	int port = 80;
	memset(&pin, 0, sizeof(pin));
	pin.sin_family = AF_INET;
	pin.sin_port = htons(port);
	/*不同的机器HBO不相同，与CPU设计有关，
	数据的顺序是由cpu决定的,而与操作系统无关。
	如 Intelx86结构下,short型数0x1234表示为34 12,
	int型数0x12345678表示为78 56 34 12
	如IBM power PC结构下,short型数0x1234表示为12 34,
	int型数0x12345678表示为12   34 56 78
	由于这个原因不同体系结构的机器之间无法通信,
	所以要转换成一种约定的数序,也就是网络字节顺序,
	其实就是如同powerpc那样的顺序 。
	在PC开发中有ntohl和htonl函数可以用来进行网络字节和主机字节的转换。
	ps:摘自https://www.cnblogs.com/orlion/p/6104204.html */
	pin.sin_addr.s_addr = ((struct in_addr*)(phost->h_addr))->s_addr;
	int isock;/*socket的指针*/
	if ((isock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)/*建立连接*/
	{
		printf("socket err\n");
		printf("%d", GetLastError());
		getchar();

		exit(1);
	}
	char requestHeader[MAX_REUQEST_LEN] = "GET ";/*制造HTTP请求,类型为GET*/
	strcat_s(requestHeader, path);
	request(requestHeader, mid);
	/*准备在这里插入参数*/
	strcat_s(requestHeader, " HTTP/1.1\r\nHost: ");
	strcat_s(requestHeader, host);
	strcat_s(requestHeader, "\r\nAccept: */*\r\n");
	strcat_s(requestHeader, "User-Agent: Mozilla/4.0(compatible)\r\n");
	strcat_s(requestHeader, "Connection: Keep-Alive\r\n");
	strcat_s(requestHeader, "\r\n");

	if (connect(isock, (struct sockaddr*)&pin, sizeof(pin)) == -1)
	{
		printf("connect err. Code=%d\n",GetLastError());
		exit(1);
	}

	if (send(isock, requestHeader, strlen(requestHeader), 0) == -1)
	{
		printf("send err\n");
		printf("%d", GetLastError());
		getchar();

		exit(1);
	}
	struct timeval timeout = { 1,0 };
	setsockopt(isock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval));
	char buffer[BUFF_MAX_SIZE];
	char* start;
	char* stop;
	int len;
	//printf("Start fetch\n");
	int flag = 0;
	Sleep(WAIT_FOR_RECEVE);
	FILE *output = fopen(file, "a");
	while ((len = recv(isock, buffer, BUFF_MAX_SIZE - 2, 0)) > 0)
	{
		buffer[len] = '\0';
		stop = buffer;
		while ((stop = strchr(stop,'\n')) != NULL)
		{
			*stop = ' ';
		}
		//;
		//fputs("from/**\n", output);
		//fputs(buffer,output);
		//fputc('\n', output);
		//fputs("to**/\n", output);
		//;
		start = buffer;
		for (size_t i = 0; i <2; i++)
		{
			start++;
			(start = strstr(start, "message")/*+3+strlen("message")*/);

		}
		if (start == NULL)
		{
			fputs("no message\n", output);
		}
		else 
		{
			stop = start;
			for (size_t i = 0; i < 3; i++)
			{
				++stop;
				stop = strchr(stop, '\"');
			}
			if (stop != NULL)
			{
				*stop = '\0';
				fputs(start, output);
				fputs("\n", output);

			}
			else
			{
				fputs("message error\n", output);
			}

		}
	}
	fclose(output);
	//close(isock);

}

int spider(unsigned long int *mid)
{
	printf("%d start\n", (*mid)*MID_PER_NODE);
	WSAData wsadata;

	WSAStartup(MAKEWORD(2, 2), &wsadata);
	char url[MAX_URL_LEN] = "https://api.bilibili.com/x/v2/reply";
	char host[MAX_URL_LEN];
	memset(host, 0, MAX_URL_LEN);
	char path[MAX_URL_LEN];
	memset(path, 0, MAX_URL_LEN);
	char file[MAX_FILENAME_LEN] = {0};
	to_string(file, *mid);
	strcat(file, ".txt");
	//parse url to get host and page path
	parseURL(url, host, path);
	//puts(host);
	//puts(path);
	//connect and sv the page into a file
	for (size_t i = 0; i <MID_PER_NODE; i++)
	{
		getPage(host, path, file,MID_PER_NODE*(*mid)+i);

	}

	printf("%d finish\n", *mid);
	//getchar();
	return 0;
}
typedef void(*load)(void *mun);


bool createthreat(load task, int *input, unsigned int id, void *handle)
{
	if (!(handle = (void*)_beginthreadex(NULL, 0, (_beginthreadex_proc_type)task, input, 0, NULL)))
	{
		return false;
	}
	return true;
}

typedef class node
{
public:
	void(*task)(void *mun);/*需要执行的任务*/
	unsigned int nodeid;/*识别号*/
	struct node *next;/*链表*/
	int taskid;
	void  *myhandle;
	bool start()
	{
		return createthreat(task, &taskid, nodeid, myhandle);
	}

}TaskNode;

typedef struct nodepool
{
	struct node *firstnode;
	unsigned int nodecount;

}Nodepool;
int addnode(void(*task)(void *mun), unsigned int id, nodepool *pool)
{
	node *newnode = (node*)(malloc(sizeof(node)));/*初始化节点(没有做防止内存泄露的工作，当心)*/
	newnode->task = task;
	newnode->nodeid = id;
	newnode->next = NULL;
	newnode->taskid = (int)id;
	pool->nodecount++;/*增加节点计数*/
					  /*添加任务到队伍未端*/
	node *temp = pool->firstnode;
	if (pool->firstnode == NULL)
	{
		pool->firstnode = newnode;
	}
	else {
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
	return pool->nodecount;
}
int main(void)
{
	static nodepool *pool = (nodepool*)malloc(sizeof(nodepool));
	pool->firstnode = NULL;
	pool->nodecount = 0;
	int count = 0;
	for (unsigned int i = MID_STR; i < MID_STP; i++)
	{
		printf("node%dcreated\n", addnode((void(*)(void *))*spider, i, pool));
	}
	node *temp = pool->firstnode;
	while (temp->next != NULL)
	{
		temp->start();
		temp = temp->next;
		count++;
	}temp->start();
	getchar();
	return count;
}