#include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <vector>
 #include <deque>
 #include <bitset>
 #include <set>
 #include <map>
 #include <utility>
 #include <string>
 #include <cstring>
 #include <queue>
 #include <algorithm>
 #include <cmath>
 using namespace std;
 #define fi first
 #define se second
 #define pb(a) push_back(a)
 #define sz(a) ((int)(a).size())
 #define all(a) a.begin() , a.end()
 #define EPS 1E-9
 #define x1 x111
 #define y1 y111
 typedef long long ll;
 typedef unsigned long long ull;
 typedef long double ld;
 typedef pair<int,int> pii;
 // real solution
 int H , N , M;
 int C[110][110] , F[110][110];
 int mv[4][2]={{-1,0} , {0,1} , {1,0} , {0,-1}};
 bool is_valid(pii a){
   return (a.fi>=0 && a.se>=0 && a.fi<N && a.se<M);
 }
 bool can_go(int tim , pii from , pii to){
   if(!is_valid(from) || !is_valid(to))return false;
   int x1=from.fi,y1=from.se,x2=to.fi,y2=to.se;
   if(C[x1][y1] - F[x1][y1]<50 || C[x2][y2]-F[x2][y2]<50)return false;
   if(C[x2][y2] - max( tim , max( F[x1][y1] , F[x2][y2] ) ) < 50)return false;
   if(C[x1][y1] - F[x2][y2] < 50)return false;
   return true;
 }
 pii after(int beg , pii from , pii to){
   int lo = 0 , hi=beg , mid;
   if(!can_go(0 , from , to))return pii(-1,-1);
   for(;;){
    if(lo+1>=hi){
     if(can_go(hi , from , to))mid=hi;
     else mid=lo;
     break;
                }
    mid=(lo+hi)/2;
    if(can_go(mid , from , to))lo=mid;
    else hi=mid;
          }
   if(mid - F[from.fi][from.se] >= 20)return pii(mid,1);
   else return pii(mid , 10);
 }
 int SP[110][110];
 struct compare{
   bool operator()(const pii& f,const pii& s){
    return (SP[f.fi][f.se] != SP[s.fi][s.se])?SP[f.fi][f.se] > SP[s.fi][s.se]:f<s;
                                             }
 };
 set<pii , compare> U;
 int djikstra(){
   U.clear();
   for(int i=0;i<N;++i)
    for(int j=0;j<M;++j)SP[i][j]=-1000000;
   SP[0][0]=H;  U.insert( pii(0,0) );
   while(!U.empty()){
    pii C=*U.begin(); U.erase(C);
    for(int i=0;i<4;++i){
     pii neo(C.fi + mv[i][0] , C.se + mv[i][1]);
     pii ttt=after( max(0 , SP[C.fi][C.se]) , C , neo );
     if(ttt.se == -1)continue;
     if(SP[C.fi][C.se] == H && ttt.fi == H){
      int CT=H;
      if(CT > SP[neo.fi][neo.se]){
       U.erase(neo);
       SP[neo.fi][neo.se] = CT;
       U.insert(neo);
                                 }
                                           }
     else{
      int CT=min(ttt.fi , SP[C.fi][C.se]) - ttt.se*10;
      if(CT > SP[neo.fi][neo.se]){
       U.erase(neo);
       SP[neo.fi][neo.se] = CT;
       U.insert(neo);
                                 }
         }
                        }
                    }
   return H-SP[N-1][M-1];
 }
 void doit(int CASE){
   scanf("%d%d%d",&H , &N , &M);
   for(int i=0;i<N;++i)
    for(int j=0;j<M;++j)
     scanf("%d",&C[i][j]);
   for(int i=0;i<N;++i)
    for(int j=0;j<M;++j)
     scanf("%d",&F[i][j]);
   printf("Case #%d: %.9lf\n" , CASE , djikstra()/10.0);
 }
 int main(){
   int Q; scanf("%d",&Q);
   for(int i=1;i<=Q;++i)doit(i);
   //system("pause");
   return 0;
 }
