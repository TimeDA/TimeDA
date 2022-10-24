#include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>
 #include<cmath>
 #include<algorithm>
 #include<vector>
 #include<string>
 #include<set>
 #include<map>
 #include<cassert>
 #define ALL(c) (c).begin(), (c).end()
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
 
 
 bool gg(vector<string> &g, vector<int>&p, int i, vector<int> &u){
 	if(i==p.size()){
 		for(int x : u) if(!x) return false;
 		return true;
 	}
 	int x = p[i];
 	bool ans = true, f = false;
 	for(int j=0;j<g.size();++j) if(g[x][j]=='1' && !u[j]){
 		f = true;
 		u[j] = 1;
 		ans&=gg(g,p,i+1,u);
 		u[j] = 0;
 	}
 	return ans&&f;
 }
 
 void solve(int test){
 	///+++start read ALL data+++
 	
 	int n;
 	cin>>n;
 	vector<string> g(n);
 	int ms =0, p2 = 1;
 	for(auto&it : g){
 		cin>>it;
 		for(int i=0;i<n;++i){
 			ms+=p2*(it[i]-'0');
 			p2*=2;
 		}
 	}
 	
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
 	
 	int ans = 1e9;
 	for(int m = 0; m<(1<<(n*n)); ++m) if((m&ms)==ms){
 		auto e = g;
 		for(int h=0;h<n*n;++h) if(m>>h&1){
 			int i = h/n, j = h%n;
 			e[i][j] = '1';
 		}
 		
 		vector<int> p(n), u(n);
 		for(int i=0;i<n;++i) p[i]=i;
 		bool ok = true;
 		do{
 			ok&=gg(e, p, 0, u);
 		}while(next_permutation(ALL(p)));
 		if(ok){
 			ans = min(ans, (int)__builtin_popcount(m^ms));
 		}
 	}
 	cout<<ans<<endl;
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
