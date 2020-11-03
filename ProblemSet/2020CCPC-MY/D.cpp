#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
typedef long long ll;

bool check(std::vector<int>& bombs,ll time) {
	ll left = time;
	for(auto b:bombs) {
		if(b<time) {
			left -= (time-b);
			if(left<0) {
				return false;
			}
		}
	}
	return true;
}

int main(void) {
	int T;
	while(scanf("%d",&T)!=EOF) {
		for(int c = 1; c<=T; ++c) {
			int n;
			std::vector<int> bombs;
			scanf("%d",&n);
			for(int i = 0; i<n; ++i) {
				int tmp;
				scanf("%d",&tmp);
				bombs.push_back(tmp);
			}
			ll r = 1e15+7;
			ll l = 1;
			while(l<r) {
				ll mid = (l+r)/2;
				if(check(bombs,mid)) {
					l = mid+1;
				} else {
					r = mid;
				}
			}
			printf("Case #%d: %lld\n",c,l);
		}
	}
}
