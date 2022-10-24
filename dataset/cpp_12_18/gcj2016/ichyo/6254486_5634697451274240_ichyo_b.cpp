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
     vector<char> v;
     v.push_back(s[0]);
     for(int i = 1; i < s.size(); i++) {
         if(s[i] != v.back()) {
             v.push_back(s[i]);
         }
     }
     cout <<  v.size() - 1 + (v.back() == '+' ? 0 : 1) << endl;
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
 
