#include <iostream>
 #include <sstream>
 #include <string>
 #include <algorithm>
 #include <vector>
 #include <stack>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <cassert>
 
 using namespace std;
 
 #define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
 #define REP(i,n) FOR(i,0,n)
 #define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
 
 template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
 inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }
 
 typedef long long ll;
 const int INF = 100000000;
 const double EPS = 1e-8;
 const int MOD = 1000000007;
 int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
 int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
 
 // Wrong
 /*
 ll get_y(ll N, ll P){
   P--;
   if((1LL << N) - 1 == P) return (1LL << N) - 1;
   ll sum = 0;
   for(int x = 0; x <= N; x++){
     assert(x < N);
     sum += (1LL << (N - (x + 1)));
     if(P < sum) return x;
   }
   return -1;
 }
 */
 
 ll worst(ll N, ll x){
   ll rank = 0;
   ll cur = x;
   REP(i, N){
     if(cur <= 0) return rank;
     rank += 1LL << (N - 1 - i);
     cur = (cur - 1) / 2;
   }
   return (1LL << N) - 1;
 }
 
 ll best(ll N, ll x){
   ll rank = 0;
   ll cur = (1LL << N) - (x + 1);
   REP(i, N){
     if(cur <= 0){
       rank += 1LL << (N - 1 - i);
     }
     cur = (cur - 1) / 2;
   }
   return rank;
 }
 
 ll get_y(ll N, ll P){
   P--;
   ll lb = 0, ub = 1LL << N;
   while(ub - lb > 1){
     ll mid = (ub + lb) / 2;
     ll rank = worst(N, mid);
     if(rank > P){
       ub = mid;
     }else{
       lb = mid;
     }
   }
   return lb;
 }
 ll get_z(ll N, ll P){
   P--;
   ll lb = 0, ub = 1LL << N;
   while(ub - lb > 1){
     ll mid = (ub + lb) / 2;
     ll rank = best(N, mid);
     if(rank > P){
       ub = mid;
     }else{
       lb = mid;
     }
   }
   return lb;
 }
 
 int main(){
   int T;
   cin >> T;
   REP(CASENUM, T){
     printf("Case #%d: ", CASENUM + 1);
     ll N;
     ll P;
     cin >> N >> P;
     cout << get_y(N, P) << " " << get_z(N, P) << endl;
   }
   return 0;
 }
