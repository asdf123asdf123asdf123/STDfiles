#include<bits/stdc++.h>
using namespace std;
#include<cstdio>
#ifndef _GLIBCXX_IOMANIP
namespace std{
  struct _Setprecision { int _M_n; };
  inline _Setprecision
  setprecision(int __n)
  { return { __n }; }
}
#endif//_Setprecision
namespace fast_IO {
#define FASTIO
#define IOSIZE 100000
	long long preci=6;
	char ibuf[IOSIZE], obuf[IOSIZE];
	char *p1 = ibuf, *p2 = ibuf, *p3 = obuf;
#ifdef ONLINE_JUDGE
#define getchar() ((p1==p2)and(p2=(p1=ibuf)+fread(ibuf,1,IOSIZE,stdin),p1==p2)?(EOF):(*p1++))
#define putchar(x) ((p3==obuf+IOSIZE)&&(fwrite(obuf,p3-obuf,1,stdout),p3=obuf),*p3++=x)
#endif//fread in OJ, stdio in local
#define isdigit(ch) (ch>47&&ch<58)
#define isspace(ch) (ch<33&&ch!=EOF)
	template<typename T> inline T read() {
		T s = 0;
		int w = 1;
		char ch;
		while (ch = getchar(), !isdigit(ch) and (ch != EOF)) if (ch == '-') w = -1;
		if (ch == EOF) return false;
		while (isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
		return s * w;
	}
	template<typename T> inline bool read(T &s) {
		s = 0;
		int w = 1;
		char ch;
		while (ch = getchar(), !isdigit(ch) and (ch != EOF)) if (ch == '-') w = -1;
		if (ch == EOF) return false;
		while (isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
		return s *= w, true;
	}
	inline bool read(char &s) {
		while (s = getchar(), isspace(s));
		return s!=EOF;
	}
	inline bool read(char *s) {
		char ch;
		while (ch = getchar(), isspace(ch));
		if (ch == EOF) return false;
		while (!isspace(ch)) *s++ = ch, ch = getchar();
		*s = '\000';
		return true;
	}
	inline bool read(bool &b){
		char ch;
		while(ch=getchar(),isspace(ch));
		if(ch==EOF)
			return false;
		b=ch^48;
		return true;
	}
	inline bool read(double &x){
		long long a = 0, b = 0, w = 0;
		char ch ;
		bool f = 0;
		while (ch = getchar(), !isdigit(ch) and (ch != EOF)) if (ch == '-') f = 1;
		if(ch==EOF)
			return false;
		while(isdigit(ch)){
			a =a*10 + ch-48;
			ch = getchar();
		}
		if(ch != '.'){
			x = (f ?-a :a);
			return 1;
		}
		ch = getchar();
		while(48<=ch && ch<=57){
			b = b*10 + ch-48;
			ch = getchar();
			w++;
		}
		x = b;
		while(w--)
			x /= 10;
		x = (f ?-a-x :a+x);
		return 1;
	}
	template<typename T> inline void print(T x) {
		if (x < 0) putchar('-'), x = -x;
		if (x > 9) print(x / 10);
		putchar(x % 10 + 48);
	}
	inline void print(char x) {
		putchar(x);
	}
	inline void print(char *x) {
		while (*x) putchar(*x++);
	}
	inline void print(const char *x) {
		for (int i = 0; x[i]; i++) putchar(x[i]);
	}
	inline void print(bool b){
		putchar(b+48);
	}
	inline void print(double x){
		long long xx,y=0,z,len=0;
		if(x<0) putchar('-'),x=-x;
		xx=x;
		x-=xx;
		for(int i=1; i<=preci; i++){
			x*=10;
			x+=1e-10;
			y=y*10+x;
			x-=(int)x;
		}
		x*=10;
		x+=1e-10;
		if(x>=5-1e-10){
			y++;
		}
		z=y;
		if(z==0)
			len=1;
		while(z){
			z/=10;
			len++;
		}
		if(preci<len){
			xx++;
			y=0;
			len=1;
		}
		print(xx);
		putchar('.');
		for(int i=1;i<=preci-len;i++)
			putchar('0');
		print(y);
	}
#ifdef _GLIBCXX_STRING
	inline bool read(std::string& s) {
		s = "";
		char ch;
		while (ch = getchar(), isspace(ch));
		if (ch == EOF) return false;
		while (!isspace(ch)) s += ch, ch = getchar();
		return true;
	}
	inline void print(std::string x) {
		for (int i = 0, n = x.size(); i < n; i++)
			putchar(x[i]);
	}
#endif//string
#ifdef _GLIBCXX_BITSET 
	template<size_t T> inline bool read(std::bitset<T>& x) {
		std::string s = "";
		char ch;
		while (ch = getchar(), isspace(ch));
		if (ch == EOF) return false;
		while (ch=='1'||ch=='0') s += ch, ch = getchar();
		x=std::bitset<T>(s);
		return true;
	}
	template<size_t T> inline void print(std::bitset<T> x) {
		print(x.to_string());
	}
#endif//bitset
	inline bool read(std::_Setprecision x) {
		preci=x._M_n;
		return true;
	}
	inline void print(std::_Setprecision x) {
		preci=x._M_n;
	}
#define FIO_EOF 0
#define FIO_OK 1
	template<typename T, typename... T1> inline bool read(T& a, T1&... other) {
		return read(a) && read(other...);
	}
	template<typename T, typename... T1> inline void print(T a, T1... other) {
		print(a);
		print(other...);
	}
	struct Fast_IO {
		Fast_IO() {
			eof=0;
		}
		~Fast_IO() {
			fwrite(obuf, p3 - obuf, 1, stdout);
		}
		bool eof;
		int precision(long long x=-1){
			if(x!=-1){
				long long old=preci;
				preci=x;
				return old;
			}
			return preci;
		}
		void merge_Fast_IO(bool eofed) {
			eof|=eofed;
		}
		operator bool(){
			return eof;
		}
	}io;
	template<typename T> Fast_IO& operator >> (Fast_IO &io, T &b) {
		return io.merge_Fast_IO(read(b)),io;
	}
	template<typename T> Fast_IO& operator << (Fast_IO &io, T b) {
		return print(b),io;
	}
#define cout io
#define cin io
#define endl '\n'
}
using namespace fast_IO;
#define int long long
namespace segment_tree{
	struct seg_t{
		struct node{
			int l,r,sum,ma,cnt,mma,laz,tag;
		}a[1200003];
		void pushup(int x){
			a[x].sum=a[x*2].sum+a[x*2+1].sum;
			if(a[x*2].ma==a[x*2+1].ma){
				a[x].ma=a[x*2].ma;
				a[x].cnt=a[x*2].cnt+a[x*2+1].cnt;
				a[x].mma=max(a[x*2].mma,a[x*2+1].mma);
			}
			if(a[x*2].ma>a[x*2+1].ma){
				a[x].ma=a[x*2].ma;
				a[x].cnt=a[x*2].cnt;
				a[x].mma=max(a[x*2].mma,a[x*2+1].ma);
			}
			if(a[x*2].ma<a[x*2+1].ma){
				a[x].ma=a[x*2+1].ma;
				a[x].cnt=a[x*2+1].cnt;
				a[x].mma=max(a[x*2].ma,a[x*2+1].mma);
			}
		}
		void pushdown(int x){
			if(a[x].tag){
				a[x*2].sum+=(a[x*2].r-a[x*2].l+1)*a[x].tag;
				a[x*2].ma+=a[x].tag;
				if(a[x*2].mma!=LONG_LONG_MIN)
					a[x*2].mma+=a[x].tag;
				if(a[x*2].laz!=999999)
					a[x*2].laz+=a[x].tag;
				a[x*2+1].sum+=(a[x*2+1].r-a[x*2+1].l+1)*a[x].tag;
				a[x*2+1].ma+=a[x].tag;
				if(a[x*2+1].mma!=LONG_LONG_MIN)
					a[x*2+1].mma+=a[x].tag;
				if(a[x*2+1].laz!=999999)
					a[x*2+1].laz+=a[x].tag;
				a[x].tag=0;
			}
			if(a[x].laz!=999999){
				if(a[x*2].ma>a[x].laz){
					a[x*2].sum=a[x*2].sum-(long long)a[x*2].cnt*a[x*2].ma+(long long)a[x*2].cnt*a[x].laz;
					a[x*2].ma=a[x].laz;
					a[x*2].laz=a[x].laz;
				}
				if(a[x*2+1].ma>a[x].laz){
					a[x*2+1].sum=a[x*2+1].sum-(long long)a[x*2+1].cnt*a[x*2+1].ma+(long long)a[x*2+1].cnt*a[x].laz;
					a[x*2+1].ma=a[x].laz;
					a[x*2+1].laz=a[x].laz;
				}
				a[x].laz=999999;
			}
		}
		void build(int b[],int l,int r,int x){
			a[x].l=l;
			a[x].r=r;
			a[x].laz=999999;
			if(l<r){
				int mid=(l+r)>>1;
				build(b,l,mid,x*2);
				build(b,mid+1,r,x*2+1);
				pushup(x);
			}
			else{
				a[x].sum=b[l];
				a[x].ma=b[l];
				a[x].cnt=1;
				a[x].mma=LONG_LONG_MIN;
			}
		}
		void adds(int l,int r,int k,int x){
			if(a[x].l>r||a[x].r<l)
				return;
			if(a[x].l>=l&&a[x].r<=r){
				a[x].sum+=(a[x].r-a[x].l+1)*k;
				a[x].ma+=k;
				if(a[x].mma!=LONG_LONG_MIN)
					a[x].mma+=k;
				if(a[x].laz!=999999)
					a[x].laz+=k;
				a[x].tag+=k;
				return;
			}
			pushdown(x);
			adds(l,r,k,x*2);
			adds(l,r,k,x*2+1);
			pushup(x);
		}
		void addm(int l,int r,int k,int x){
			if(a[x].l>r||a[x].r<l||a[x].ma<=k)
				return;
			if(a[x].l>=l&&a[x].r<=r&&a[x].mma<k){
				a[x].sum=a[x].sum-(long long)a[x].cnt*a[x].ma+(long long)a[x].cnt*k;
				a[x].ma=k;
				a[x].laz=k;
				return;
			}
			pushdown(x);
			addm(l,r,k,x*2);
			addm(l,r,k,x*2+1);
			pushup(x);
		}
		int asks(int l,int r,int x){
			if(a[x].l>r||a[x].r<l)
				return 0;
			if(a[x].l>=l&&a[x].r<=r)
				return a[x].sum;
			pushdown(x);
			int ans=asks(l,r,x*2)+asks(l,r,x*2+1);
			pushup(x);
			return ans;
		}
		int askm(int l,int r,int x){
			if(a[x].l>r||a[x].r<l)
				return -1;
			if(a[x].l>=l&&a[x].r<=r)
				return a[x].ma;
			pushdown(x);
			int ans=max(askm(l,r,x*2),askm(l,r,x*2+1));
			pushup(x);
			return ans;
		}
	};
}
using namespace segment_tree;
namespace estidi{
	seg_t a,b;
	int aa[300003],bb[300003];
	int main(){
		int n,m,t,l,r,x;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>aa[i];
		for(int i=1;i<=n;i++)
			cin>>bb[i];
		a.build(aa,1,n,1);
		b.build(bb,1,n,1);
		while(m--){
			cin>>t>>l>>r;
			if(t==1){
				cin>>x;
				a.addm(l,r,x,1);
			}
			if(t==2){
				cin>>x;
				b.addm(l,r,x,1);
			}
			if(t==3){
				cin>>x;
				a.adds(l,r,x,1);
			}
			if(t==4){
				cin>>x;
				b.adds(l,r,x,1);
			}
			if(t==5){
			}
		}
		return 0;
	}
}
signed main(){
	estidi::main();
	return 0;
}
