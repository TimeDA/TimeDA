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
 
 int HD, AD, HK, AK, B, D;
 
 int simulate(int dt, int bt) {
     int hd = HD;
     int ad = AD;
     int hk = HK;
     int ak = AK;
     auto attack = [&]{
         hk -= ad;
     };
     auto damage = [&]{
         if(hk > 0) { hd -= ak; }
     };
     auto debuff = [&]{
         dt--;
         ak = max(ak-D, 0);
     };
     auto buff = [&]{
         bt--;
         ad = ad + B;
     };
     auto heal = [&]{
         hd = HD;
     };
     for(int turn = 0; turn < 100000; turn++) {
         assert(ak >= 0);
         assert(ad >= 0);
         if(hd <= 0) {
             assert(hk > 0);
             return INT_MAX;
         } if(hk <= 0) {
             return turn;
         } else if(turn > 100 && HD - ak - ak <= 0) {
             return INT_MAX;
         } else if(hk - ad <= 0) {
             attack();
         } else if(dt > 0 && hd - max(ak-D, 0) > 0) {
             debuff();
         } else if(hd - ak <= 0) {
             heal();
         } else if(bt > 0) {
             buff();
         } else {
             attack();
         }
         damage();
     }
     assert(false);
 }
 
 void solve() {
     cin >> HD >> AD >> HK >> AK >> B >> D;
     int ans = INT_MAX;
     for(int bt = 0; bt <= 100; bt++) {
         for(int dt = 0; dt <= 100; dt++) {
             ans = min(ans, simulate(bt, dt));
         }
     }
     if(ans == INT_MAX) {
         cout << "IMPOSSIBLE" << endl;
     } else {
         cout << ans << endl;
     }
 }
 
 int main(){
     iostream_init();
     int TESTCASE;
     cin >> TESTCASE;
     for(int test = 1; test <= TESTCASE; test++) {
         cout << "Case #" << test << ": ";
         solve();
     }
     return 0;
 }
 
