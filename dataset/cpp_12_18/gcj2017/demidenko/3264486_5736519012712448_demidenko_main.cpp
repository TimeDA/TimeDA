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
 
 
 
 
 void solve(int test){
 	///+++start read ALL data+++
 	
 	string s;
 	int k;
 	cin>>s>>k;
 	
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
 	
 	int ans = 0;
 	
 	for(int i=0;i+k<=s.size();++i) if(s[i]=='-'){
 		++ans;
 		for(int j=0;j<k;++j) s[i+j]^='+'^'-';
 	}
 	
 	if(count(ALL(s),'-')==0) cout<<ans<<endl;
 	else cout<<"IMPOSSIBLE"<<endl;
 	
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
