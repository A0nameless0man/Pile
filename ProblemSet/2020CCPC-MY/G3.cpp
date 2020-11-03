#include<bits/stdc++.h>
using namespace std;

int c[4];

int judge(void) {
	int win0;
	int win1;
	if(c[1]||c[2]||c[3]) {
		win0=(c[0]%2);
	} else {
		if(c[0]==0) {
			win0=0;
		} else {
			win0=!(c[0]%2);
		}
	}
	win1=!((c[1]%3==0)||((c[1]%3==1)&&c[2]));
	return win1!=win0;
}

int main(void) {
	int T;
	scanf("%d",&T);
	for(int z=1; z<=T; z++) {
		for(int i=0; i<4; i++) {
			scanf("%d",&c[i]);
		}
		printf("Case #%d: %s\n",z,judge()?"Rabbit":"Horse");
	}
	return 0;
}
