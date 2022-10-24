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
 
 class range {
     struct Iterator {
         int val, inc;
         int operator*() {return val;}
         bool operator!=(Iterator& rhs) {return val < rhs.val;}
         void operator++() {val += inc;}
     };
     Iterator i, n;
     public:
     range(int e) : i({0, 1}), n({e, 1}) {}
     range(int b, int e) : i({b, 1}), n({e, 1}) {}
     range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
     Iterator& begin() {return i;}
     Iterator& end() {return n;}
 };
 
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
 int get(char c) {
     if(c == '^') return 0;
     if(c == '>') return 1;
     if(c == 'v') return 2;
     if(c == '<') return 3;
     assert(false);
 }
 void solve() {
     int H, W;
     cin >> H >> W;
     vector<string> grid(H);
     REP(y, H) {
         cin >> grid[y];
     }
     bool need[110][110] = {};
     bool ngH[110][110] = {};
     bool ngW[110][110] = {};
     REP(y, H) {
         vector<int> idx;
         REP(x, W) {
             if(grid[y][x] != '.') idx.push_back(x);
         }
         if(idx.size() == 0) {
         } else if(idx.size() == 1) {
             int x = idx.front();
             ngH[y][x] = true;
             int g = get(grid[y][x]);
             if(g % 2 == 1) {
                 need[y][x] = true;
             }
         } else {
             int x1 = idx.front();
             int x2 = idx.back();
             if(get(grid[y][x1]) == 3) {
                 need[y][x1] = true;
             }
             if(get(grid[y][x2]) == 1) {
                 need[y][x2] = true;
             }
         }
     }
     REP(x, W) {
         vector<int> idx;
         REP(y, H) {
             if(grid[y][x] != '.') idx.push_back(y);
         }
         if(idx.size() == 0) {
         } else if(idx.size() == 1) {
             int y = idx.front();
             ngW[y][x] = true;
             int g = get(grid[y][x]);
             if(g % 2 == 0) {
                 need[y][x] = true;
             }
         } else {
             int y1 = idx.front();
             int y2 = idx.back();
             if(get(grid[y1][x]) == 0) {
                 need[y1][x] = true;
             }
             if(get(grid[y2][x]) == 2) {
                 need[y2][x] = true;
             }
         }
     }
     REP(y, H) REP(x, W) if(ngH[y][x] && ngW[y][x]) {
         cout << "IMPOSSIBLE" << endl;
         return;
     }
     int ans = 0;
     REP(y, H) REP(x, W) if(need[y][x]) {
         ans ++;
     }
     cout << ans << endl;
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
 
 /* vim:set foldmethod=marker: */
 
