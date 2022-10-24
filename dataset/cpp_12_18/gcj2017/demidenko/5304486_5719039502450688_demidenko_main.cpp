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
 /*
 const int N = 105;
 int u[N][N][N][N];
 */
 
 void solve(int test){
 	///+++start read ALL data+++
 	
 	int hd,ad,hk,ak,B,D;
 	cin>>hd>>ad>>hk>>ak>>B>>D;
 	
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
 	
 	vector<vector<int>> q;
 	map<vector<int>, int> u;
 	
 	vector<int> st = {hd, ad, hk, ak};
 	q.push_back(st);
 	u[st] = 0;
 	
 	for(int k=0;k<q.size();++k){
 		auto s = q[k];
 		int myhp = s[0], mydmg = s[1];
 		int hehp = s[2], hedmg = s[3];
 		int steps = u[s];
 		if(mydmg>=hehp){
 			cout<<steps+1<<endl;
 			return ;
 		}
 		
 		vector<vector<int>> to = {
 			{myhp, mydmg, hehp-mydmg, hedmg},
 			{myhp, min(hehp, mydmg+B), hehp, hedmg},
 			{hd, mydmg, hehp, hedmg},
 			{myhp, mydmg, hehp, max(0,hedmg-D)}
 		};
 		
 		for(auto t : to) if(t[0]>t[3]){
 			t[0]-=t[3];
 			if(!u.count(t)){
 				u[t] = steps+1; 
 				q.push_back(t);
 			}
 		}
 	}
 	
 	cout<<"IMPOSSIBLE"<<endl;
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
