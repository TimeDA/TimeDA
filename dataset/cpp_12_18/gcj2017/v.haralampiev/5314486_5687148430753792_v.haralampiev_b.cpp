#ifdef _WIN32
 #  define LL "%I64d"
 #else
 #  define LL "%Ld"
 #endif
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <cstring>
 #include <ctime>
 #include <vector>
 #include <deque>
 #include <set>
 #include <map>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <string>
 #include <algorithm>
 #include <complex>
 #include <utility>
 using namespace std;
 #define null NULL
 #define mp make_pair
 #define pb(a) push_back(a)
 #define sz(a) ((int)(a).size())
 #define all(a) a.begin() , a.end()
 #define fi first
 #define se second
 #define relaxMin(a , b) (a) = min((a),(b))
 #define relaxMax(a , b) (a) = max((a),(b))
 #define SQR(a) ((a)*(a))
 typedef vector<int> vi;
 typedef pair<int,int> pii;
 typedef long long ll;
 #define SZ 10000
 #define INF 1000000000
 struct edge{
   int f,t,cap,fl,pr;
   edge(int _f=0,int _t=0,int _cap=0,int _pr=0){
    f=_f; t=_t; cap=_cap; pr=_pr;
    fl=0;
                                               }
   int rc(){return cap - fl;}
 };
 vector<edge> E;
 vi fo[SZ];
 int N , F , T;
 void add_edge(int f,int t,int cap,int pr){
   E.pb(edge(f,t,cap,pr)); E.pb(edge(t,f,0,-pr));
   fo[f].pb(sz(E)-2); fo[t].pb(sz(E)-1);
 }
 int sp[SZ] , par[SZ] , type[SZ];
 deque<int> M2;
 bool levit(){
   M2.clear();
   for(int i=0;i<N;++i)
    sp[i] = INF , par[i] = -1 , type[i] = 3;
   sp[F] = 0; type[F] = 2; M2.pb(F);
   while(!M2.empty()){
    int V = M2[0]; M2.pop_front();
    type[V] = 1;
    for(int i=0;i<sz(fo[V]);++i)
     if(E[fo[V][i]].rc()){
      edge e = E[fo[V][i]];
      if(sp[e.t] > sp[e.f] + e.pr){
       sp[e.t] = sp[e.f] + e.pr;
       par[e.t] = fo[V][i];
       if(type[e.t] == 3)M2.push_front(e.t);
       else if(type[e.t] == 1)M2.pb(e.t);
       type[e.t] = 1;
                                  }
                         }
                     }
   return sp[T]<INF;
 }
 int push_path(int vr , int MAX){
   if(vr == F)return MAX;
   MAX = push_path(E[par[vr]].f , min( MAX , E[par[vr]].rc() ));
   E[par[vr]].fl += MAX; E[par[vr]^1].fl -= MAX;
   return MAX;
 }
 void mfmc(){
   while(levit())push_path(T , INF);
 }
 
 // Solution
 int CASE = 0;
 
 int n, c, m;
 
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   vi a1, a2;
   scanf("%d%d%d", &n, &c, &m);
   for(int i = 0;i < m;++i){
     int p, b;
     scanf("%d%d", &p, &b);
     if(b == 1) a1.pb(p);
     else a2.pb(p);
   }
 
   N = sz(a1) + sz(a2) + 2;
   F = N - 2;
   T = N - 1;
 
   for(int i = 0;i < sz(a1);++i)
     add_edge(F, i, 1, 0);
 
   for(int i = 0;i < sz(a2);++i)
     add_edge(sz(a1) + i, T, 1, 0);
 
   for(int i = 0;i < sz(a1);++i)
     for(int j = 0;j < sz(a2);++j){
       if(a1[i] != a2[j]){
         add_edge(i, sz(a1) + j, 1, 0);
       } else {
         if(a1[i] != 1){
           add_edge(i, sz(a1) + j, 1, 1);
         }
       }
     }
 
   mfmc();
 
   int flow = 0, cost = 0;
   for(const auto& e : E){
     if(e.f == F && e.fl == 1) ++flow;
     if(e.fl == 1 && e.pr == 1) ++cost;
   }
 
   printf("Case #%d: ", CASE);
   printf("%d %d\n", m - flow , cost);
 
   E.clear();
   for(int i = 0;i < N;++i)
     fo[i].clear();
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
   /*
   N=4; F=0; T=3;
   add_edge(0,1,1,1); add_edge(0,2,1,1);
   add_edge(1,2,1,1);
   add_edge(1,3,1,100); add_edge(2,3,2,1);
   mfmc();
   for(int i=0;i<sz(E);++i)
    if(E[i].fl>0)cout<<E[i].f<<' '<<E[i].t<<":"<<E[i].fl<<endl;
   */
   return 0;
 }
