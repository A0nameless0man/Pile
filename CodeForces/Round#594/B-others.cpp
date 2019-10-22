//#include<bits/stdc++.h>
#include<cstring>
#include<cstdio>
#include<string>
#define maxn 300005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long
 
using namespace std;
int N,sum[maxn]; char str[maxn<<1];
 
inline int read(){
	int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
 
int _main(){
    N=read(),scanf("%s",str+1);
	int pos=0,mn=inf;
    for(int i=1;i<=N;i++) str[i+N]=str[i];
    for(int i=1;i<=N;i++){
    	sum[i]=sum[i-1]+((str[i]==')')?-1:1);
    	if(sum[i]<mn) mn=sum[i],pos=i;
	}
	for(int i=pos+1;i<=pos+N;i++) 
		sum[i-pos]=sum[i-pos-1]+((str[i]==')')?-1:1);
	if(sum[N]!=0){printf("0\n1 1\n");return 0;}
	int ans=0,mxans=0,p1=1,p2=1;
	for(int i=1;i<=N;i++)
		if(sum[i]==0) ans++;
	for(int i=1;i<=N;){
		int j=i; while(j<=N && sum[j+1]!=0) j++; j++;
		int n1=0,n2=0,t1=0,t2=0,mxn2=0,las1=i;
		for(int k=i;k<=j;k++){
			if(sum[k]==1){
				if(mxn2<n2) mxn2=n2,t1=las1+1,t2=k;
				n2=0,n1++,las1=k;
			}
			if(sum[k]==2) n2++;
		}
		if(mxn2<n2) mxn2=n2,t1=las1+1,t2=j;
		if(mxans<mxn2+ans) mxans=mxn2+ans,p1=t1,p2=t2;
		if(mxans<n1) mxans=n1,p1=i,p2=j; i=j+1;
	}
	//cout<<p1<<" "<<p2<<endl;
	printf("%d\n%d %d\n",mxans,(p1+pos-1)%N+1,(p2+pos-1)%N+1);
	return 0;
}
int main(void)
{
    while(true)
    {
        _main();
    }
    return 0;
}