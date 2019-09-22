u#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[200010],allwin,setwin,now,all,ans,ans2;
const int inf = 1e7;
int main()
{
    int n,k,k2;
    cin>>n>>k;
    k2=k;
    int i;
	for(i=0;i<n;i++)
	{
		int aa;
		scanf("%d",&aa);
		if(aa<0){
			allwin++;
			//all++;
			setwin++;
			break;
		}
	}
	now=-1;
	for(i++;i<n;i++){
		int aa;
		scanf("%d",&aa);
		if(aa>=0){
			if(now==1)  a[all]++;//1=1
			else {
				all++;//-1=1
				//cout<<"all"<<all<<endl;
				a[all]++;
				now=1;
			}
		}
		else{
			if(now==-1){//-1=-1
				allwin++;
			}
			else{//1=-1
				now=-1;
				allwin++;
				setwin++;
			}
		}
	}
	//cout<<allwin<<" "<<all<<" "<<setwin<<endl;
	//input end
//cout<<a[setwin]<<endl;
	k-=allwin+a[setwin];//lefday
	if(k<0)ans=inf;
	ans+=2*setwin-1;//
	sort(a+1,a+all);
	i=1;
	while(k>=a[i]&&i!=setwin){
		//cout<<"K:"<<k<<"A[i]:"<<a[i]<<endl;
		k-=a[i];
		i++;
		ans-=2;
	}
	k2-=allwin;
	if(k2<0)ans2=inf;
	ans2+=2*setwin;
	i=1;
	while(k2>=a[i]&&i!=setwin){
	//cout<<"K2:"<<k2<<"A[i]:"<<a[i]<<endl;
		k-=a[i];
		i++;
		ans2-=2;
	}
	//cout<<ans<<" "<<ans2<<endl;
	ans=min(ans,ans2);
	if(ans==inf)ans=-1;
	cout<<ans<<endl;
	return 0;

}
