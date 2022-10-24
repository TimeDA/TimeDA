#include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<algorithm>
 #include<vector>
 #include<string>
 #include<set>
 #include<map>
 #include<cmath>
 #include<memory.h>
 #include<assert.h>
 #include <unistd.h>
 #include <wait.h>
 using namespace std;
 typedef long long ll;
 typedef long double ld;
 
 bool __multithreading = true;
 const int __limitofthreads = 8;
 vector<pid_t> __ids;
 char __str[128];
 int __tests, __testsdone;
 void __inctests(){
 	++__testsdone;
 	sprintf(__str, "\033[1;1Htests %d/%d done.%c",__testsdone,__tests,10);
 	cerr<<__str;
 }
 
 int f(int x){
 	int ms = 0, ans = 0;
 	for(int i=x;;i+=x){
 		for(int j=i;j;j/=10) ms|=1<<(j%10);
 		if(ms==1023) return i;
 	}
 }
 
 
 void solve(int test){
 	///+++start read ALL data+++
 	
 	int n;
 	cin>>n;
 	
 	///---end read data---
 	if(__multithreading){
 		if(__ids.size()>=__limitofthreads) if(wait(0)!=-1) __inctests();
 		pid_t __id = fork();
 		if(__id>0){
 			__ids.push_back(__id);
 			return ;
 		}else{
 			sprintf(__str, "thread%d.out", test);
 			freopen(__str,"w",stdout);
 		}
 	}
 	///+++start solution and write output+++
 	cout<<"Case #"<<test<<": ";
 	
 	if(n==0) cout<<"INSOMNIA"<<endl;
 	else cout<<f(n)<<endl;
 	
 	///---end solution---
 	if(__multithreading) exit(0);
 }
 
 int main(){
 	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 	
 	cin>>__tests;
 	for(int i=1;i<=__tests;++i){
 		solve(i);
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
