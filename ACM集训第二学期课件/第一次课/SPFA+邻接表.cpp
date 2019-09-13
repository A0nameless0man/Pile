//SPFA+数组模拟邻接表模板 
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=10005;
int n,m,s; 

/*邻接表*/ 
struct edge
{
	int to;//该边指向何处 
	int next;//后（在数组中其实是前）一个由该点引出的边 
	int w;//边权 
}e[10000005];
int cnt=0;//队列最后一个元素指针
int p[MAXN];// 点i指向的第一条边下标p[i]（需要初始化）
void add_edge(int from,int to,int weight)
{
	e[++cnt].next=p[from];//指向下一个同源边
	p[from]=cnt;//更新队列指针
	e[cnt].w=weight;
	e[cnt].to=to; 
	return;
} 
/*邻接表*/


/*SPFA*/ 
queue<int> q;//访问队列 
bool visited[MAXN];//判断是否在队列中
int dist[MAXN];//从给定源点到i的距离为dist[i]
int in[MAXN];//负环判断 
bool accb[MAXN];//判断是否可达 

bool spfa(int node)
{
	memset(visited,0,sizeof(visited));//初始时不在队列中 
	memset(dist,0x3f,sizeof(dist));//初始时距离无限大 
	memset(in,0,sizeof(in));//in[i]>n即表示有负环 
	memset(accb,0,sizeof(accb));//初始都不可达 
	
	q.push(node);//源点进队 
	visited[node]=1;//进队标记 
	dist[node]=0;//源点初始化 
	
	 while(!q.empty())
	 {
	  	int t=q.front(); //从队头取出出发节点的编号t 
	  	q.pop();
		visited[t]=0;//出队，回到可访问状态 
		accb[t]=1;//点t可达 
	  	for(int i=p[t];i;i=e[i].next)//穷举可行边i 
	  	{
	  		int temp=e[i].to;//获取所到节点编号temp 
	  		if(dist[temp]>dist[t]+e[i].w)
	  		{
	  			dist[temp]=dist[t]+e[i].w;//更新长度
				if(!visited[temp])
				{
					q.push(temp);
					visited[temp]=1;//入队 
					if(++in[temp]>n)return false;//存在负环 
				 } 
			  }
		  }
	 }
	 return true;//无负环，算法处理完成 
 } 
/*SPFA*/ 


 int read()
 {
 	int x=0,f=1;char ch=getchar();
 	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
 	return x*f;
 }//快速读入 
 
 int main()
 {
 	memset(p,-1,sizeof(p)); 
 	n=read(),m=read(),s=read();
	for(int i=0;i<m;i++)
	{
		int x=read();
		int y=read();
		int z=read();
		add_edge(x,y,z);
	 } //预处理 
 	
 	spfa(s);
 	for(int i=1;i<=n;i++)
 	{
 		if(!accb[i])printf("2147483647 ");
 		else printf("%d ",dist[i]);
	 }
 	return 0;
 }
