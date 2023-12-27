#include<bits/stdc++.h>
using namespace std;
namespace estidi{
	long long a[300003],b[300003];
	int main(){
		int n,m,t,l,r;
		long long x,ans;
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%lld",&b[i]);
		scanf("%d",&m);
		while(m--){
			scanf("%d%d%d",&t,&l,&r);
			if(t==1){
				scanf("%lld",&x);
				for(int i=l;i<=r;i++)
					a[i]=min(a[i],x);
			}
			if(t==2){
				scanf("%lld",&x);
				for(int i=l;i<=r;i++)
					b[i]=min(b[i],x);
			}
			if(t==3){
				scanf("%lld",&x);
				for(int i=l;i<=r;i++)
					a[i]+=x;
			}
			if(t==4){
				scanf("%lld",&x);
				for(int i=l;i<=r;i++)
					b[i]+=x;
			}
			if(t==5){
				ans=LLONG_MIN;
				for(int i=l;i<=r;i++)
					ans=max(ans,a[i]+b[i]);
				printf("%lld\n",ans);
			}
		}
		return 0;
	}
}
int main(){
	estidi::main();
	return 0;
}
