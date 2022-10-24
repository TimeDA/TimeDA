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
     string s;
     cin >> s;
     int rest = s.size() / 2;
     stack<char> stk;
     int ans = 0;
     REP(i, s.size()) {
         if((stk.size() == 0 || stk.top() != s[i]) && rest > 0) {
             rest--;
             stk.push(s[i]);
         } else {
             char c = stk.top();
             stk.pop();
             if(c != s[i]) {
                 ans += 5;
             } else {
                 ans += 10;
             }
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
 
