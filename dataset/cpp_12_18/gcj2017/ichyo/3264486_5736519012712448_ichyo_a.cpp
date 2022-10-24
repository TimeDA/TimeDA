// Template {{{
 #include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 using namespace std;
 typedef long long LL;
 
 #ifdef LOCAL
 #include "contest.h"
 #else
 #define error(args...) 
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
     string s;
     cin >> s;
     int K;
     cin >> K;
     vector<int> state;
     REP(i, s.size()) {
         state.push_back(s[i] == '+' ? 1 : 0);
     }
     int n = state.size();
     int ans = 0;
     REP(i, n-K+1) {
         if(state[i] == 0) {
             ans++;
             REP(j, K) {
                 state[i+j] ^= 1;
             }
         }
     }
     int sum = 0; REP(i, n) sum += state[i];
     if(sum == n) {
         cout << ans << endl;
     } else {
         cout << "IMPOSSIBLE" << endl;
     }
 }
 
 int main(){
     iostream_init();
     int TESTCASE;
     cin >> TESTCASE;
     for(int testcase = 1; testcase <= TESTCASE; testcase++) {
         cout << "Case #" << testcase << ": ";
         solve();
     }
     return 0;
 }
 
