#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
   int n,a=0,b=0,c=0,d=0;
   cin>>n;
   char aa[260];
   getchar();
   cin.getline(aa,260);
   //puts(aa);
   if(n%4!=0) cout<<"==="<<endl;
   else{
   		for(int i=0;i<strlen(aa);i++){
   			if(aa[i]=='A') a++;
   			if(aa[i]=='G') b++;
   			if(aa[i]=='C') c++;
   			if(aa[i]=='T') d++;
   		}
   		//cout<<a<<" "<<b<<" "<<c<<" "<<d;
   		if(a>n/4||b>n/4||c>n/4||d>n/4) cout<<"==="<<endl;
   		else{
   			for(int i=0;i<n;i++){
   				if(aa[i]=='?'){
   					if(a<n/4) {
   						aa[i]='A';a++;
   					}
   					else if(b<n/4){
   						aa[i]='G';b++;
   					}
   					else if(c<n/4){
   						aa[i]='C';c++;
   					}
   					else if(d<n/4){
   						aa[i]='T';d++;
   					}
   				}
   			}
   			puts(aa);
   		}
   }
    return 0;
}
