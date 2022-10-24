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
 
 string grid[55];
 int R, C;
 
 bool is_shooter(char c) {
     return c == '-' || c == '|';
 }
 
 void solve() {
     cin >> R >> C;
     REP(y, R) cin >> grid[y];
     int dp[55][1<<5] = {};
     int back[55][1<<5] = {};
 
     REP(y, R) REP(x, C) if(grid[y][x] == '/' || grid[y][x] == '\\') {
         cout << "UNKNOWN" << endl;
         return;
     }
 
     dp[0][0] = 1;
     REP(y, R) REP(x, C) if(is_shooter(grid[y][x])) grid[y][x] = '|';
 
     REP(x, C) {
         REP(s, 1<<R) {
             if(!dp[x][s]) continue;
 
             REP(y, R) {
                 if((s >> y & 1) && is_shooter(grid[y][x])) {
                     continue;
                 }
             }
 
             REP(t, 1<<R) {
                 bool ng = false;
                 REP(y, R) if(!(s >> y & 1) && (t >> y & 1) && !is_shooter(grid[y][x])) ng = true;
                 REP(y, R) if((s >> y & 1) && !(t >> y & 1) && grid[y][x] != '#') ng = true;
                 if(ng) continue;
                 bool d[5] = {};
                 REP(y, R) if(!(t >> y & 1) && is_shooter(grid[y][x])) {
                     for(int cy = y-1; cy >= 0; cy--) {
                         if(is_shooter(grid[cy][x])) {
                             ng = true;
                             continue;
                         } else if(grid[cy][x] == '#') {
                             break;
                         } else {
                             d[cy] = true;
                         }
                     }
                     for(int cy = y+1; cy < R; cy++) {
                         if(is_shooter(grid[cy][x])) {
                             ng = true;
                             continue;
                         } else if(grid[cy][x] == '#') {
                             break;
                         } else {
                             d[cy] = true;
                         }
                     }
                 }
                 REP(y, R) if((t >> y & 1) && is_shooter(grid[y][x])) {
                     for(int cx = x-1; cx >= 0; cx--) {
                         if(is_shooter(grid[y][cx])) {
                             ng = true;
                             continue;
                         } else if(grid[y][cx] == '#') {
                             break;
                         }
                     }
                 }
                 REP(y, R) if(grid[y][x] == '.' && !d[y]) ng = true;
                 if(!ng) {
                     dp[x+1][t] = true;
                     back[x+1][t] = s;
                 }
             }
         }
     }
     int lt = -1;
     REP(t, 1<<R) if(dp[C][t]) lt = t;
     if(lt == -1) {
         cout << "IMPOSSIBLE" << endl;
     } else {
         cout << "POSSIBLE" << endl;
         for(int x = C; x > 0; x--) {
             REP(y, R) if(lt >> y & 1 && is_shooter(grid[y][x-1])) {
                 grid[y][x-1] = '-';
             }
             lt = back[x][lt];
         }
         REP(y, R) {
             cout << grid[y] << endl;
         }
     }
 }
 
 int main(){
     iostream_init();
     int T;
     cin >> T;
     for(int testcase = 1; testcase <= T; testcase++) {
         cout << "Case #" << testcase << ": ";
         solve();
     }
 
     return 0;
 }
 
