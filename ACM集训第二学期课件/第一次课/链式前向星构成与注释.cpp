const int N=1005,M=100005; 
struct edge{
	/*��������Ϊָ����*/ 
	int next;//��ʾͬ���������һ����
	/*��������Ϊdata��*/ 
	int to;//��ʾ��ǰ������� 
	int weight;//�ñ�Ȩ�� 
}e[M*2];//*2����Ϊ����ͼ��Ҫ��������� 
int cnt=0;//cnt��ʾ��ǰ��ıߵĸ�����ͬʱҲ��Ϊ����e���±�
int tail[N];//tail[i](��ʱҲд��head),��ʾ��iΪ������ĵ�һ���ߵ��±� 

void add_edge(int f,int t,int w){//����һ����
	/*���ȴ��������������*/ 
	e[cnt].to=t;
	e[cnt].weight=w;
	/*Ȼ��ָ����*/
	e[cnt].next=tail[f];//�������±߽ӵ�֮ǰ�������f�ı�����
	tail[f]=cnt;//����tail����,��ʵ�����������
	++cnt; 
}

void INITIATION(){
	/*��tail��ʼ��Ϊ-1����ʾָ��NULL*/
	for(int i=1;i<=N;++i)tail[i]=-1; 
}
 
void dfs(int cur){
	 for(int i=tail[cur];//�ӵ�һ���߿�ʼ 
	 	 ~i;//�ȼ���i!=-1��Ҳ���ǵ�ָ��NULLΪֹ 
		 ++i;)//���� 
		{
	 	//����дdfs�Ĳ������� 
	 } 
}


