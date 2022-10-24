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
 
 ///+mincostmaxflow
 const int V = 1111;
 const int E = 500*500 + 1000*2 + 123;
 int e[E*2], eb[V], es[E*2], ec[E*2], ef[E*2], ex[E*2], ed;
 int S,T,nv;
 
 void init(){
     ed = 1;
 }
 
 void adde(int i,int j, int cap, int cost){
     e[++ed] = j;
     ec[ed] = cap;
     ef[ed] = 0;
     ex[ed] = cost;
     es[ed]=eb[i];
     eb[i]=ed;
     
     e[++ed] = i;
     ec[ed] = 0;
     ef[ed] = 0;
     ex[ed] = -cost;
     es[ed]=eb[j];
     eb[j]=ed;
 }
 
 int d[V], f[V], p[V];
 bool u[V];
 
 pair<int,int> mcmf(int S, int T, int n){
     int inf = 1e9;
     int flow = 0;
     int cost = 0;
     
     for(int i=0;i<n;++i) p[i]=0;
     for(;;){
         for(int i=0;i<n;++i){
             d[i]=inf;
             u[i]=0;
             f[i]=-1;
         }
         d[S]=0;
         for(;;){
             int i=-1;
             for(int j=0;j<n;++j) if(!u[j] && (i==-1 || d[i]>d[j])) i=j;
             if(i==-1 || d[i]>=inf) break;
             u[i]=1;
             for(int k=eb[i];k;k=es[k]) if(ec[k]>ef[k]){
                 int j = e[k];
                 int val = d[i]+ex[k]+p[i]-p[j];
                 if(val<d[j]){
                     d[j]=val;
                     f[j]=k;
                 }
             }
         }
         if(!u[T]) return make_pair(flow, cost);
         int add=inf;
         for(int v=T;v!=S; v=e[f[v]^1]) add=min(add, ec[f[v]]-ef[f[v]]);
         flow+=add;
         for(int v=T;v!=S; v=e[f[v]^1]){
             cost+=add*ex[f[v]];
             ef[f[v]]+=add;
             ef[f[v]^1]-=add;
         }
         for(int i=0;i<n;++i) p[i]+=d[i];
     }
 }
 ///-mincostmaxflow
 
 
 void solve(int test){
 	///+++start read ALL data+++
 	
 	int n, C, m;
 	cin>>n>>C>>m;
 	vector<pair<int,int>> a(m);
 	for(int i=0;i<m;++i){
 		cin>>a[i].first;
 		cin>>a[i].second;
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
 	
 	init();
 	
 	vector<int> vl;
 	vector<int> vr;
 	
 	for(auto p : a) (p.second==1 ? vl : vr).push_back(p.first);
 	
 	nv = m+2;
 	S = 0;
 	T = nv-1;
 	
 	for(int i=0;i<vl.size();++i) adde(S, i+1, 1, 0);
 	for(int i=0;i<vr.size();++i) adde(i+1+vl.size(), T, 1, 0);
 	for(int i=0;i<vl.size();++i)
 	for(int j=0;j<vr.size();++j){
 		if(vl[i]==vr[j]){
 			if(vl[i]!=1) adde(i+1, j+1+vl.size(), 1, 1);
 		}else{
 			adde(i+1, j+1+vl.size(), 1, 0);
 		}
 	}
 	
 	auto res = mcmf(S, T, nv);
 	
 	cout<<m-res.first<<' '<<res.second<<endl;
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
