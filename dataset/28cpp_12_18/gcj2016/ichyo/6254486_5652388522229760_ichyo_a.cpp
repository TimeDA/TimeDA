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
     int N;
     cin >> N;
     if(N == 0) {
         cout << "INSOMNIA" << endl;
         return;
     }
     int cur = N;
     set<int> st;
     while(true) {
         string s = to_string(cur);
         for(char c : s) {
             int x = c + '0';
             st.insert(x);
         }
         if(st.size() == 10) break;
         cur += N;
     }
     cout << cur << endl;
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
 
