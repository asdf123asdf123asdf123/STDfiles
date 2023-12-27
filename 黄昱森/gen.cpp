#include<bits/stdc++.h>
#include"data_gen.h"
using namespace std;
namespace estidi{
	long long a[300003],b[300003],cnt,ans[300003];
	int main(){
//		ios::sync_with_stdio(0);
//		cin.tie(0);
//		cout.tie(0);
		data_gen x("seg",0);
		for(int tc=1;tc<=10;tc++){
			x.next_testcase();
			x.open("in");
			cnt=0;
			int n,m,t,l,r;
			long long val;
			if(tc<=5){
				n=x.random_int(4000,5000);
				m=x.random_int(4000,5000);
			}
			else
				if(tc<=9){
					n=x.random_int(200000,300000);
					m=x.random_int(200000,300000);
				}
				else{
					n=300000;
					m=300000;
				}
			x.output(n);
			x.endl();
			x.random_int_array(a,1,n,1LL,10000000000LL);
			x.random_int_array(b,1,n,1LL,10000000000LL);
			x.output_array_between(a,1,n,' ');
			x.endl();
			x.output_array_between(b,1,n,' ');
			x.endl();
			x.output(m);
			x.endl();
			while(m--){
				if(m%10000==0)
					cerr<<m<<endl;
				t=x.random_int(1,5);
				l=x.random_int(1,n/2);
				r=x.random_int(l+n/2,n);
				x.output(t);
				x.space();
				x.output(l);
				x.space();
				x.output(r);
				if(t==1){
					val=x.random_int(100000LL,10000000000LL);
					x.space();
					x.output(val);
					x.endl();
					for(int i=l;i<=r;i++)
						a[i]=min(a[i],val);
				}
				if(t==2){
					val=x.random_int(100000LL,10000000000LL);
					x.space();
					x.output(val);
					x.endl();
					for(int i=l;i<=r;i++)
						b[i]=min(b[i],val);
				}
				if(t==3){
					val=x.random_int(-100000LL,100000LL);
					x.space();
					x.output(val);
					x.endl();
					for(int i=l;i<=r;i++)
						a[i]+=val;
				}
				if(t==4){
					val=x.random_int(-100000LL,100000LL);
					x.space();
					x.output(val);
					x.endl();
					for(int i=l;i<=r;i++)
						b[i]+=val;
				}
				if(t==5){
					x.endl();
					ans[++cnt]=LONG_LONG_MIN;
					for(int i=l;i<=r;i++)
						ans[cnt]=max(ans[cnt],a[i]+b[i]);
				}
			}
			x.open("out");
			x.output_array_between(ans,1,cnt,'\n');
			cerr<<tc<<" done"<<endl;
		}
		return 0;
	}
}
int main(){
	estidi::main();
	return 0;
}
