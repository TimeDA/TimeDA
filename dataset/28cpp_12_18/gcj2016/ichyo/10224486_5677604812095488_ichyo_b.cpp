// Template {{{
 #include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 using namespace std;
 typedef long long LL;
 
 #ifdef LOCAL
 #include "contest.h"
 #else
 #define dump(x) 
 #endif
 
 const int dx[4] = {1, 0, -1, 0};
 const int dy[4] = {0, 1, 0, -1};
 inline bool valid(int x, int w) { return 0 <= x && x < w; }
 
 void iostream_init() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.setf(ios::fixed);
     cout.precision(12);
 }
 //}}}
 
 void solve() {
     int N, K;
     cin >> N >> K;
     vector<double> P(N);
     REP(i, N) {
         cin >> P[i];
     }
     double ans = 0;
     REP(s, 1 << N) if(__builtin_popcount(s) == K) {
         vector<double> dp(N+1);
         dp[0] = 1.0;
         REP(i, N) if(s >> i & 1) {
             vector<double> ndp(N + 1);
             REP(k, N+1) {
                 ndp[k] = dp[k] * (1 - P[i]) + (k - 1 >= 0 ? dp[k-1] * P[i] : 0);
             }
             dp.swap(ndp);
         }
         if(ans < dp[K/2]) {
             ans = dp[K/2];
         }
     }
     cout << ans << endl;
 }
 
 int main(){
     iostream_init();
     int T;
     cin >> T;
     REP(casenum, T) {
         cout << "Case #" << casenum + 1 << ": ";
         solve();
     }
 
     return 0;
 }
 
