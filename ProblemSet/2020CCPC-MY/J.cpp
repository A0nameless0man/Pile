#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<vector>
#define asc(i,s,e) for((i)=(s);(i)<=(e);++(i))
#define rng(i,s,e) for((i)=(s);(i)<(e);++(i))
//#define eprintf(...)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;

void solve();
int main() {
	int T;
	scanf("%d",&T);
	int t;
	asc(t,1,T) {
		printf("Case #%d:",t);
		solve();
	}
}

int n,m;
int t[int(1e5+7)];
int x[int(1e5+7)];
int bucket[int(1e4)];
int ans[int(1e5+7)];
std::vector<int> insert[int(1e5+7)];
std::vector<int> pop[int(1e5+7)];
void solve() {
	scanf("%d %d",&n,&m);

	int i;
	asc(i,1,n)	{
		scanf("%d %d",&t[i],&x[i]);
	}

	int sqrtm = sqrt(m)+1;
	asc(i,1,sqrtm) {
		bucket[i]=0;
	}
	asc(i,1,m) {
		insert[i].clear();
		pop[i].clear();
		ans[i]=0;
	}
	asc(i,1,n) {
		if(2*t[i]<sqrtm) {
			bucket[t[i]]=max(bucket[t[i]],x[i]);
		} else {
			for(int j = 0;; j+=2) {
				if(t[i]*j+1<=m) {
					insert[t[i]*j+1].push_back(x[i]);
				} else {
					break;
				}
				if(t[i]*j+t[i]+1<=m) {
					pop[t[i]*j+t[i]+1].push_back(x[i]);
				} else {
					break;
				}
			}
		}
	}
	std::multiset<int> light;
	asc(i,1,m) {
		int j;
		for(auto b:insert[i]) {
			light.insert(b);
		}
		for(auto b:pop[i]) {
			light.erase(light.find(b));
//			light.delte(b);
		}

		asc(j,1,sqrtm) {
			if((i-1)/j%2==0) {
				ans[i]=max(ans[i],bucket[j]);
			}
		}
		if(!light.empty()) {
			ans[i]=max(ans[i],*light.rbegin());
		}
		printf(" %d",ans[i]);
	}
	printf("\n");
}
