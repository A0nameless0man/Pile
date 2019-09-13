const int N=1005,M=100005; 
struct edge{
	/*以下内容为指针域*/ 
	int next;//表示同出发点的下一条边
	/*以下内容为data域*/ 
	int to;//表示当前边所达点 
	int weight;//该边权重 
}e[M*2];//*2是因为无向图需要建立反向边 
int cnt=0;//cnt表示当前存的边的个数，同时也作为数组e的下标
int tail[N];//tail[i](有时也写作head),表示以i为出发点的第一条边的下标 

void add_edge(int f,int t,int w){//新增一条边
	/*首先存入数据域的内容*/ 
	e[cnt].to=t;
	e[cnt].weight=w;
	/*然后指针域*/
	e[cnt].next=tail[f];//把这条新边接到之前关于起点f的边上面
	tail[f]=cnt;//更新tail数组,其实就是链表操作
	++cnt; 
}

void INITIATION(){
	/*将tail初始化为-1，表示指向NULL*/
	for(int i=1;i<=N;++i)tail[i]=-1; 
}
 
void dfs(int cur){
	 for(int i=tail[cur];//从第一条边开始 
	 	 ~i;//等价于i!=-1，也就是到指向NULL为止 
		 ++i;)//迭代 
		{
	 	//这里写dfs的操作即可 
	 } 
}


