#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll qmin,qmax;
////unorder_map<pair<int,int>,pair<int,int> >mp;
//void dfs(ll x) {
//	if(x%2==1) { //even
//		qmin=min(qmin,x/2);
//		qmax=max(qmax,x/2+1);
//		return;
//	}
//	if((x/2)%2==1) {
//		qmin=min(qmin,x/2);
//		qmax=max(qmax,x/2 );
//		dfs(x/2);
//	} else {
//		dfs(x/2-1);
//		dfs(x/2+1);
//	}
//}

int a[20]= {0,0,0,0,0,1,-1,1,2,1,3};

int main(void) {
	int T;
	ll x;
	int ans;
	scanf("%d",&T);
	for(int z=1; z<=T; z++) {
//		qmin=0x7fffffffffff,qmax=-1;
		ans=0x7fff;
		scanf("%lld",&x);
		if(x&1) {
			ans=1;
		} else if(x<10) {
			ans=a[x];
		} else {
			if(x%4==0) {
				ans=min(ans,2);
			}
			if(x%3==0) {
				ans=min(ans,2);
			}
			if(x%3==1) {
				if((x-4)/3%3==0) {
					ans=min(ans,4);
				} else {
					ans=min(ans,3);
				}
			}
			if(x%3==2) {
				if((x-5)/3%3==0) {
					ans=min(ans,4);
				} else {
					ans=min(ans,3);
				}
			}
		}

		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}
