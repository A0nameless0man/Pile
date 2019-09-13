#include<bits/stdc++.h>
using namespace std; 

int n,m;
int c[305][305];
int ans[305],bestn=0;
int s[305];

void dfs(int x,int cnt){
	if(cnt>bestn){
		bestn=cnt;
		for(int i=1;i<=n;++i)ans[i]=s[i];
	}//update
	if(x>n)return;
	if(n-x+1+cnt<=bestn)return;//purning
	dfs(x+1,cnt);//not pick
	for(int i=1;i<x;++i)if(s[i]&&c[i][x])return;
	s[x]=1;dfs(x+1,cnt+1);s[x]=0;//pick
	return;
}

int main(){
	cin>>n>>m;
	for(int i=0,a,b;i<m;++i){
		cin>>a>>b;
		c[a][b]=c[b][a]=1;
	}
	dfs(1,0);
	cout<<bestn<<endl; 
	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
}
