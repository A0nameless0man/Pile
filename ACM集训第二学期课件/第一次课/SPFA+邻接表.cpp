//SPFA+����ģ���ڽӱ�ģ�� 
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=10005;
int n,m,s; 

/*�ڽӱ�*/ 
struct edge
{
	int to;//�ñ�ָ��δ� 
	int next;//������������ʵ��ǰ��һ���ɸõ������ı� 
	int w;//��Ȩ 
}e[10000005];
int cnt=0;//�������һ��Ԫ��ָ��
int p[MAXN];// ��iָ��ĵ�һ�����±�p[i]����Ҫ��ʼ����
void add_edge(int from,int to,int weight)
{
	e[++cnt].next=p[from];//ָ����һ��ͬԴ��
	p[from]=cnt;//���¶���ָ��
	e[cnt].w=weight;
	e[cnt].to=to; 
	return;
} 
/*�ڽӱ�*/


/*SPFA*/ 
queue<int> q;//���ʶ��� 
bool visited[MAXN];//�ж��Ƿ��ڶ�����
int dist[MAXN];//�Ӹ���Դ�㵽i�ľ���Ϊdist[i]
int in[MAXN];//�����ж� 
bool accb[MAXN];//�ж��Ƿ�ɴ� 

bool spfa(int node)
{
	memset(visited,0,sizeof(visited));//��ʼʱ���ڶ����� 
	memset(dist,0x3f,sizeof(dist));//��ʼʱ�������޴� 
	memset(in,0,sizeof(in));//in[i]>n����ʾ�и��� 
	memset(accb,0,sizeof(accb));//��ʼ�����ɴ� 
	
	q.push(node);//Դ����� 
	visited[node]=1;//���ӱ�� 
	dist[node]=0;//Դ���ʼ�� 
	
	 while(!q.empty())
	 {
	  	int t=q.front(); //�Ӷ�ͷȡ�������ڵ�ı��t 
	  	q.pop();
		visited[t]=0;//���ӣ��ص��ɷ���״̬ 
		accb[t]=1;//��t�ɴ� 
	  	for(int i=p[t];i;i=e[i].next)//��ٿ��б�i 
	  	{
	  		int temp=e[i].to;//��ȡ�����ڵ���temp 
	  		if(dist[temp]>dist[t]+e[i].w)
	  		{
	  			dist[temp]=dist[t]+e[i].w;//���³���
				if(!visited[temp])
				{
					q.push(temp);
					visited[temp]=1;//��� 
					if(++in[temp]>n)return false;//���ڸ��� 
				 } 
			  }
		  }
	 }
	 return true;//�޸������㷨������� 
 } 
/*SPFA*/ 


 int read()
 {
 	int x=0,f=1;char ch=getchar();
 	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
 	return x*f;
 }//���ٶ��� 
 
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
	 } //Ԥ���� 
 	
 	spfa(s);
 	for(int i=1;i<=n;i++)
 	{
 		if(!accb[i])printf("2147483647 ");
 		else printf("%d ",dist[i]);
	 }
 	return 0;
 }
