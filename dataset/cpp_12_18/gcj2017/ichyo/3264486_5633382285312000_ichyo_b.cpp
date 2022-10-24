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
     string t;
     bool nine = false;
     for(int i = 0; i < s.size(); i++) {
         if(nine) {
             t += '9';
         } else if(i + 1 < s.size() && s[i] > s[i+1]) {
             t += (char)(s[i] - 1);
             int j;
             for(j = i; j > 0; j--) {
                 if(t[j-1] > t[j]) {
                     t[j-1] = (char)(t[j-1] - 1);
                 } else {
                     break;
                 }
             }
             for(int k = j+1; k <= i; k++) {
                 t[k] = '9';
             }
             nine = true;
         } else {
             t += s[i];
         }
     }
     int zeros = 0;
     while(zeros < t.size() && t[zeros] == '0') zeros++;
     cout << t.substr(zeros) << endl;
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
 
