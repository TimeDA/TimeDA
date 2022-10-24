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
 	
 	int n, m;
 	cin>>n>>m;
 	vector<int> r(n);
 	for(int &x : r) cin>>x;
 	vector<vector<int>> a(n, vector<int>(m));
 	for(auto&v:a) for(int&x:v) cin>>x;
 	
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
 	auto bl = a;
 	auto br = bl;
 	for(int i=0;i<n;++i){
 		for(int j=0;j<m;++j){
 			int x = a[i][j];
 			bl[i][j] = br[i][j] = -1;
 			for(int k=1;;++k){
 				ll c = r[i]*1LL*k;
 				// 0.9*c <= x <= 1.1*c
 				if(9LL*c>x*10LL) break;
 				if(x*10LL<=11LL*c){
 					if(bl[i][j]==-1) bl[i][j] = k;
 					br[i][j] = k;
 				}
 			}
 		}
 	}
 	
 	
 	
 	vector<vector<pair<int,int>>> c(n);
 	for(int i=0;i<n;++i){
 		for(int j=0;j<m;++j) if(bl[i][j]!=-1) c[i].push_back({bl[i][j],br[i][j]});
 		sort(ALL(c[i]));
 	}
 	/*
 	cout<<endl;
 	for(int i=0;i<n;++i){
 		for(auto p : c[i]) cout<<"["<<p.first<<","<<p.second<<"] ";
 		cout<<endl;
 	}*/
 	
 	vector<int> pos(n);
 	
 	int ans = 0, inf = 1e9;
 	
 	for(int k=1;k<2e6;){
 		bool fin = false;
 		for(int j=0;j<n;++j){
 			while(pos[j]<c[j].size() && c[j][pos[j]].second<k) ++pos[j];
 			if(pos[j]==c[j].size()) fin = true;
 		}
 		if(fin) break;
 		bool ok = true;
 		for(int i=0;i<n;++i) if(c[i][pos[i]].first>k){
 			ok = false;
 			break;
 		}
 		if(ok){
 			++ans;
 			for(int i=0;i<n;++i) pos[i]++;
 		}else ++k;
 	}
 	
 	cout<<ans<<endl;
 	
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
