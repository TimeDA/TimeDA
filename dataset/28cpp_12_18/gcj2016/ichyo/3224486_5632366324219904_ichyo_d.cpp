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
     int N, L;
     cin >> N >> L;
     vector<string> good(N);
     REP(i, N) {
         cin >> good[i];
     }
     string bad;
     cin >> bad;
     bool ng = false;
     REP(i, N) if(good[i] == bad) ng = true;
     int idx = -1;
     string A = "";
     REP(i, L) A += "0?";
     string B(L-1, '1');
     if(L == 1) B = "0";
     if(!ng) {
         cout << A << " " << B << endl;
     } else {
         cout << "IMPOSSIBLE" << endl;
     }
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
 
