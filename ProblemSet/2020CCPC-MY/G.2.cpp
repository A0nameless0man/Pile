#include<cstdio>

const int range = 12;
const int ob= -1;
const int unknow = 0;
const int win = 1;
const int lost = 2;
int sg[range][range][range][range];

int move[][4]= {
	{-1,0,0,0},
	{0,-2,+1,0},
	{0,-1,-1,+1}
}

int c[4];
int judeg(void){
	bool win0;
	bool win1 = (c[1]%3)==2||((c[1]%3)==1&&(c[2]!=0));
	
	while(true)
	{
		if(c[2]){
			c[1]%=3;
		}
		
	}
	if(c[1]!=0||c[2]!=0||c[3]!=0) {
		win0=c[0]%2==1;
	} else {
		if(c[0]==0) {
			win0= false;
		} else {
			win0=c[0]%2==0;
		}
	}
	return win0!=win1;
}

int getSg(int a,int b,int c,int d) {
	if(a<0||b<0||c<0||d<0) {
		return ob;
	} else {
		if(sg[a][b][c][d]!=unknow) {
			return sg[a][b][c][d];
		} else {
			int win = false;
			if(b>0||c>0||d>0) {
				if(
				getSg())
			}
		}
	}
}
