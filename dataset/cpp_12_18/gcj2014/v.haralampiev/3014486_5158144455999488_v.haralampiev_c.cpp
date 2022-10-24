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
 #define SZ 110000
 struct edge{
   int f,t,cap,fl;
   edge(int _f=0,int _t=0,int _cap=0){f=_f , t=_t , cap=_cap , fl=0;}
   int rc(){return cap-fl;}
 };
 int N,F,T;
 vector<edge> E;
 vi fo[SZ];
 void flush(){
   E.clear();
   for(int i=0;i<N;++i)
    fo[i].clear();
 }
 void add_edge(int f,int t,int cap){
   E.pb(edge(f,t,cap)); E.pb(edge(t,f,0));
   fo[f].pb(sz(E)-2); fo[t].pb(sz(E)-1);
 }
 int Q[SZ] , QL , QR , lev[SZ];
 bool bfs(){
   memset(lev , -1 , N*sizeof(int));
   QL=QR=0;
   Q[QR++]=F; lev[F]=0;
   while(QL<QR){
    int C = Q[QL++];
    for(int i=sz(fo[C])-1;i>=0;--i){
     edge U = E[ fo[C][i] ];
     if(lev[U.t]==-1 && U.cap>U.fl)lev[U.t]=lev[U.f]+1 , Q[QR++]=U.t;
                                   }
               }
   return lev[T]!=-1;
 }
 int pos[SZ];
 int dfs(int vr , int how=1000000000){
   if(vr==T || !how)return how;
   for(;pos[vr]<sz(fo[vr]);++pos[vr]){
    edge U = E[fo[vr][pos[vr]]];
    if(lev[U.f]+1 == lev[U.t] && U.cap>U.fl){
     int push = dfs(U.t , min(how , U.rc()));
     if(push){
      E[ fo[vr][pos[vr]] ].fl += push;
      E[ fo[vr][pos[vr]]^1 ].fl -= push;
      return push;
             }
                                            }
                                     }
   return 0;
 }
 int max_flow(){
   int how=0 , tmp;
   while(bfs()){
    memset(pos , 0 , N*sizeof(int));
    while(tmp=dfs(F))how += tmp;
               }
   return how;
 }
 // Solution
 int W , H , B;
 int id[110][510];
 int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
 void doit(int CASE = 0){
   scanf("%d%d%d" , &W , &H , &B);
   for(int i=0;i<W;++i)
    for(int j=0;j<H;++j)
     id[i][j] = 0;
   for(int i=0;i<B;++i){
    int xf , yf , xt , yt;
    scanf("%d%d%d%d" , &xf , &yf , &xt , &yt);
    for(int x=xf;x<=xt;++x)
     for(int y=yf;y<=yt;++y)
      id[x][y] = -1;
                       }
   N = 0;
   for(int i=0;i<W;++i)
    for(int j=0;j<H;++j)
     if(id[i][j] >= 0)
      id[i][j] = N,
      N += 2;
   for(int i=0;i<N;i += 2)
    add_edge(i , i+1 , 1);
   N += 2;
   F = N-2 , T = N-1;
   for(int i=0;i<W;++i)
    if(id[i][0] >= 0)
     add_edge(F , id[i][0] , 1);
   for(int i=0;i<W;++i)
    if(id[i][H-1] >= 0)
     add_edge(id[i][H-1] + 1 , T , 1);
   for(int i=0;i<W;++i)
    for(int j=0;j<H;++j){
     if(id[i][j] < 0) continue;
     for(int p=0;p<4;++p){
      int x = i + d[p][0];
      int y = j + d[p][1];
      if(x < 0 || x >= W || y < 0 || y >= H)
       continue;
      if(id[x][y] < 0) continue;
      add_edge(id[i][j] + 1 , id[x][y] , 1);
                         }
                        }
   int out = max_flow();
   printf("Case #%d: %d\n" , CASE , out);
   //////////////////
   flush();
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i)
    doit(i);
   return 0;
 }
