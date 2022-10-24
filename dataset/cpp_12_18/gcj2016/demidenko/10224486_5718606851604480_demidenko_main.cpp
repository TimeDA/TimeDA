#include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<algorithm>
 #include<string>
 #include<cstring>
 #include<cmath>
 #include<set>
 #include<map>
 #include<assert.h>
 using namespace std;
 typedef long long ll;
 typedef long double ld;
 
 #include <unistd.h>
 #include <wait.h>
 bool __multithreading = true;
 const int __limitofthreads = 8;
 vector<pid_t> __ids;
 char __str[128];
 int __tests, __testsdone, __id;
 void __inctests(){
 	++__testsdone;
 	sprintf(__str, "\033[1;1Htests %d/%d done.%c",__testsdone,__tests,10);
 	cerr<<__str;
 }
 
 string no = "IMPOSSIBLE";
 
 string f(int n, int r, int p, int s){
 	assert(n==p+r+s);
 	if(n==1){
 		if(r) return "R";
 		if(p) return "P";
 		if(s) return "S";
 		return no;
 	}
 	if(max(r,max(p,s))*2>n) return no;
 	
 	int b2 = s-r+p;
 	if(b2&1) return no;
 	int b = b2/2;
 	if(b<0) return no;
 	int a = s-b, c = p-b;
 	if(a<0 || c<0) return no;
 	string t = f(n/2, a,c,b);
 	if(t==no) return no;
 	string res;
 	for(char x : t){
 		if(x=='R') res+="RS"; else
 		if(x=='P') res+="PR"; else
 		if(x=='S') res+="PS";
 	}
 	return res;
 }
 
 string gg(string s){
 	int n = s.size();
 	if(n==1) return s;
 	n/=2;
 	string a = gg(s.substr(0, n));
 	string b = gg(s.substr(n, n));
 	return min(a+b, b+a);
 }
 
 
 void solve(int test){
 	///+++start read ALL data+++
 	
 	int h, r, p, s;
 	cin>>h>>r>>p>>s;
 	int n = 1<<h;
 	
 	///---end read data---
 	if(__multithreading){
 		if(__ids.size()>=__limitofthreads && wait(0)!=-1) __inctests();
 		__id = fork();
 		if(__id>0){
 			__ids.push_back(__id);
 			return ;
 		}
 		sprintf(__str, "thread%d.out", test);
 		freopen(__str, "w", stdout);
 	}
 	///start solution and write output
 	cout<<"Case #"<<test<<": ";
 	
 	string res = f(n,r,p,s);
 	if(res!=no) res = gg(res);
 	
 	cout<<res<<endl;
 	
 }
 
 int main(){
 	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 	
 	cin>>__tests;
 	for(int i=1;i<=__tests;++i){
 		solve(i);
 		if(__multithreading&&__id==0) return 0;
 	}
 	
 	///combining outputs
 	if(__multithreading){
 		for(pid_t __id : __ids) if(waitpid(__id,0,0)!=-1) __inctests();
 		int __bufsize = 1<<16;
 		char *__buf = new char[__bufsize];
 		for(int i=1;i<=__tests;++i){
 			sprintf(__str, "thread%d.out", i);
 			FILE *f = fopen(__str, "r");
 			while(fgets(__buf, __bufsize, f)) printf("%s",__buf);
 			fclose(f);
 			remove(__str);
 		}
 		delete [] __buf;
 	}
 	
 	return 0;
 }
