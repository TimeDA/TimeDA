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
 int N , M , T[110][110];
 bool used[110][110];
 struct compare{
   bool operator()(const pii& f , const pii& s)const{
    return T[f.fi][f.se] != T[s.fi][s.se] ?
           T[f.fi][f.se] < T[s.fi][s.se]  :
           f < s;
                                                    }
 };
 set<pii , compare> U;
 void doit(int CASE){
   scanf("%d%d" , &N , &M);
   for(int i=0;i<N;++i)
    for(int j=0;j<M;++j)
     scanf("%d" , &T[i][j]),
     used[i][j] = false,
     U.insert(mp(i,j));
   bool OK = true;
   while(!U.empty()){
    pii c = *U.begin();
    U.erase(c);
    int X = c.fi , Y = c.se;
    bool hor = true , ver = true;
    for(int i=0;i<N;++i)
     if(!used[i][Y] && T[i][Y] != T[X][Y])ver = false;
    for(int j=0;j<M;++j)
     if(!used[X][j] && T[X][j] != T[X][Y])hor = false;
    if(!hor && !ver){
     OK = false;
     break;
                    }
    if(hor)
     for(int j=0;j<M;++j)
      used[X][j] = true,
      U.erase(mp(X , j));
    if(ver)
     for(int i=0;i<N;++i)
      used[i][Y] = true,
      U.erase(mp(i , Y));
                    }
   U.clear();
   if(OK)printf("Case #%d: YES\n" , CASE);
   else printf("Case #%d: NO\n" , CASE);
 }
 int main(){
   int Q , CASE = 1; scanf("%d" , &Q);
   while(Q--)
    doit(CASE++);
   return 0;
 }
