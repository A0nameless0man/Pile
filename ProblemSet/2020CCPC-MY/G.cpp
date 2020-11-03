#include<cstdio>
#include<algorithm>

using LL = long long;

const char H[] = "Horse";
const char R[] = "Rabbit";

int c[4];

bool judge(void) {
	bool win0;
	bool win1 = ((c[1]%3)==2||((c[1]%3)==1&&(c[2]!=0)));
	if(c[1]!=0||c[2]!=0||c[3]!=0) {
		win0=(c[0]%2==1);
	} else {
		if(c[0]==0) {
			win0= false;
		} else {
			win0=((c[0]%2)==0);
		}
	}
	return win0!=win1;
}

int main(void) {
	int T;
	while(scanf("%d",&T)!=EOF) {
		for(int cc = 1; cc<=T; ++cc) {
			for(int i = 0; i<4; ++i) {
				scanf("%d",&c[i]);
			}
			printf("Case #%d: %s\n",cc,judge()?R:H);
		}
	}
	return 0;
}
/*
Case #1: Horse
Case #2: Rabbit
*/
