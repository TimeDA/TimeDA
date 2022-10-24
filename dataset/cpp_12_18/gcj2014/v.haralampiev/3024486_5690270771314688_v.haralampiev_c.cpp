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
 #include <cassert>
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
 #define BITS(a) __builtin_popcount(a)
 #define INF 1000000000
 int dp[20][1<<16];
 void doit(int CASE = 1){
   map<int , int> id;
   int N;
   cin>>N;
   vector<string> type(N);
   vi per(N);
   for(int i=0;i<N;++i){
    cin>>type[i]>>per[i];
    if(per[i] == 0) per[i] = -1;
    else id[per[i]] = 0;
                       }
   int idx = 0;
   for(map<int,int>::iterator it = id.begin();
       it != id.end();++it) it->se = idx++;
   int UP = 15;
   for(int i=0;i<N;++i)
    if(per[i] != -1)
     per[i] = id[per[i]];
   for(int i=0;i<=N;++i)
    for(int msk=0;msk<(1<<UP);++msk)
     dp[i][msk] = 0;
   for(int i=0;i<(1<<UP);++i)
    dp[0][i] = 1;
   for(int i=0;i<N;++i){
    int ni = i+1;
    char todo = type[i][0];
    int on = per[i];
    for(int p=0;p<UP;++p){
     if(on != -1 && on != p) continue;
     for(int msk=0;msk<(1<<UP);++msk){
      if(!dp[i][msk]) continue;
      if(todo == 'E' && !(msk & (1<<p)))
       dp[ni][msk | (1<<p)] = 1;
      if(todo == 'L' && (msk & (1<<p)))
       dp[ni][msk ^ (1<<p)] = 1;
                                     }
                         }
                       }
   int ANS = INF;
   for(int i=0;i<(1<<UP);++i)
    if(dp[N][i]) relaxMin(ANS , BITS(i));
   if(ANS >= INF)
    printf("Case #%d: CRIME TIME\n" , CASE);
   else
    printf("Case #%d: %d\n" , CASE , ANS);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=0;i<Q;++i)
    doit(i+1);
   return 0;
 }
