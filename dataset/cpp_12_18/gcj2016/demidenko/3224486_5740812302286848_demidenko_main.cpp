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
 
 
 struct dsu{
 	vector<int> p;
 	int n;
 	dsu(int sz){
 		n = sz;
 		p.resize(n);
 		for(int i=0;i<n;++i) p[i]=i;
 	}
 	int get(int i){
 		return i==p[i] ? i : (p[i] = get(p[i]));
 	}
 	bool un(int i, int j){
 		i=get(i);
 		j=get(j);
 		if(i!=j){
 			p[i] = j;
 		}
 		return i!=j;
 	}
 };
 
 int sqr(int x){
 	return x*x;
 }
 
 void solve(int test){
 	///+++start read ALL data+++
 	
 	int n, S;
 	cin>>n>>S;
 	vector<int> x(n);
 	vector<int> y(n);
 	vector<int> z(n);
 	vector<int> sx(n);
 	vector<int> sy(n);
 	vector<int> sz(n);
 	for(int i=0;i<n;++i){
 		cin>>x[i]>>y[i]>>z[i];
 		cin>>sx[i]>>sy[i]>>sz[i];
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
 	
 	vector<pair<int,pair<int,int>>> a;
 	for(int i=0;i<n;++i) for(int j=0;j<i;++j) a.push_back({sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]), {i,j}});
 	sort(ALL(a));
 	dsu q(n);
 	for(auto p : a){
 		int i = p.second.first;
 		int j = p.second.second;
 		if(q.un(i,j)){
 			if(q.get(0)==q.get(1)){
 				cout.precision(10);
 				cout<<fixed<<sqrt(p.first)<<endl;
 				return ;
 			}
 		}
 	}
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
