#include<cstdio>
#include<algorithm>
#include<queue>
#define asc(i,s,e) for((i)=(s);(i)<=(e);++(i))
#define rng(i,s,e) for((i)=(s);(i)<(e);++(i))
//#define eprintf(...)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

// ----

ll qpow2(int p) {
	ll r = 1;
	ll b = 2;
	while(p) {
		if(p&1) {
			r = (r * b) % MOD;
		}
		b = b * b % MOD;
		p >>= 1;
	}
	return r;
}

// ----


int solve();

int main() {
	int T;
	scanf("%d",&T);
	int t;
	asc(t,1,T) {
		int ans = solve();
		printf("Case#%d: %d\n",t, ans);
	}
}

int solve() {
	int n;
	scanf("%d",&n);

	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> boxes;
	int i;
	asc(i,1,n) {
		int ai,xi;
		scanf("%d %d",&ai,&xi);
		if(xi==0) {
			continue;
		}
		boxes.push(make_pair(ai,xi));
	}

	int total_ans = 0;

	int ans = 1;
	int alive_cnt = 0;
	int alive_cnt_qpow2=1;
	int carry_ai = -1;
	int carry_cnt2 = 0;

	int ai = boxes.top().first;
	int xi = boxes.top().second;
	boxes.pop();

	for(;;) {
		eprintf("ai = %d, xi = %d, alive_cnt = %d, ans = %d\n",ai,xi,alive_cnt,ans);
		
		ans += alive_cnt_qpow2;
		ans %= MOD;

		if(xi>2) {
			int g = (xi-1)/2;
			xi -= g*2;
			boxes.push(make_pair(ai+1,g));
		}

		if(xi==2) {
			if(carry_ai==-1) {
				carry_ai = ai;
				carry_cnt2 = 1;
			} else {
				carry_cnt2 += 1;
			}
		}

		alive_cnt += 1;
		alive_cnt_qpow2 = qpow2(alive_cnt);

		if(carry_ai != -1){
			if(boxes.empty() || boxes.top().first > ai + 1){
				alive_cnt -= (ai - carry_ai + 1);
				alive_cnt += carry_cnt2 - 1;
				alive_cnt_qpow2 = qpow2(alive_cnt);
				carry_ai = -1;
				boxes.push(make_pair(ai+1,1));
			}
		}

		if(boxes.empty()){
			total_ans += ll(total_ans) * ans % MOD;
			total_ans %= MOD;
			break; 
		}
		
		if(boxes.top().first>ai+1){
			ans = 1;
			alive_cnt = 0;
			alive_cnt_qpow2 = 1;
			carry_ai = -1;
			carry_cnt2 = 0;
		}
		
		ai = boxes.top().first;
		xi = 0;
		while(!boxes.empty() && boxes.top().first==ai){
			xi += boxes.top().second;
			boxes.pop();
		}
	}

	return ans;
}
