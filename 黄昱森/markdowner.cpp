#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
	freopen("markdownedlink.md","w",stdout);
	string openoj="https://oj.bashu.com.cn/code/problempage.php?problem_id=",openlg="https://www.luogu.com.cn/problem/",openvj="https://vjudge.net/problem/";
	string s;
	while(getline(cin,s)){
		if(isdigit(s[0]))
			cout<<"["<<"°ÍÊñOJ"<<s<<"]("<<openoj<<s<<")\n\n";
		if(s.substr(0,2)=="Âå")
			cout<<"["<<s<<"]("<<openlg<<s.substr(4)<<")\n\n";
		if(s[0]=='C')
			cout<<"["<<"CodeForces"<<s.substr(2)<<"]("<<openlg<<s<<")\n\n";
		if(s[0]=='H')
			cout<<"["<<s<<"]("<<openvj<<"HDU-"<<s.substr(3)<<")\n\n";
		if(s[0]=='P')
			cout<<"["<<s<<"]("<<openvj<<"POJ-"<<s.substr(3)<<")\n\n";
	}
	return 0;
}
