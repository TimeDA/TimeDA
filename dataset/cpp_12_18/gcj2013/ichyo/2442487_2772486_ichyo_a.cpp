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
 const ll MOD = 1000002013;
 int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
 int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
 typedef pair<int, int> P;
 ll f(ll n){ return n * (n - 1) / 2;}
 
 int main(){
   int T;
   cin >> T;
   REP(CASENUM, T){
     printf("Case #%d: ", CASENUM + 1);
     int N, M;
     cin >> N >> M;
     //int B[1000], E[1000], P[1000];
     //REP(i, M) cin >> B[i] >> E[i] >> P[i];
     vector<P> vp;
     REP(i, M){
       int b, e, p;
       cin >> b >> e >> p;
       b--; e--;
       REP(j, p){
         vp.push_back(P(b, e));
       }
     }
     sort(vp.begin(), vp.end());
     ll ans = 0;
     for(int i = 0; i < vp.size(); i++){
       for(int j = i + 1; j < vp.size(); j++){
         if(vp[j].first <= vp[i].second && vp[i].second < vp[j].second){
           ll dif = f(vp[j].second - vp[i].first) + f(vp[i].second - vp[j].first) - f(vp[i].second - vp[i].first) - f(vp[j].second - vp[j].first);
           ans += dif;
           ans %= MOD;
           swap(vp[i].second, vp[j].second);
         }
       }
       sort(vp.begin() + i + 1, vp.end());
     }
     cout << ans << endl;
   }
   return 0;
 }
