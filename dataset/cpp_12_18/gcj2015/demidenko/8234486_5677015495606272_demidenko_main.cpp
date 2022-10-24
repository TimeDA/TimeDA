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
 #include <unistd.h>
 #include <wait.h>
 using namespace std;
 typedef long long ll;
 const int __limitofthreads = 8;
 vector<pid_t> __ids;
 char __str[256];
 int __tests, __testsdone;
 void __inctests(){
     ++__testsdone;
     sprintf(__str, "\033[1;1Htests %d/%d done.%c",__testsdone,__tests,10);
     cerr<<__str;
 }
 
 const int N = 111;
 const int V = 3333;
 int mod = 1e9+7;
 int vn;
 
 pair<string,int> f[V];
 bool canf[V];
 
 
 int a[N], b[N];
 void gen(int i, int n){
     if(i==n){
         bool ok = true, ok2 = true;
         int ms2 = 0;
         string ms;
         for(i=0;i<n;++i){
             int x = a[i];
             ms+=char('0'+x);
             int s = 0;
             if(a[(i+n-1)%n]==x) ++s;
             if(a[(i+1)%n]==x) ++s;
             if(b[i]) ++s;
             if(s>x){
                 ok = false;
                 break;
             }
             if(s<x){
                 ok2 = false;
             }
             if(s+1<x){
                 ok = false;
                 break;
             }
             
             ms2|=b[i]<<i;
         }
         if(ok){
             f[vn] = {ms, ms2};
             canf[vn] = ok2;
             /*if(ok){
                 cout<<endl<<vn<<":"<<ok2<<endl;
                 cout<<ms<<endl; for(i=0;i<n;++i) cout<<(ms2>>i&1); cout<<endl;
             }*/
             ++vn;
         }
         
         return ;
     }
     for(int x=1;x<=3;++x)
     for(int y=0;y<=1;++y){
         a[i]=x;
         b[i]=y;
         gen(i+1, n);
     }
 }
 
 
 vector<int> g[V];
 
 vector<vector<int>> ans;
 
 bool same(vector<int> wi, vector<int> wj){
     vector<string> si;
     vector<string> sj;
     int n = wi.size();
     for(int k=0;k<n;++k){
         si.push_back(f[wi[k]].first);
         sj.push_back(f[wj[k]].first);
     }
     int m = si[0].size();
     for(int k=0;k<m;++k){
         if(si==sj) return true;
         for(int i=0;i<n;++i){
             rotate(si[i].begin(), si[i].begin()+1, si[i].end());
         }
     }
     return false;
 }
 
 int w[N];
 void dfs(int v, int n, int wn){
     w[wn] = v;
     if(n==1){
         if(f[v].second==0){
             bool ok = true;
             vector<int> q(w,w+wn+1);
             for(auto w2 : ans) if(same(w2, q)){
                 ok = false;
                 break;
             }
             if(ok) ans.push_back(q);
         }
         return ;
     }
     for(int u : g[v]){
         dfs(u, n-1, wn+1);
     }
 }
 
 void solve(int test){
     /*+++start read data+++*/
     
     int n,m;
     cin>>n>>m;
     
     /*---end read data---*/
     if(__ids.size()>=__limitofthreads) if(wait(0)!=-1) __inctests();
     pid_t __id = fork();
     if(__id>0){
         __ids.push_back(__id);
         return ;
     }else{
         sprintf(__str, "thread%d.out", test);
         freopen(__str,"w",stdout);
     }
     /*+++start solution and write output+++*/
     cout<<"Case #"<<test<<": ";
     
     gen(0,m);
     int en = 0;
     for(int i=0;i<vn;++i)
     for(int j=0;j<vn;++j){
         bool ok = true;
         for(int k=0;k<m;++k){
             int xi = f[i].first[k]-'0';
             int xj = f[j].first[k]-'0';
             ok&=((xi==xj)==(f[i].second>>k&1));
         }
         if(!ok) continue;
         for(int k=0;k<m;++k){
             int xi = f[i].first[k]-'0';
             int xj = f[j].first[k]-'0';
             int sj = 0;
             if(f[j].first[(k+m-1)%m]-'0'==xj) ++sj;
             if(f[j].first[(k+m+1)%m]-'0'==xj) ++sj;
             if(xi==xj) ++sj;
             if(f[j].second>>k&1) ++sj;
             if(sj!=xj) ok=false;
         }
         if(!ok) continue;
         g[i].push_back(j);
         //cout<<i<<"->"<<j<<endl;
         ++en;
     }
     
     //cout<<"ok"<<vn<<' '<<en<<endl;
     
     for(int v=0;v<vn;++v) if(canf[v]) dfs(v, n, 0);
     cout<<ans.size()<<endl;
     
     /*---end solution---*/
     exit(0);
 }
 
 int main(){
     freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
     
     cin>>__tests;
     for(int i=1;i<=__tests;++i){
         solve(i);
     }
     
     /*combining outputs*/
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
     
     return 0;
 }
