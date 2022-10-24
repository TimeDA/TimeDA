#include<bits/stdc++.h>
 #define ALL(c) (c).begin(), (c).end()
 using namespace std;
 using ll = long long;
 using ld = long double;
 
 
 #include <unistd.h>
 #include <wait.h>
 bool __multithreading = true;
 const int __limitofthreads = 4;
 vector<pid_t> __ids;
 char __str[128];
 int __tests, __testsdone, __id;
 void __inctests(){
 	++__testsdone;
 	sprintf(__str, "\033[1;1Htests %d/%d done.%c",__testsdone,__tests,10);
 	cerr<<__str;
 }
 ifstream __in("input.txt");
 #define cin __in
 
 
 
 void solve(int test){
 	///+++start read ALL data+++
 	
 	int n,m;
 	cin>>n>>m;
 	vector<string> s(n);
 	for(string &t : s) cin>>t;
 	
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
 	
 	for(int i=0;i<n;++i){
 		char p = '?';
 		for(int j=0;j<m;++j) if(s[i][j]=='?'){
 			s[i][j] = p;
 		}else p = s[i][j];
 		for(int j=m-2;j>=0;--j) if(s[i][j]=='?') s[i][j] = s[i][j+1];
 	}
 	
 	for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(s[i][j]=='?'){
 		int k = 0;
 		for(k=i-1;k>=0;--k) if(s[k][j]!='?'){s[i][j]=s[k][j]; break;}
 		if(s[i][j]=='?') 
 		for(k=i+1;k<n;++k) if(s[k][j]!='?'){s[i][j]=s[k][j]; break;}
 	}
 	
 	cout<<endl;
 	for(string t : s) cout<<t<<endl;
 }
 
 int main(){
 	freopen("output.txt","w",stdout);
 	
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
